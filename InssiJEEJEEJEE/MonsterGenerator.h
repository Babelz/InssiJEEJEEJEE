#pragma once
#include <vector>
#include <random>
#include "GameObject.h"
#include "InssiMath.h"
#include "World.h"
#include "BoxRendererComponent.h"
#include "HealthComponent.h"
#include "soundManager.h"

class MonsterGenerator
{
private:
	World &world;
	std::vector<sf::Texture> textures;
	std::vector<sf::Vector2f> spawnPoints;
	float lastSpawn;
	float spawnFrequency;
	sf::Clock clock;
	soundManager &sound_manager;

	void addTexture(char *texturePath);
	b2Body *MonsterGenerator::createMonsterBody(float x, float y, b2World &world);
public:
	MonsterGenerator(World &world, soundManager &sound_manager);
	~MonsterGenerator();

	void spawnMonsters();
};