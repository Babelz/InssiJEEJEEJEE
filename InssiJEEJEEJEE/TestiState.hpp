#pragma once
#include "State.hpp"

class TestiState : public State
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
