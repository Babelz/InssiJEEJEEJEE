#pragma once
#include "GameObject.h"
#include "FiniteStateMachine.h"
#include "CooldownTimer.h"

class Monster : public GameObject
{
public:
	Monster();

	virtual void update(sf::Time &tpf);
	virtual void draw(sf::RenderWindow &window);

	~Monster();
};

