#include "Camera.h"
#include "InssiMath.h"

int Camera::getHeight() {
	return height;
}
void Camera::setHeight(int value) {
	height = value;
}
int Camera::getWidth() {
	return width;
}
void Camera::setWidth(int value) {
	width = value;
}

sf::Vector2f& Camera::getPosition() {
	return position;
}

Camera::Camera(GameObject* owner, World& world, int width, int height, int tileWidth, int tileHeight) :
GameObjectComponent(owner), world(world), width(width), height(height) {
	this->tileWidth = tileWidth;
	this->tileHeight = tileHeight;
}

void Camera::draw(sf::RenderWindow &win) {
}

void Camera::update(sf::Time &tpf) {
	position.x = Convert::box2dToWorld(getOwner()->body->GetPosition().x) + 32.f / 2 - width / 2.f;
	position.y = Convert::box2dToWorld(getOwner()->body->GetPosition().y) + 32.f / 2 - height / 2.f;
	
	if (position.x < 0) {
		position.x = 0;
	}

	if (position.x >= world.getActiveMap()->getWidth() * tileWidth - width) {
		position.x = world.getActiveMap()->getWidth() * tileWidth - width;
	}

	if (position.y < 0) {
		position.y = 0;
	}

	if (position.y >= world.getActiveMap()->getHeight() * tileHeight - height) {
		position.y = world.getActiveMap()->getHeight() * tileHeight - height;
	}
}

Camera::~Camera() {
}