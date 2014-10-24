#include "Camera.h"
#include "InssiMath.h"


Camera::Camera(GameObject* owner, World& world, int width, int height) : 
GameObjectComponent(owner), world(world), width(width), height(height)
{
}


Camera::~Camera()
{
}


void Camera::draw(sf::RenderWindow &win) {
}

void Camera::update(sf::Time &tpf) {
	position.x = Convert::box2dToWorld(getOwner()->body->GetPosition().x) + 32.f / 2 - width / 2.f;
	position.y = Convert::box2dToWorld(getOwner()->body->GetPosition().y) + 32.f / 2 - height / 2.f;
	if (position.x < 0)
		position.x = 0;
	if (position.x >= world.getActiveMap()->getWidth() * 32.f - width)
		position.x = world.getActiveMap()->getWidth() * 32.f - width;
	if (position.y < 0)
		position.y = 0;
	if (position.y >= world.getActiveMap()->getHeight() * 32.f - height)
		position.y = world.getActiveMap()->getHeight() * 32.f - height;
		
}