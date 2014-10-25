#pragma once
#include "GameState.hpp"

class MenuScreen :
	public GameState
{
private:
	sf::Texture menuTexture;
	sf::RectangleShape shape;
public:
	MenuScreen(Game *game);
	~MenuScreen();

	void activate();
	void draw(sf::RenderWindow &window);
	void update(sf::Time &time);
	int pollEvent(sf::Event &event);
};

