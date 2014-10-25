#include "GameOverScreen.h"
#include "Game.h"

GameOverScreen::GameOverScreen(Game *game) : GameState(game)
{
	if (!defeatTexture.loadFromFile("defeat.png"))
		return;

	shape = sf::RectangleShape(sf::Vector2f(1280.f, 720.f));
	shape.setTexture(&defeatTexture);
}


GameOverScreen::~GameOverScreen()
{
}

void GameOverScreen::activate()
{
}

void GameOverScreen::draw(sf::RenderWindow &window)
{
	window.draw(shape);
	window.display();
}

void GameOverScreen::update(sf::Time &time)
{
}

int GameOverScreen::pollEvent(sf::Event &event)
{
	if (event.type == sf::Event::KeyPressed)
	{
		getGame()->getStateManager()->change(0);
	}
	return 0;
}
