#pragma once

#include <SFML\Graphics.hpp>

class GameObjectComponent
{
public:
	GameObjectComponent();
	~GameObjectComponent();

	virtual void update(sf::Time& tpf) = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
};

