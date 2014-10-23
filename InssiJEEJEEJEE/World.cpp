#include "World.h"


World::World() : world(b2Vec2(0.0f, 0.0f))
{
}


World::~World()
{
	gameObjects.erase(gameObjects.end());
}

void World::addGameObject(GameObject* gameObject) {
	gameObjects.push_back(gameObject);
}

void World::update(sf::Time& tpf) {
	std::for_each(gameObjects.begin(), gameObjects.end(), [&tpf](GameObject* go) {
		go->update(tpf);
	});
}

void World::draw(sf::RenderWindow& window) {

	std::for_each(gameObjects.begin(), gameObjects.end(), [&window](GameObject* go) {
		go->draw(window);
	});
}