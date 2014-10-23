#include "InputMovementComponent.h"


InputMovementComponent::InputMovementComponent(GameObject* owner) :
	GameObjectComponent(owner)
{
}


InputMovementComponent::~InputMovementComponent()
{
}

void InputMovementComponent::update(sf::Time& tpf) {
	const float SPEED = 20.f;
	b2Vec2 vel(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		vel.x = -SPEED;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		vel.x = SPEED;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		vel.y = -SPEED;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		vel.y = SPEED;
	}
	getOwner()->body->SetLinearVelocity(vel);
	
}
void InputMovementComponent::draw(sf::RenderWindow& window) {

}
