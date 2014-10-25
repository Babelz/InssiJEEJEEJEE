#include "GameOverScreen.h"
#include "Game.h"

GameOverScreen::GameOverScreen(Game *game) : GameState(game)
{
}


GameOverScreen::~GameOverScreen()
{
}

void GameOverScreen::activate()
{
}

void GameOverScreen::draw(sf::RenderWindow &window)
{
}

void GameOverScreen::update(sf::Time &time)
{
}

int GameOverScreen::pollEvent(sf::Event &event)
{
	if (sf::Keyboard::isKeyPressed)
	{
		getGame()->getStateManager()->change(0);
	}

	return 0;
}
