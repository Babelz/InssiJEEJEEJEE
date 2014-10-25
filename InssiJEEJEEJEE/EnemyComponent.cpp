#include "EnemyComponent.h"
#include "HealthComponent.h"
#include "World.h"

EnemyComponent::EnemyComponent(GameObject *owner) : GameObjectComponent(owner), lastHit(0.f), hitFrequency(0.5f), damage(30.f)
{
}

EnemyComponent::~EnemyComponent()
{
}

void EnemyComponent::update(sf::Time& tpf)
{
}

void EnemyComponent::draw(sf::RenderWindow& win)
{
	if (clock.getElapsedTime().asSeconds() - lastHit > hitFrequency)
	{
		for (b2ContactEdge* edge = getOwner()->body->GetContactList(); edge; edge = edge->next) {
			b2Body* bodya = edge->contact->GetFixtureA()->GetBody();
			b2Body* bodyb = edge->contact->GetFixtureB()->GetBody();

			GameObject* playa = getOwner()->getWorld()->getPlayer();

			if (bodyb == playa->body)
			{
				GameObject* g = (GameObject*)playa->body->GetUserData();
				HealthComponent* h = (HealthComponent*)g->getComponent<HealthComponent>();
				h->takeDamage(damage);

				lastHit = clock.getElapsedTime().asSeconds();
			}
		}
	}
}
