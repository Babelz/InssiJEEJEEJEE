#pragma once
#include "GameObjectComponent.h"
class PickUpComponent :
	public GameObjectComponent
{
public:
	PickUpComponent(GameObject* owner);
	~PickUpComponent();
	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& win);
};

