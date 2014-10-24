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
	int tileWidth;
	int tileHeight;

	JaggedVector<Tile>* tiles;
	ModelRegister* modelRegister;
	std::vector<sf::Vector2f> paths;
public:
	int getWidth();
	int getHeight();
	int getTileHeight();
	int getTileWidth();

	Map(JaggedVector<Tile>* tiles, ModelRegister* modelRegister, std::vector<sf::Vector2f> paths, int tileWidth, int tileHeight);

	void initializeTiles();

	void update(sf::Time &tpf);
	void draw(sf::RenderWindow &window);

	~Map();
};

