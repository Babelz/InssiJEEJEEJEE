#pragma once

#include "FiniteStateMachine.h"
#include "World.h"
#include "AStarPathfinder.h"
#include "DirectionHandler.h"

class FollowState : public MachineState
{
private:
	World* world;
	AStarPathfinder* pathFinder;
	std::vector<sf::Vector2f> currentPath;
	sf::Vector2f currentDestination;
	DirectionHandler dirHandler;
public:
	FollowState(GameObject* owner, FiniteStateMachine* stateMachine, World* world);

	virtual void update(sf::Time& tpf);

	~FollowState();
};