#pragma once
#include "Game.h"
#include "AStarGrid.h"
#include "AStarPathfinder.h"

class JamGame :
	public Game
{
public:
	JamGame(int width, int height);
	~JamGame();
	void update(sf::Time &tpf);
	void draw(sf::RenderWindow &win);
};

