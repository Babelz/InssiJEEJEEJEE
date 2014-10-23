#include "StateManager.hpp"

int StateManager::add(State &state)
{
	states.push_back(&state);

	return states.size() - 1;
}

void StateManager::push(unsigned int i)
{
	if (i >= 0 && i < states.size())
	{
		activeStates.push_back(states[i]);
		activeStates.back()->activate();
	}	
}

void StateManager::change(unsigned int i)
{
	activeStates.clear();
	push(i);
}

void StateManager::pop()
{
	activeStates.pop_back();
}

void StateManager::draw(sf::RenderWindow &window)
{
	for (unsigned int i = 0; i < activeStates.size(); i++)
	{
		activeStates[i]->draw(window);
	}
}

void StateManager::update(sf::Time &time)
{
	if (activeStates.size() > 0)
		activeStates.back()->update(time);
}

int StateManager::pollEvent(sf::Event &event)
{
	if (activeStates.size() > 0)
		return activeStates.back()->pollEvent(event);

	return 0;
}