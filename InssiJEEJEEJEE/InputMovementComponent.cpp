#include "InputMovementComponent.h"


InputMovementComponent::InputMovementComponent(GameObject* owner) :
	GameObjectComponent(owner)
{
}


InputMovementComponent::~InputMovementComponent()
{
}

void InputMovementComponent::update(sf::Time& tpf) {
	sf::Event inputEvent;

	
}
void InputMovementComponent::draw(sf::RenderWindow& window) {

}
