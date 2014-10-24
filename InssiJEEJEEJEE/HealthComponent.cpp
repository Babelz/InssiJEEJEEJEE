#include "HealthComponent.h"

HealthComponent::HealthComponent(GameObject* owner, unsigned int maxHP)
: GameObjectComponent(owner), maxHitPoints(maxHP), hitPoints(maxHP)
{
}


HealthComponent::~HealthComponent()
{
}

void HealthComponent::update(sf::Time& tpf) {

}

void HealthComponent::draw(sf::RenderWindow& window) {
	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(32.f * hitPoints/maxHitPoints, 4.f));
	shape.setFillColor(sf::Color::Red);
	shape.setPosition(Convert::box2dToWorld(getOwner()->body->GetPosition().x), Convert::box2dToWorld(getOwner()->body->GetPosition().y) - 8.f);
	window.draw(shape);
}