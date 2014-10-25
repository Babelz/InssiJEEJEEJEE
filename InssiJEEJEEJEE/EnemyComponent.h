#pragma once
#include "GameObjectComponent.h"
class EnemyComponent :
	public GameObjectComponent
{
private:
	float lastHit;
	float hitFrequency;
	float damage;
	sf::Clock clock;
public:
	EnemyComponent(GameObject *owner);
	~EnemyComponent();

	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& win);
};

