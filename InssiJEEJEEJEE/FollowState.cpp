#include "FollowState.h"
#include "InssiMath.h"

FollowState::FollowState(GameObject* owner, FiniteStateMachine* stateMachine, World* world) :
MachineState(owner, stateMachine) {
	this->world = world;

	b2Vec2 playerPos = Convert::box2dToWorld(world->getPlayer()->getPosition());
	sf::Vector2f pos(playerPos.x, playerPos.y);

	b2Vec2 b2v = Convert::box2dToWorld(getOwner()->getPosition());
	sf::Vector2f position(b2v.x, b2v.y);

	pathFinder = new AStarPathfinder(world->getActiveMap()->getAStarGrid());

	world->getActiveMap()->getAStarGrid()->setStart(position);
	world->getActiveMap()->getAStarGrid()->setGoal(pos);
	
	//stateMachine->getTimers()->addTimer("FindPath", 5000);

	currentPath = pathFinder->findPath();
	world->getActiveMap()->getAStarGrid()->resetNodes();

	currentPath.erase(std::remove(currentPath.begin(), currentPath.end(), currentDestination), currentPath.end());
	currentDestination = currentPath[0];

	updateDirection();
}

float FollowState::roundPosX() {
	b2Vec2 b2v = Convert::box2dToWorld(getOwner()->getPosition());
	sf::Vector2f position(b2v.x, b2v.y);

	float min = std::min(position.x, currentDestination.x);
	float max = std::max(position.x, currentDestination.x);

	float rX = fmod(max, min) + max;

	return rX - fmod(rX, min);
}
float FollowState::roundPosY() {
	b2Vec2 b2v = Convert::box2dToWorld(getOwner()->getPosition());
	sf::Vector2f position(b2v.x, b2v.y);

	float min = std::min(position.y, currentDestination.y);
	float max = std::max(position.y, currentDestination.y);

	float rY = fmod(max, min) + max;

	return rY - fmod(rY, min);
}
void FollowState::updateDirection() {
	//float x = roundPosX();
	//float y = roundPosY();

	b2Vec2 b2v = Convert::box2dToWorld(getOwner()->getPosition());
	sf::Vector2f position(b2v.x, b2v.y);

	float x = (int)position.x;
	float y = (int)position.y;

	float dirX = 0.0f;
	float dirY = 0.0f;

	if (x < currentDestination.x) {
		while (fmod(x, 64.f) > 0) {
			x = x - 1.f;
		}
	}

	if (y < currentDestination.y) {
		while (fmod(y, 64.f) > 0) {
			y = y - 1.f;
		}
	}

	while (fmod(y, 64.f) > 0) {
		y = y + 1.f;
	}

	while (fmod(x, 64.f) > 0) {
		x = x + 1.f;
	}

	if (x != currentDestination.x) {
		if (x < currentDestination.x) {
			dirX = 1.0f;
			currentDirection = sf::Vector2f(dirX, dirY);
		}
		else if (x > currentDestination.x) {
			dirX = -1.0f;
			currentDirection = sf::Vector2f(dirX, dirY);
		}
	}

	
	if (y != currentDestination.y) {
		if (y <= currentDestination.y) {
			dirY = 1.0f;
		}
		else if (y >= currentDestination.y) {
			dirY = -1.0f;
		}
	}

	currentDirection = sf::Vector2f(dirX, dirY);
}
bool FollowState::atDest() {
	b2Vec2 b2v = Convert::box2dToWorld(getOwner()->getPosition());
	sf::Vector2f position(b2v.x, b2v.y);

	/*float rX = roundPosX();
	float rY = roundPosY();

	if (currentDirection.x != 0.f) {
		if (fmod(rX, currentDestination.x) < 64.0f) {
			return true;
		} else {
			float min = std::min(rX, currentDestination.x);
			float max = std::max(rX, currentDestination.x);

			float mX = fmod(max, min);

			if (rX > currentDestination.y) {
				return (int)(rX - mX) == (int)currentDestination.x;
			}
			else {
				return (int)rX + (int)mX == (int)currentDestination.x;
			}
		}
	}

	if (currentDirection.y != 0.f) {
		if (fmod(rY, currentDestination.y) < 64.0f) {
			return true;
		}
		else {
			float min = std::min(rY, currentDestination.y);
			float max = std::max(rY, currentDestination.y);

			float mY = fmod(max, min);

			if (rY > currentDestination.y) {
				return (int)(rY - mY) == (int)currentDestination.y;
			} else {
				return (int)rY + (int)mY == (int)currentDestination.y;
			}
		}
	}

	return true;*/

	if (currentDirection.x != 0) {
		if (currentDirection.x == -1) {
			return position.x < currentDestination.x;
		}
		else {
			return position.x > currentDestination.x;
		}
	}

	if (currentDirection.y != 0) {
		if (currentDirection.y == -1) {
			return position.y <= currentDestination.y;
		}
		else {
			return position.y >= currentDestination.y;
		}
	}

	return true;
}

// 14.999
const float velocityMod = 14.f;

void FollowState::update(sf::Time& tpf) {
	b2Vec2 b2v = Convert::box2dToWorld(getOwner()->getPosition());
	sf::Vector2f position(b2v.x, b2v.y);

	if (currentPath.size() == 0 || updatesInSameSpot == 100 /*|| getStateMachine()->getTimers()->expired("FindPath")*/) {
		b2Vec2 playerPos = Convert::box2dToWorld(world->getPlayer()->getPosition());
		sf::Vector2f pos(playerPos.x, playerPos.y);
		
		world->getActiveMap()->getAStarGrid()->setStart(position);
		world->getActiveMap()->getAStarGrid()->setGoal(pos);

		currentPath = pathFinder->findPath();

		world->getActiveMap()->getAStarGrid()->resetNodes();

		//getStateMachine()->getTimers()->resetTimer("FindPath");

		currentPath.erase(std::remove(currentPath.begin(), currentPath.end(), currentDestination), currentPath.end());

		if (currentPath.size() == 0) {
			return;
		}

		last = currentDestination;
		currentDestination = currentPath[0];

		updatesInSameSpot = 0;

		updateDirection();
	}

	if (atDest()) {
		currentPath.erase(std::remove(currentPath.begin(), currentPath.end(), currentDestination), currentPath.end());

		if (currentPath.size() == 0) {
			return;
		}

		last = currentDestination;
		currentDestination = currentPath[0];

		updatesInSameSpot = 0;

		updateDirection();
	}
	else {
		updatesInSameSpot++;
	}

	b2Vec2 velo(currentDirection.x * velocityMod, currentDirection.y * velocityMod);

	getOwner()->body->SetLinearVelocity(velo);
}

FollowState::~FollowState() {

}