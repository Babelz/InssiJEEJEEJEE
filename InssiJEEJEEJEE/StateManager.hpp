#pragma once
#include <vector>
#include "State.hpp"

class StateManager
{
private:
	std::vector<State*> states;
	std::vector<State*> activeStates;
public:
	int add(State &state);
	void change(unsigned int i);
	void push(unsigned int i);
	void pop();
	void update(sf::Time &time);
	void draw(sf::RenderWindow &window);
	
	int pollEvent(sf::Event &event);
};