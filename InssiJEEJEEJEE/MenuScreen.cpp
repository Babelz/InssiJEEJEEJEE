#include "MenuScreen.h"
#include "Game.h"


MenuScreen::MenuScreen(Game *game) : GameState(game)
{
}

MenuScreen::~MenuScreen()
{
}

void MenuScreen::activate()
{
}

void MenuScreen::draw(sf::RenderWindow &window)
{
}

void MenuScreen::update(sf::Time &time)
{
}

int MenuScreen::pollEvent(sf::Event &event)
{
	if (sf::Keyboard::isKeyPressed)
	{
		getGame()->getStateManager()->change(1);
	}
	return 0;
}
