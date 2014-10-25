#pragma once
#include "GameState.hpp"
class GameOverScreen :
	public GameState
{
public:
	GameOverScreen(Game *game);
	~GameOverScreen();

	void activate();
	void draw(sf::RenderWindow &window);
	void update(sf::Time &time);
	int pollEvent(sf::Event &event);
};

