#pragma once

#include <SFML\Graphics.hpp>
#include "StateManager.hpp"
#include "soundManager.h"
#include <functional>
class Game
{
protected:
	sf::RenderWindow window;
	StateManager stateManager;
	soundManager sound_manager;
	bool gameRunning;
	std::vector<std::function<void(void)>> pendingActions;
public:
	Game(int width, int height);
	void run();
	inline StateManager* getStateManager() { return &stateManager; }
	inline soundManager* getSoundManager() { return &sound_manager; }
	inline void setGameRunning(bool b) { gameRunning = b; }
	virtual void update(sf::Time &tpf) = 0;
	virtual void draw(sf::RenderWindow &win) = 0;
	void doNextUpdate(std::function< void(void)> action);
	sf::RenderWindow& getWindow() {
		return window;
	}
	~Game();

};

