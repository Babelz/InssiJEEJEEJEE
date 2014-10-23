#pragma once

#include <Box2D\Box2D.h>
#include "GameObject.h"
#include <vector>

class World
{
private:
	b2World world;
	std::vector<GameObject*> gameObjects;
public:
	World();
	~World();

	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& window);

	void addGameObject(GameObject* gobject);
};

