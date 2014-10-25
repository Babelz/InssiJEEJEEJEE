#include "JamGame.h"
#include "MenuScreen.h"

JamGame::JamGame(int width, int height) : Game(width, height)
{
	stateManager.push(new MenuScreen(this));
	window.setMouseCursorVisible(true);
}

void JamGame::update(sf::Time &tpf) {
	sf::Event event;

	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}

		stateManager.pollEvent(event);
	}

	stateManager.update(tpf);
}
void JamGame::draw(sf::RenderWindow &window) {
	stateManager.draw(window);
}

JamGame::~JamGame() {
}