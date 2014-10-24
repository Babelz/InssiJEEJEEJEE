#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <iostream>
#include <sstream>
#include "GameObjectComponent.h"
#include "Camera.h"
class Hud : public GameObjectComponent
{
public:
	Hud(GameObject* owner, int *health, int *souls, int *moonPos, sf::Vector2f windowSize, Camera* camera);
	void draw(sf::RenderWindow& window);
	void update(sf::Time& tpf);
	~Hud();
private:
	Camera* camera;
	sf::Font font;
	sf::Text text;
	sf::Texture moonTexture, soulTexture, healthTexture;
	sf::CircleShape moonShape;
	sf::RectangleShape soulShape, healthShape;
	int *health, *souls, *moonPosition;
	sf::Vector2f windowSize;
};

