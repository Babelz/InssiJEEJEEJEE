#include "Game.h"

Game::Game(int width, int height) : 
	window(sf::VideoMode(width, height), "InssiJeeJee"), gameRunning(true) {
	window.setFramerateLimit(60);
	sound_manager.initialiseSound();
}


void Game::run() {
	sf::Clock clock;
	while (window.isOpen() && gameRunning) {
		sf::Time elapsed = clock.restart();
		for (int i = pendingActions.size() - 1; i >= 0; i--) {
			pendingActions[i]();
		}
		pendingActions.clear();
		update(elapsed);
		draw(window);
	}
}

void Game::doNextUpdate(std::function< void(void)> action) {
	pendingActions.push_back(action);
}
Game::~Game() {
}
