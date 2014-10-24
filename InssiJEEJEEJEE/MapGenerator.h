#pragma once

#include "Map.h"
#include "World.h"

class MapGenerator
{
public:
	MapGenerator();

	virtual Map* generate(World& const world) = 0;

	~MapGenerator();
};

