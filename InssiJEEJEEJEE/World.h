#pragma once

#include "ForestMapGenerator.h"
#include <Box2D\Box2D.h>
#include "GameObject.h"
#include <vector>
#include "Map.h"

class World
{
private:
	Map* map;
	std::vector<GameObject*> gameObjects;
public:
	b2World world;
	World();
	~World();

	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& window);

	void addGameObject(GameObject* gobject);
};

