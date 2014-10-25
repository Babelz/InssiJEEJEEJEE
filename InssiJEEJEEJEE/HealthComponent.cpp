#include "HealthComponent.h"
#include "InssiMath.h"

HealthComponent::HealthComponent(GameObject* owner, unsigned int maxHP)
: GameObjectComponent(owner), maxHitPoints(maxHP), hitPoints(maxHP)
{
}


HealthComponent::~HealthComponent()
{
}

void HealthComponent::update(sf::Time& tpf) {
	if (getHp() <= 0) {
		getOwner()->destroy();
	}
}

void HealthComponent::takeDamage(int amount) {
	this->hitPoints -= amount;
}

void HealthComponent::draw(sf::RenderWindow& window) {
	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(32.f * hitPoints/maxHitPoints, 4.f));
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(Convert::box2dToWorld(getOwner()->body->GetPosition().x) + 16.f, Convert::box2dToWorld(getOwner()->body->GetPosition().y) - 8.f);
	window.draw(shape);
}