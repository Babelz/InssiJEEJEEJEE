#pragma once

#include <SFML\Graphics.hpp>
#include "World.h"
#include "State.hpp"
class GameplayScreen : public State
{
private:
	World world;
public:
	GameplayScreen();
	~GameplayScreen();
	void update(sf::Time &tpf);
	void draw(sf::RenderWindow& window);
	void activate();
	int pollEvent(sf::Event &event);
};

