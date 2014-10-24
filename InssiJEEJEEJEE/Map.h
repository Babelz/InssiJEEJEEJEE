#pragma once

#include "SFML\Graphics\Text.hpp"
#include "SFML\Graphics\RenderWindow.hpp"
#include "JaggedVector.h"
#include "Tile.h"
#include "TileModel.h"
#include "ModelRegister.h"

class Map 
{
private:
	JaggedVector<Tile>* tiles;
	ModelRegister* modelRegister;
	std::vector<sf::Vector2f> paths;
public:
	int getWidth();
	int getHeight();

	Map(JaggedVector<Tile>* tiles, ModelRegister* modelRegister, std::vector<sf::Vector2f> paths);

	void initializeTiles();

	void update(sf::Time &tpf);
	void draw(sf::RenderWindow &window, int fromX, int toX, int fromY, int toY);

	~Map();
};

