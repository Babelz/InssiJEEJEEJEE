#pragma once

#include <Box2D\Box2D.h>
#include "GameObject.h"
#include <vector>

class World
{
private:
	
	std::vector<GameObject*> gameObjects;
public:
	b2World world;
	World();
	~World();

	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& window);

	void addGameObject(GameObject* gobject);
};

