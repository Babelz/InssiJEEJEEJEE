#include "MonsterGenerator.h"
#include "FiniteStateMachine.h"
#include "FollowState.h"
MonsterGenerator::MonsterGenerator(World &world, soundManager &sound_manager) : world(world), sound_manager(sound_manager), lastSpawn(0.f), spawnFrequency(5.f)
{
	float width = world.getActiveMap()->getWidth();
	float height = world.getActiveMap()->getHeight();
	float tWidth = world.getActiveMap()->getTileWidth();
	float tHeight = world.getActiveMap()->getTileHeight();
	spawnPoints.push_back(sf::Vector2f(0, 0));
	spawnPoints.push_back(sf::Vector2f(width * tWidth - tWidth, 0));
	spawnPoints.push_back(sf::Vector2f(width * tWidth - tWidth, height*tHeight - tHeight));
	spawnPoints.push_back(sf::Vector2f(0, height*tHeight - tHeight));

	MonsterGenerator::addTexture("monster1.png");
	MonsterGenerator::addTexture("monster2.png");
}

MonsterGenerator::~MonsterGenerator()
{
	spawnPoints.clear();
	textures.clear();
}

void MonsterGenerator::addTexture(char *texturePath)
{
	sf::Texture temp;

	if (temp.loadFromFile(texturePath))
		textures.push_back(temp);
}

void MonsterGenerator::spawnMonsters()
{
	if (clock.getElapsedTime().asSeconds() - lastSpawn > spawnFrequency)
	{
		std::random_device rd;
		std::default_random_engine generator(rd());
		std::uniform_int_distribution<int> uniform_dist(0, 3);
		std::uniform_int_distribution<int> uniform_dist2(0, textures.size() - 1);
		int spawnPoint = uniform_dist(generator);

		GameObject* monster = new GameObject();
		monster->body = MonsterGenerator::createMonsterBody(spawnPoints[spawnPoint].x, spawnPoints[spawnPoint].y, world.getBoxWorld());
		monster->body->SetUserData(monster);
		monster->addComponent(new BoxRendererComponent(monster, textures[uniform_dist2(generator)]));
		monster->addComponent(new HealthComponent(monster, 100));
		FiniteStateMachine* brain = new FiniteStateMachine(monster);
		brain->pushState(new FollowState(monster, brain, &world));
		world.addGameObject(monster);

		sound_manager.playSmallMonsterEntry();

		if(spawnFrequency > 1 && (spawnFrequency *= 0.95) < 1) spawnFrequency = 1;

		lastSpawn = clock.getElapsedTime().asSeconds();
	}
}

b2Body *MonsterGenerator::createMonsterBody(float x, float y, b2World *world) {
	b2BodyDef BodyDef;
	BodyDef.position = Convert::worldToBox2d(x, y);
	BodyDef.type = b2_dynamicBody;
	BodyDef.fixedRotation = true;
	BodyDef.linearDamping = 50;
	b2Body* body = world->CreateBody(&BodyDef);

	b2PolygonShape Shape;
	Shape.SetAsBox(Convert::worldToBox2d(32 / 2.f), Convert::worldToBox2d(48.f / 2.f));
	b2FixtureDef FixtureDef;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &Shape;
	body->CreateFixture(&FixtureDef);

	return body;
}
