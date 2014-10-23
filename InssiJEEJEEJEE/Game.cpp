#include "Game.h"


Game::Game(int width, int height) : 
	window(sf::VideoMode(width, height), "InssiJeeJee")
{
	window.setFramerateLimit(60);
}


void Game::run() {
	sf::Clock clock;
	while (window.isOpen()) {
		sf::Time elapsed = clock.restart();
		update(elapsed);
		draw(window);
	}
}

Game::~Game()
{
}
