#pragma once
#include <vector>
#include "GameState.hpp"

class StateManager
{
private:
	std::vector<GameState*> states;
	std::vector<GameState*> activeStates;
	int newScreen;
public:
	StateManager::StateManager();
	int add(GameState* state);
	void remove(unsigned int i);
	void change(unsigned int i);
	void push(unsigned int i);
	void push(GameState *state);
	void pop();
	void update(sf::Time &time);
	void draw(sf::RenderWindow &window);
	
	int pollEvent(sf::Event &event);
};