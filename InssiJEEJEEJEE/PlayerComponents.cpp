#include "PlayerComponents.h"
#include "InssiMath.h"
#include "MouseMovementComponent.h"
#include "AltarComponents.h"

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








InteractionComponent::InteractionComponent(GameObject* owner)
	: GameObjectComponent(owner) {
	((SoulComponent*)owner->getComponent<SoulComponent>())->setSouls(100);
}

InteractionComponent::~InteractionComponent() {

}
void InteractionComponent::update(sf::Time& tpf){

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::E)) return;

	// TODO DIRTY HACK
	b2Vec2 charPosition = getOwner()->getPosition();
	b2Vec2 lower = charPosition - Convert::worldToBox2d(b2Vec2(32.f, 32.f));
	b2Vec2 upper = charPosition + Convert::worldToBox2d(b2Vec2(32.f, 32.f));
	b2AABB area;
	area.lowerBound = lower;
	area.upperBound = upper;
	ClosestGameObjectsCallback query;
	GameObject* owner = getOwner();
	owner->getWorld()->getBoxWorld()->QueryAABB(&query, area);

	std::for_each(query.bodies.begin(), query.bodies.end(), [owner](b2Body* body){
		if (body->GetUserData() != NULL && body != owner->body) {
			
			SwitchComponent* moonSwitch = (SwitchComponent*) ((GameObject*)body->GetUserData())->getComponent<SwitchComponent>();
			moonSwitch->interactWith(owner);
		}
	});

}
void InteractionComponent::draw(sf::RenderWindow& win) {

}