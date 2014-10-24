#pragma once

#include "TileModel.h"
#include "Map.h"
#include "World.h"
#include "ModelRegister.h"
#include "AStarGrid.h"
#include "AStarPathfinder.h"

class World;

class ForestMapGenerator
{
private:
	std::vector<sf::Vector2f> resolvePaths(int mapWidth, int mapHeight, int tileWidth, int tileHeight);
	void generateRooms(int mapWidth, int mapHeight, int tileWidth, int tileHeight, std::vector<sf::Vector2f>& pathsToCenter);
public:
	ForestMapGenerator();

	virtual Map* generate(World& const world);

	~ForestMapGenerator();
};

