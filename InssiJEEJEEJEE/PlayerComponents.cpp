#include "PlayerComponents.h"


SoulComponent::SoulComponent(GameObject* owner) 
	: GameObjectComponent(owner) {
	setSouls(0);
}


SoulComponent::~SoulComponent() { }

void SoulComponent::update(sf::Time& tpf) { }
void SoulComponent::draw(sf::RenderWindow& win) { }



MoonComponent::MoonComponent(GameObject* owner) 
	: GameObjectComponent(owner) {
	setMoonState(0);
}

MoonComponent::~MoonComponent() { }

void MoonComponent::update(sf::Time& tpf) { }
void MoonComponent::draw(sf::RenderWindow& win) { }