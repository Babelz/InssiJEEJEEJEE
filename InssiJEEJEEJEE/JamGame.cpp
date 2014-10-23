#include "JamGame.h"


JamGame::JamGame(int width, int height) : Game(width, height)
{
}


JamGame::~JamGame()
{
}

void JamGame::update(sf::Time &tpf) {
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}
	screen.update(tpf);
}

void JamGame::draw(sf::RenderWindow &window) {
	screen.draw(window);
}