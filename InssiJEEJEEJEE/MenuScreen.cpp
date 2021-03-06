#include "MenuScreen.h"
#include "Game.h"
#include "soundManager.h"
#include "GameplayScreen.h"


MenuScreen::MenuScreen(Game *game) : GameState(game)
{
	if (!menuTexture.loadFromFile("menu.png"))
		return;

	shape = sf::RectangleShape(sf::Vector2f(1280.f, 720.f));
	shape.setTexture(&menuTexture);
	soundManager::getSound().playMenuMusic();
}

MenuScreen::~MenuScreen()
{
}

void MenuScreen::activate()
{
}

void MenuScreen::draw(sf::RenderWindow &window)
{
	window.draw(shape);
	window.display();
}

void MenuScreen::update(sf::Time &time)
{
}

int MenuScreen::pollEvent(sf::Event &event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		getGame()->getStateManager()->change(1);
		soundManager::destroy();
		soundManager::getSound().playBattleMusic();
		getGame()->getStateManager()->push(new GameplayScreen(getGame()));
	}
	return 0;
}
