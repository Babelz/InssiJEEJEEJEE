#pragma once

#include "SFML\Graphics\Text.hpp"
#include "SFML\Graphics\RenderWindow.hpp"
#include "JaggedVector.h"
#include "Tile.h"
#include "TileModel.h"
#include "ModelRegister.h"
#include "AStarGrid.h"

class Map 
{
private:
	int tileWidth;
	int tileHeight;

	JaggedVector<Tile>* tiles;
	AStarGrid* grid;
	ModelRegister* modelRegister;
	std::vector<sf::Vector2f> paths;
public:
	int getWidth();
	int getHeight();
	int getTileHeight();
	int getTileWidth();
	AStarGrid* const getAStarGrid();

	Map(JaggedVector<Tile>* tiles, ModelRegister* modelRegister, std::vector<sf::Vector2f> paths, int tileWidth, int tileHeight, AStarGrid* grid);

	void initializeTiles();

	void update(sf::Time &tpf);
	void draw(sf::RenderWindow &window, int fromX, int toX, int fromY, int toY);

	~Map();
};

