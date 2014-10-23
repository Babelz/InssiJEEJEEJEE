#include "TestiState.hpp"

TestiState::TestiState()
{
	shape = new sf::CircleShape(100.0f);
	shape->setFillColor(sf::Color::Green);
}

void TestiState::activate()
{
}

void TestiState::draw(sf::RenderWindow &window)
{
	window.draw(*shape);
}

void TestiState::update(sf::Time &time)
{
}

int TestiState::pollEvent(sf::Event &event)
{
	if (event.type == sf::Event::Closed)
		return 0;

	return 1;
}