#pragma once

#include "ForestMapGenerator.h"
#include <Box2D\Box2D.h>
#include "GameObject.h"
#include <vector>
#include "Map.h"
#include "Hud.h"
#include "Game.h"

class World
{
private:
	b2World world;
	Map* map;
	std::vector<GameObject*> gameObjects;
	GameObject* player;
	Game* game;
public:
	b2World* const getBoxWorld();
	Map* const getActiveMap();
	Game* const getGame();
	
	void setPlayer(GameObject* player);
	GameObject* const getPlayer();

	World();

	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& window, int fromX, int toX, int fromY, int toY);
	void addGameObject(GameObject* gobject);

	~World();
};

