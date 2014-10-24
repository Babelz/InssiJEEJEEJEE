#pragma once

#include <SFML\Graphics.hpp>
#include "GameObjectComponent.h"
class World;
#include "World.h"
class Camera : public GameObjectComponent
{
private:
	int tileWidth;
	int tileHeight;

	int width;
	int height;

	sf::View view;
	sf::Vector2f position;
	World& world;
public:
	int getHeight();
	void setHeight(int value);

	int getWidth();
	void setWidth(int value);

	sf::Vector2f& getPosition();

	Camera(GameObject* owner, World& world, int width, int height, int tileWidth, int tileHeight);
	void update(sf::Time &tpf);
	void draw(sf::RenderWindow& win);
	
	~Camera();

};

