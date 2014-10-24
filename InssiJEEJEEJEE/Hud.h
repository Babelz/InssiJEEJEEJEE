#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include <iostream>
#include <sstream>
class Hud
{
public:
	Hud(int *health, int *souls, int *moonPos, sf::Vector2f windowSize);
	void Draw(sf::RenderWindow *window);
	~Hud();
private:
	sf::Font font;
	sf::Text text;
	sf::Texture moonTexture, soulTexture, healthTexture;
	sf::CircleShape moonShape;
	sf::RectangleShape soulShape, healthShape;
	int *health, *souls, *moonPosition;
	sf::Vector2f windowSize;
};

