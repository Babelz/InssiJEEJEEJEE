#pragma once

#include "TileModel.h"
#include "Map.h"
#include "World.h"
#include "ModelRegister.h"
#include "AStarGrid.h"
#include "AStarPathfinder.h"
#include "Random.h"

class World;

class ForestMapGenerator
{
private:
	const int mapWidth = 80;
	const int mapHeight = 50;
	const int tileWidth = 64;
	const int tileHeight = 64;

	AStarGrid* grid;

	std::vector<sf::Vector2f> resolvePaths();
	void generateRooms(std::vector<sf::Vector2f>& pathsToCenter);
	void generateHouses(std::vector<sf::Vector2f>& rooms);
public:
	ForestMapGenerator();

	virtual Map* generate(World& const world);

	~ForestMapGenerator();
};

