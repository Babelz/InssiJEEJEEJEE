#include "JamGame.h"
#include "GameplayScreen.h"
#include "MenuScreen.h"
#include "GameOverScreen.h"

JamGame::JamGame(int width, int height) : Game(width, height)
{
	stateManager.add(new MenuScreen(this));
	stateManager.add(new GameplayScreen(this));
	stateManager.add(new GameOverScreen(this));
	stateManager.change(0);
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