#pragma once

#include "TileModel.h"
#include "Map.h"
#include "World.h"
#include "ModelRegister.h"

class World;

class ForestMapGenerator
{
public:
	ForestMapGenerator();

	virtual Map* generate(World& const world);

	~ForestMapGenerator();
};

