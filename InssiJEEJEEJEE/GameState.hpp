#pragma once
#include <SFML/Graphics.hpp>

class GameState
{
public:
	virtual void activate() = 0;
	virtual void draw(sf::RenderWindow &window) = 0;
	virtual void update(sf::Time &time) = 0;
	virtual int pollEvent(sf::Event &event) = 0;
};