#pragma once
#include "Game.h"

class JamGame :
	public Game
{
private:
	
public:
	JamGame(int width, int height);

	void update(sf::Time &tpf);
	void draw(sf::RenderWindow &win);
	
	~JamGame();
};

