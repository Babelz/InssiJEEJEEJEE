#pragma once
#include "GameState.hpp"
class GameOverScreen :
	public GameState
{
private:
	sf::Texture defeatTexture;
	sf::RectangleShape shape;
public:
	GameOverScreen(Game *game);
	~GameOverScreen();

	void activate();
	void draw(sf::RenderWindow &window);
	void update(sf::Time &time);
	int pollEvent(sf::Event &event);
};

