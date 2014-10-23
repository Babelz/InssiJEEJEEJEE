#pragma once

#include <SFML\Graphics.hpp>
#include "World.h"
class GameplayScreen
{
private:
	World world;
public:
	GameplayScreen();
	~GameplayScreen();
	void update(sf::Time &tpf);
	void draw(sf::RenderWindow& window);
};

