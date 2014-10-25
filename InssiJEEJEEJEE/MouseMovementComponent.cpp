#include "MouseMovementComponent.h"
#include "InssiMath.h"
#include "Box2D\Common\b2Math.h"
MouseMovementComponent::MouseMovementComponent(GameObject* owner, Camera* camera, World& world, sf::RenderWindow &win) 
	: GameObjectComponent(owner), window(win), world(world)
{
	this->camera = camera;
}


MouseMovementComponent::~MouseMovementComponent()
{
}


void MouseMovementComponent::update(sf::Time& tpf) {
	sf::Vector2i position = sf::Mouse::getPosition(window);
	b2Vec2 mousePosition = b2Vec2(
		camera->getPosition().x + position.x,
		camera->getPosition().y + position.y);

	b2Vec2 charPosition = Convert::box2dToWorld(getOwner()->body->GetPosition());
	
	b2Vec2 toTarget =   mousePosition - charPosition;
	

	float angle = atan2f(-toTarget.x, toTarget.y);
	getOwner()->body->SetTransform(getOwner()->body->GetPosition(), angle);
	
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		// miltä alueelta etsitään
		b2Vec2 lower = Convert::worldToBox2d(charPosition - b2Vec2(48.f, 48.f));
		b2Vec2 upper = Convert::worldToBox2d(charPosition + b2Vec2(48.f, 48.f));
		b2AABB area;
		area.lowerBound = lower;
		area.upperBound = upper;
		ClosestGameObjectsCallback query;

		world.getBoxWorld()->QueryAABB(&query, area);
		// TODO tee kolmio ja eti 
		GameObject *owner = getOwner();
		std::for_each(query.bodies.begin(), query.bodies.end(), [owner](b2Body* body) {
			if (body != owner->body && body->GetUserData() != NULL) {
				GameObject* other = (GameObject*)body->GetUserData();
				HealthComponent* component = (HealthComponent*)other->getComponent<HealthComponent>();
				assert(component != NULL);
				component->takeDamage(10);

				
			}
		});
	}
	

}
void MouseMovementComponent::draw(sf::RenderWindow& win) {

}