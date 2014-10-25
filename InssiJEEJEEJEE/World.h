#pragma once

#include "ForestMapGenerator.h"
#include <Box2D\Box2D.h>
#include "GameObject.h"
#include <vector>
#include "Map.h"
#include "Hud.h"
#include <queue>
#include "Game.h"

class World
{
private:
	b2World world;
	Map* map;
	std::vector<GameObject*> gameObjects;
	GameObject* player;
	Game* game;
	std::queue<GameObject*> queue;
public:
	b2World* const getBoxWorld();
	Map* const getActiveMap();
	Game* const getGame();
	void setGame(Game* game) {
		this->game = game;
	}
	void setPlayer(GameObject* player);
	GameObject* const getPlayer();

	World();
	void addGameObjectNextFrame(GameObject* gameObject);
	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& window, int fromX, int toX, int fromY, int toY);
	void addGameObject(GameObject* gobject);

	~World();
};

