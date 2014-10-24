#include "JamGame.h"
#include "GameplayScreen.h"

JamGame::JamGame(int width, int height) : Game(width, height) {
	stateManager.add(new GameplayScreen());
	stateManager.change(0);
}

void JamGame::update(sf::Time &tpf) {
	sf::Event event;

	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}

	stateManager.update(tpf);
}
void JamGame::draw(sf::RenderWindow &window) {
	stateManager.draw(window);
}

JamGame::~JamGame() {
}