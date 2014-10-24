#pragma once

#include "ForestMapGenerator.h"
#include <Box2D\Box2D.h>
#include "GameObject.h"
#include <vector>
#include "Map.h"
#include "Hud.h"

class World
{
private:
	Map* map;
	std::vector<GameObject*> gameObjects;
	//Hud hud;
public:
	b2World world;
	World();
	~World();

	Map* getActiveMap() {
		return map;
	}

	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& window, int fromX, int toX, int fromY, int toY);

	void addGameObject(GameObject* gobject);
};

