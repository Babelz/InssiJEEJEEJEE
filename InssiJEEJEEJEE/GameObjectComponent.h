#pragma once

#include <SFML\Graphics.hpp>
class GameObject;
#include "GameObject.h"
class GameObjectComponent
{
private:
	GameObject* owner;
public:
	GameObjectComponent(GameObject* owner);
	~GameObjectComponent();

	GameObject* getOwner() {
		return owner;
	}

	virtual void update(sf::Time& tpf) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
};

