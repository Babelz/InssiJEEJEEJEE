#pragma once
#include "GameObjectComponent.h"
#include "Camera.h"
#include "World.h"
class MouseMovementComponent : public GameObjectComponent
{
private:
	Camera* camera;
	sf::RenderWindow& window;
	World& world;
	bool sword;
	bool direction;
	sf::Texture tex;
	sf::RectangleShape swordRect;
public:
	MouseMovementComponent(GameObject* owner, Camera* camera, World& world, sf::RenderWindow &window);
	~MouseMovementComponent();
	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& win);
};

class ClosestGameObjectsCallback : public b2QueryCallback {
public:
	std::vector<b2Body*> bodies;

	bool ReportFixture(b2Fixture* fixture) {
		bodies.push_back(fixture->GetBody());
		return true;
	}
};