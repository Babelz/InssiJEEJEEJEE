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
		update(elapsed);
		draw(window);
	}
}

Game::~Game() {
}
