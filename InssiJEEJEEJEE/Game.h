#pragma once

#include <SFML\Graphics.hpp>
#include "StateManager.hpp"
class Game
{
protected:
	sf::RenderWindow window;
	StateManager stateManager;
public:
	Game(int width, int height);
	void run();
	virtual void update(sf::Time &tpf) = 0;
	virtual void draw(sf::RenderWindow &win) = 0;
	~Game();

};

