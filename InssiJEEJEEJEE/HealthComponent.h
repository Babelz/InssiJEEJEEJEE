#pragma once
#include "GameObjectComponent.h"
#include "SFML/Graphics/RectangleShape.hpp"

class HealthComponent : public GameObjectComponent
{
private:
	unsigned int hitPoints;
	unsigned int maxHitPoints;
public:
	HealthComponent(GameObject* owner, unsigned int maxHP);
	~HealthComponent();
	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& window);
};

