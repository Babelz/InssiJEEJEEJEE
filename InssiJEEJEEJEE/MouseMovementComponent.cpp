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
	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left)) return;
	
	sf::Vector2i position = sf::Mouse::getPosition(window);
	b2Vec2 mousePosition = b2Vec2(
		camera->getPosition().x + position.x,
		camera->getPosition().y + position.y);

	b2Vec2 charPosition = Convert::box2dToWorld(getOwner()->body->GetPosition());
	
	b2Vec2 toTarget =   mousePosition - charPosition;
	

	float angle = atan2f(-toTarget.x, toTarget.y);
	//getOwner()->body->SetTransform(getOwner()->body->GetPosition(), angle);
	
	// miltä alueelta etsitään
	b2Vec2 lower = Convert::worldToBox2d(charPosition - b2Vec2(32.f, 32.f));
	b2Vec2 upper = Convert::worldToBox2d(charPosition + b2Vec2(32.f, 32.f));
	b2AABB area;
	area.lowerBound = lower;
	area.upperBound = upper;
	ClosestGameObjectsCallback query;

	world.getBoxWorld()->QueryAABB(&query, area);
	// TODO tee kolmio ja eti 
	GameObject *owner = getOwner();
	std::for_each(query.bodies.begin(), query.bodies.end(), [owner,angle](b2Body* body) {
		if (body != owner->body && body->GetUserData() != NULL) {
			GameObject* other = (GameObject*)body->GetUserData();
			HealthComponent* component = (HealthComponent*)other->getComponent<HealthComponent>();
			if (component != NULL) {
				component->takeDamage(5);

				/*
				b2PolygonShape triangle;
				float f = 8.f;
				b2Vec2 verts[3] = {
				Convert::worldToBox2d(0, -f),
				Convert::worldToBox2d(f, f),
				Convert::worldToBox2d(-f, f)
				};
				b2Rot rotation;
				rotation.Set(angle);
				for (int i = 0; i < 3; i++) {
				verts[i] = b2Mul(rotation, verts[i]);
				}
				triangle.Set(verts, 3);

				if (b2TestOverlap(&triangle, 0, other->body->GetFixtureList()->GetShape(), 0, body->GetTransform(), other->body->GetTransform())) {
				component->takeDamage(2);
				}*/
			}
		}
	});
	
	

}
void MouseMovementComponent::draw(sf::RenderWindow& win) {
	b2Vec2 pos = Convert::box2dToWorld(getOwner()->getPosition());
	b2PolygonShape triangle;
	b2Vec2 verts[3] = {
		Convert::worldToBox2d(16.f, -16.f),
		Convert::worldToBox2d(-16.f, -16.f),
		
		Convert::worldToBox2d(0, 16.f)
	};
	b2Rot rot;
	rot.Set(45 * b2_pi / 180);
	triangle.Set(verts, 3);
	
	sf::ConvexShape shape;
	shape.setPointCount(3);
	for (int i = 0; i < 3; i++) {
		b2Vec2 vertex = Convert::box2dToWorld(triangle.GetVertex(i));
		vertex = b2Mul(rot, vertex);
		shape.setPoint(i,
			sf::Vector2f( 
				vertex.x,
				vertex.y
			));
	}
	b2Vec2 v = Convert::box2dToWorld(getOwner()->getPosition());
	shape.setPosition(v.x +32.f, v.y);
	//b2TestOverlap()
	shape.setOrigin(sf::Vector2f(16.f, 16.f));
	win.draw(shape);
}