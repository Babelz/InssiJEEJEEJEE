#pragma once
#include "GameObjectComponent.h"
class InputMovementComponent : public GameObjectComponent
{
public:
	InputMovementComponent(GameObject* owner);
	~InputMovementComponent();
	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& window);
};

