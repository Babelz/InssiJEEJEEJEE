#pragma once
#include <vector>
#include <random>
#include "GameObject.h"
#include "InssiMath.h"
#include "World.h"
#include "MonsterRendererComponent.h"
#include "HealthComponent.h"
#include "DropComponent.h"
#include "soundManager.h"
#include "EnemyComponent.h"

class MonsterGenerator
{
private:
	World &world;
	std::vector<sf::Texture> textures;
	std::vector<sf::Vector2f> spawnPoints;
	float lastSpawn;
	float spawnFrequency;
	sf::Clock clock;
	soundManager *sound_manager;

	void addTexture(char *texturePath);
	b2Body* createMonsterBody(float x, float y, b2World *world);
public:
	MonsterGenerator(World &world, soundManager *sound_manager);
	~MonsterGenerator();
	void generateTo(float x, float y);
	void spawnMonsters();
};