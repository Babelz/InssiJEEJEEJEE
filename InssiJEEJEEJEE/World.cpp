#include "World.h"


World::World() : world(b2Vec2(0.0f, 0.0f))
{
	ForestMapGenerator* g = new ForestMapGenerator();

	map = g->generate(*this);
}


World::~World()
{
	// todo tuhoa peliobjectit
}

void World::addGameObject(GameObject* gameObject) {
	gameObjects.push_back(gameObject);
}

void World::update(sf::Time& tpf) {
	map->update(tpf);

	world.Step(1 / 60.f, 100, 3);
	std::for_each(gameObjects.begin(), gameObjects.end(), [&tpf](GameObject* go) {
		go->update(tpf);
	});
}

void World::draw(sf::RenderWindow& window, int fromX, int toX, int fromY, int toY) {
	map->draw(window, fromX, toX, fromY, toY);
	std::for_each(gameObjects.begin(), gameObjects.end(), [&window](GameObject* go) {
		go->draw(window);
	});
}