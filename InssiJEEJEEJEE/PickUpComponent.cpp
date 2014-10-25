#include "PickUpComponent.h"
#include "PlayerComponents.h"

PickUpComponent::PickUpComponent(GameObject* owner) : GameObjectComponent(owner)
{
}


PickUpComponent::~PickUpComponent()
{
}

void PickUpComponent::update(sf::Time& tpf) {
	for (b2ContactEdge* edge = getOwner()->body->GetContactList(); edge; edge = edge->next) {
		b2Body* bodya = edge->contact->GetFixtureA()->GetBody();
		b2Body* bodyb = edge->contact->GetFixtureB()->GetBody();

		GameObject* g = (GameObject*)bodyb->GetUserData();
		SoulComponent* s = (SoulComponent*)g->getComponent<SoulComponent>();
		if (s == NULL) return;
		s->setSouls(s->getSouls() + 10);
		this->getOwner()->setRemoveOnNextUpdate(true);
	}
}
void PickUpComponent::draw(sf::RenderWindow& win)
{

}