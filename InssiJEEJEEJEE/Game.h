#pragma once

#include <SFML\Graphics.hpp>
#include "StateManager.hpp"
class Game
{
protected:
	sf::RenderWindow window;
	StateManager stateManager;
	bool gameRunning;
public:
	Game(int width, int height);
	void run();
	inline StateManager* getStateManager() { return &stateManager; };
	inline void setGameRunning(bool b) { gameRunning = b; }
	virtual void update(sf::Time &tpf) = 0;
	virtual void draw(sf::RenderWindow &win) = 0;

	sf::RenderWindow& getWindow() {
		return window;
	}
	~Game();

};

