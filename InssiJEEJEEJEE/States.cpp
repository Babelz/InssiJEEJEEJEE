#include "FiniteStateMachine.h"
#include "World.h"
#include "AStarPathfinder.h"

namespace BasicMonster
{
	class FollowState : public AI::State
	{
	private:
		AStarPathfinder* pathFinder;
		std::vector<sf::Vector2f> currentPath;
		sf::Vector2f currentDestination;
	public:
		FollowState(GameObject* owner, AI::FiniteStateMachine* stateMachine, World* world) :
		State(owner, stateMachine) {
			pathFinder = new AStarPathfinder(world->getActiveMap()->getAStarGrid());
			
			stateMachine->getTimers()->addTimer("FindPath");
			currentPath = pathFinder->findPath();
			currentDestination = currentPath[0];
		}
		virtual void Update(sf::Time& tpf) override {
			int timerValue = getStateMachine()->getTimers()->getTimerValue("FindPath");
			
			if (timerValue > 5000) {
				currentPath = pathFinder->findPath();
			}

			b2Vec2 position = getOwner()->getPosition();

			if (position.x == currentDestination.x && position.y == currentDestination.y) {
				currentPath.erase(std::remove(currentPath.begin(), currentPath.end(), currentDestination), currentPath.end());
				currentDestination = currentPath[0];
			}
		}
	};

	class FindPlayer : public AI::State
	{
		virtual void Update(sf::Time& tpf) override {
		}
	};

	class GotoTemple : public AI::State
	{
		virtual void Update(sf::Time& tpf) override {
		}
	};

	class Attack : public AI::State
	{
		virtual void Update(sf::Time& tpf) override {
		}
	};
}
