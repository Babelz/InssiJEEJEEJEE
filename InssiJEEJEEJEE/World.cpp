#include "World.h"

b2World* const World::getBoxWorld() {
	return &world;
}
Map* const World::getActiveMap() {
	return map;
}

World::World() : world(b2Vec2(0.0f, 0.0f)) {
	ForestMapGenerator generator;

	map = generator.generate(*this);
}

void World::addGameObject(GameObject* gameObject) {
	gameObjects.push_back(gameObject);
}
void World::update(sf::Time& tpf) {
	map->update(tpf);

	world.Step(1 / 60.f, 100, 3);
	std::for_each(gameObjects.begin(), gameObjects.end(), [&tpf](GameObject* gameObject) {
		gameObject->update(tpf);
	});
}
void World::draw(sf::RenderWindow& window, int fromX, int toX, int fromY, int toY) {
	map->draw(window, fromX, toX, fromY, toY);

	std::for_each(gameObjects.begin(), gameObjects.end(), [&window](GameObject* gameObject) {
		gameObject->draw(window);
	});
}

World::~World() {
	// todo tuhoa peliobjectit
}
