#include "FollowState.h"
#include "InssiMath.h"

FollowState::FollowState(GameObject* owner, FiniteStateMachine* stateMachine, World* world) :
MachineState(owner, stateMachine) {
	this->world = world;

	b2Vec2 playerPos = Convert::box2dToWorld(world->getPlayer()->getPosition());
	sf::Vector2f pos(playerPos.x, playerPos.y);

	pathFinder = new AStarPathfinder(world->getActiveMap()->getAStarGrid());
	world->getActiveMap()->getAStarGrid()->setStart(sf::Vector2f(0.f, 0.f));
	world->getActiveMap()->getAStarGrid()->setGoal(pos);

	stateMachine->getTimers()->addTimer("FindPath", 500);
	//stateMachine->getTimers()->addTimer("ChangeDir", 250);

	currentPath = pathFinder->findPath();
	world->getActiveMap()->getAStarGrid()->resetNodes();

	currentPath.erase(std::remove(currentPath.begin(), currentPath.end(), currentDestination), currentPath.end());
	currentDestination = currentPath[0];

	dirHandler.setOffset(sf::Vector2f(.0f, .0f));

	dirHandler.changeDirection(sf::Vector2f(0.f, 0.f), currentDestination);
}

void FollowState::update(sf::Time& tpf) {
	b2Vec2 b2v = Convert::box2dToWorld(getOwner()->getPosition());
	sf::Vector2f position(b2v.x, b2v.y);

	if (currentPath.size() == 0) {
		b2Vec2 playerPos = Convert::box2dToWorld(world->getPlayer()->getPosition());
		sf::Vector2f pPos(playerPos.x, playerPos.y);
		world->getActiveMap()->getAStarGrid()->setGoal(pPos);

		b2Vec2 myPos = Convert::box2dToWorld(getOwner()->getPosition());
		sf::Vector2f mPos(myPos.x, myPos.y);
		world->getActiveMap()->getAStarGrid()->setStart(mPos);

		currentPath = pathFinder->findPath();
		world->getActiveMap()->getAStarGrid()->resetNodes();


		getStateMachine()->getTimers()->resetTimer("FindPath");
		
		if (currentPath.size() == 0) {
			return;
		}

		currentDestination = currentPath[0];

		dirHandler.changeDirection(position, currentDestination);
	}

	if (dirHandler.passedGoal(position)) {
		currentPath.erase(std::remove(currentPath.begin(), currentPath.end(), currentDestination), currentPath.end());
		
		if (currentPath.size() == 0) {
			return;
		}
		
		currentDestination = currentPath[0];

		dirHandler.changeDirection(position, currentDestination);
	}

	sf::Vector2f trans = dirHandler.translate();
	b2Vec2 velo(12.5f * -(trans.x), 12.5f * -(trans.y));

	getOwner()->body->SetLinearVelocity(velo);
}

FollowState::~FollowState() {

}