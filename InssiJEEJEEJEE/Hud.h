#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <iostream>
#include <sstream>
#include "GameObjectComponent.h"
#include "PlayerComponents.h"
#include "HealthComponent.h"
class Camera;
#include "Camera.h"
class Hud : public GameObjectComponent
{
public:
	Hud(GameObject* owner, sf::Vector2f windowSize, Camera* camera);
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

	SoulComponent *souls;
	HealthComponent *health;
	MoonComponent *moon;

	sf::Vector2f windowSize;
};

