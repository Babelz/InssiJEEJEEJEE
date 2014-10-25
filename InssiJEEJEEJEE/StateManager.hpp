#pragma once
#include <vector>
#include "GameState.hpp"

class StateManager
{
private:
	std::vector<GameState*> states;
	std::vector<GameState*> activeStates;
public:
	int add(GameState* state);
	void remove(unsigned int i);
	void change(unsigned int i);
	void push(unsigned int i);
	void pop();
	void update(sf::Time &time);
	void draw(sf::RenderWindow &window);
	
	int pollEvent(sf::Event &event);
};