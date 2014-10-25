#include "World.h"
#include "InssiMath.h"
void createWall(float x, float y, float width, float height, b2World& world);

b2World* const World::getBoxWorld() {
	return &world;
}
Map* const World::getActiveMap() {
	return map;
}

Game* const World::getGame() {
	return game;
}

void World::setPlayer(GameObject* player) {
	this->player = player;
}
GameObject* const World::getPlayer() {
	return player;
}

std::vector<GameObject*>* World::getGameObjects() {
	return &gameObjects;
}

World::World() : world(b2Vec2(0.0f, 0.0f)) {
	ForestMapGenerator generator;

	map = generator.generate(*this);
	// tehdään seinät
	float tw = map->getTileWidth();
	float th = map->getTileHeight();
	float w = map->getWidth() * tw;
	float h = map->getHeight() * th;

	float desiredSize = 10.f;
	// center
	float c = desiredSize / 2.f;
	// koska origin
	float offset = -32.f;
	// ylä
	createWall(w / 2.f, offset - c, w, desiredSize, world);
	// vasen
	createWall(offset - c, h / 2.f,  desiredSize, h, world);
	// ala
	createWall(w / 2.f, h + offset + c, w, desiredSize, world);
	// oikea
	createWall(w + offset + c, h / 2.f, desiredSize, h, world);
}

void World::addGameObject(GameObject* gameObject) {
	gameObject->setWorld(this);
	gameObjects.push_back(gameObject);
}

void World::addGameObjectNextFrame(GameObject* gameObject) {
	gameObject->setWorld(this);
	queue.push(gameObject);
}
void World::update(sf::Time& tpf) {
	for (int i = gameObjects.size() - 1; i >= 0; i--) {
		GameObject* g = gameObjects[i];
		if (!g->getRemoveOnNextUpdate()) continue;

		g->destroy();
		gameObjects.erase(gameObjects.begin() + i);
	}
	while (queue.size() > 0) {
		gameObjects.push_back(queue.front());
		queue.pop();
	}
	world.Step(1 / 60.f, 8, 3);
	map->update(tpf);
	for (int i = 0; i < gameObjects.size(); i++) {
		GameObject* gameObject = gameObjects[i];
		gameObject->update(tpf);
	}
	
}
void World::draw(sf::RenderWindow& window, int fromX, int toX, int fromY, int toY) {
	map->draw(window, fromX, toX, fromY, toY);

	for (int i = 0; i < gameObjects.size(); i++) {
		GameObject* gameObject = gameObjects[i];
		gameObject->draw(window);
	}
}

World::~World() {
	// todo tuhoa peliobjectit
}



void createWall(float x, float y, float width, float height, b2World& world) {
	b2BodyDef bodyDef;
	bodyDef.position = Convert::worldToBox2d(x, y);
	bodyDef.type = b2_staticBody;
	b2Body* body = world.CreateBody(&bodyDef);
	b2PolygonShape shape;
	shape.SetAsBox(Convert::worldToBox2d(width / 2.f), Convert::worldToBox2d(height / 2.f));
	b2FixtureDef fixdef;
	fixdef.shape = &shape;
	body->CreateFixture(&fixdef);

}