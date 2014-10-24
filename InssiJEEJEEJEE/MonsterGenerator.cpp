#include "MonsterGenerator.h"

MonsterGenerator::MonsterGenerator(World &world, char *texturePath) : world(world), lastSpawn(0.f)
{
	spawnPoints.push_back(sf::Vector2f(0, 0));
	spawnPoints.push_back(sf::Vector2f(2560, 0));
	spawnPoints.push_back(sf::Vector2f(2560, 1600));
	spawnPoints.push_back(sf::Vector2f(0, 1600));

	if (!gfxMonster.loadFromFile(texturePath))
		return;
}

MonsterGenerator::~MonsterGenerator()
{
	spawnPoints.clear();
}

void MonsterGenerator::spawnMonsters()
{
	if (clock.getElapsedTime().asSeconds() - lastSpawn > 1)
	{
		std::random_device rd;
		std::default_random_engine e1(rd());
		std::uniform_int_distribution<int> uniform_dist(0, 3);
		int spawnPoint = uniform_dist(e1);

		GameObject* monster1 = new GameObject();
		monster1->body = MonsterGenerator::createMonsterBody(spawnPoints[spawnPoint].x, spawnPoints[spawnPoint].y, *world.getBoxWorld());
		monster1->addComponent(new BoxRendererComponent(monster1, gfxMonster));
		monster1->addComponent(new HealthComponent(monster1, 100));
		world.addGameObject(monster1);

		lastSpawn = clock.getElapsedTime().asSeconds();
	}
}


b2Body *MonsterGenerator::createMonsterBody(float x, float y, b2World &world) {
	b2BodyDef BodyDef;
	BodyDef.position = Convert::worldToBox2d(x, y);
	BodyDef.type = b2_dynamicBody;
	BodyDef.fixedRotation = true;
	BodyDef.linearDamping = 50;
	b2Body* body = world.CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(Convert::worldToBox2d(32 / 2.f), Convert::worldToBox2d(48.f / 2.f));
	b2FixtureDef FixtureDef;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;
	body->CreateFixture(&FixtureDef);

	return body;
}
