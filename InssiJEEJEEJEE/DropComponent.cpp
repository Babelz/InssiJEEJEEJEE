#include "DropComponent.h"
#include "BoxRendererComponent.h"
#include "PickUpComponent.h"
#include "InssiMath.h"
#include "World.h"

DropComponent::DropComponent(GameObject *owner, sf::Texture &texture) : GameObjectComponent(owner), itemTexture(texture)
{
}

DropComponent::~DropComponent()
{
}

void DropComponent::update(sf::Time& tpf)
{
}

void DropComponent::draw(sf::RenderWindow& window)
{
}

void DropComponent::dropItem(float x, float y, World *world)
{
	GameObject *item = new GameObject();;
	b2BodyDef BodyDef;
	BodyDef.position = b2Vec2(x, y);
	BodyDef.type = b2_staticBody;

	b2Body* body = world->getBoxWorld()->CreateBody(&BodyDef);
	b2PolygonShape Shape;
	Shape.SetAsBox(Convert::worldToBox2d(16.f / 2.f), Convert::worldToBox2d(16.f / 2.f));
	b2FixtureDef FixtureDef;
	FixtureDef.shape = &Shape;
	FixtureDef.isSensor = true;

	body->CreateFixture(&FixtureDef);

	item->body = body;
	body->SetUserData(item); // Tarvitaanko?
	item->addComponent(new BoxRendererComponent(item, itemTexture));
	item->addComponent(new PickUpComponent(item));

	world->addGameObject(item);
}