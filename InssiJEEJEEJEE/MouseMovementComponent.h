#pragma once
#include "GameObjectComponent.h"
#include "Camera.h"
class MouseMovementComponent : public GameObjectComponent
{
private:
	Camera* camera;
	sf::RenderWindow& window;
public:
	MouseMovementComponent(GameObject* owner, Camera* camera, sf::RenderWindow &window);
	~MouseMovementComponent();
	void update(sf::Time& tpf);
	void draw(sf::RenderWindow& win);
};

