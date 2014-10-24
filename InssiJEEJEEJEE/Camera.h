#pragma once

#include <SFML\Graphics.hpp>
#include "GameObjectComponent.h"
#include "World.h"
class Camera : public GameObjectComponent
{
private:
	sf::View view;
	sf::Vector2f position;
	World& world;
public:
	int width;
	int height;
	Camera(GameObject* owner, World& world, int width, int height);
	void update(sf::Time &tpf);
	void draw(sf::RenderWindow& win);
	sf::Vector2f& getPosition() {
		
		return position;
	}

	const sf::FloatRect& getViewport() {
		return view.getViewport();
	}
	
	~Camera();

};

