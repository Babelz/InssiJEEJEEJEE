#pragma once
#include "GameState.hpp"

class TestiState : public GameState
{
private:
	sf::CircleShape *shape;
public:
	TestiState();
	void activate();
	void update(sf::Time &time);
	void draw(sf::RenderWindow &window);
	int pollEvent(sf::Event &event);
};
