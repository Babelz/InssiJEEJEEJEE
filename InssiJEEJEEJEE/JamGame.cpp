#include "JamGame.h"


JamGame::JamGame(int width, int height) : Game(width, height) {
}


JamGame::~JamGame() {
	delete(grid);
	delete(pathfinder);
}

void JamGame::update(sf::Time &tpf) {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
}

void JamGame::draw(sf::RenderWindow &window) {
	window.clear(sf::Color::Black);

	window.display();
}