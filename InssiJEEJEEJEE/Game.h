#pragma once

#include <SFML\Graphics.hpp>

class Game
{
protected:
	sf::RenderWindow window;
public:
	Game(int width, int height);
	void run();
	virtual void update(sf::Time &tpf) = 0;
	virtual void draw(sf::RenderWindow &win) = 0;
	~Game();

};

