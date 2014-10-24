#pragma once
#include <vector>
#include <random>
#include "GameObject.h"
#include "InssiMath.h"
#include "World.h"
#include "BoxRendererComponent.h"
#include "HealthComponent.h"

class MonsterGenerator
{
private:
	World &world;
	sf::Texture gfxMonster;
	std::vector<sf::Vector2f> spawnPoints;
	float lastSpawn;
	sf::Clock clock;
public:
	MonsterGenerator(World &world, char *texturePath);
	~MonsterGenerator();

	void spawnMonsters();
	b2Body *MonsterGenerator::createMonsterBody(float x, float y, b2World &world);
};