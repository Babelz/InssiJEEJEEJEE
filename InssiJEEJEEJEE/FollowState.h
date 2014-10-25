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
	sf::Vector2f currentDirection;
	sf::Vector2f last;

	int updatesInSameSpot;

	void updateDirection();
	float roundPosX();
	float roundPosY();
	bool atDest();
public:
	FollowState(GameObject* owner, FiniteStateMachine* stateMachine, World* world);

	virtual void update(sf::Time& tpf);

	~FollowState();
};