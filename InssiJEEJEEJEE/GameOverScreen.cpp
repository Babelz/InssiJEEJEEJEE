#include "GameOverScreen.h"
#include "Game.h"
#include "MenuScreen.h"
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
	sf::View view = window.getDefaultView();
	view.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
	view.reset(sf::FloatRect(0, 0, 1280.f, 720.f));
	window.setView(view);
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
		Game* game = getGame();
		getGame()->doNextUpdate([game]() {
			game->getStateManager()->push(new MenuScreen(game));
		});
	}
	return 0;
}
