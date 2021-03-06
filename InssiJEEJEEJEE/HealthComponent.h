#pragma once
#include "GameObjectComponent.h"
#include "SFML/Graphics/RectangleShape.hpp"

class HealthComponent : public GameObjectComponent
{
private:
	int hitPoints;
	unsigned int maxHitPoints;

	int defMaxHitPoints;
public:

	void addHitPoints(int amount);
	void removeHitPoints(int amount);
	void resetToDefault();

	HealthComponent(GameObject* owner, unsigned int maxHP);
	~HealthComponent();

	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& window);
	void takeDamage(int amount);
	int getHp() {
		return hitPoints;
	}
};

