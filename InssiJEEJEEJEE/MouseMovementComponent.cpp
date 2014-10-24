#include "MouseMovementComponent.h"
#include "InssiMath.h"
#include "Box2D\Common\b2Math.h"
MouseMovementComponent::MouseMovementComponent(GameObject* owner, Camera* camera, sf::RenderWindow &win) 
	: GameObjectComponent(owner), window(win)
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
	//b2Vec2 mousePosition = b2Vec2(Convert::worldToBox2d(position.x), Convert::worldToBox2d(position.y));
	//b2Vec2 mousePosition = b2Vec2(position.x, position.y);
	
	//b2Vec2 mousePosition = b2Vec2(1280 / 2, 720 / 2);

	b2Vec2 charPosition = Convert::box2dToWorld(getOwner()->body->GetPosition());
	
	b2Vec2 toTarget =   mousePosition - charPosition;
	
	/*
	if (mousePosition.x > charPosition.x)
		toTarget.x = mousePosition.x - charPosition.x;
	else
		toTarget.x = charPosition.x - mousePosition.x;

	if (mousePosition.y > charPosition.y)
		toTarget = b2Vec2(toTarget.x, mousePosition.y - charPosition.y);
	else
		toTarget = b2Vec2(toTarget.x, charPosition.y - mousePosition.y);
	*/
	float angle = atan2f(-toTarget.x, toTarget.y);
	getOwner()->body->SetTransform(getOwner()->body->GetPosition(), angle);
	
	

}
void MouseMovementComponent::draw(sf::RenderWindow& win) {

}