#include "GameplayScreen.h"


GameplayScreen::GameplayScreen()
{

}


GameplayScreen::~GameplayScreen()
{
}

void GameplayScreen::update(sf::Time& tpf) {
	world.update(tpf);
}

void GameplayScreen::draw(sf::RenderWindow& window) {
	world.draw(window);
}
