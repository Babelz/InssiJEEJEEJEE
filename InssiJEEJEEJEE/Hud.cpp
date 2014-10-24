#include "Hud.h"


Hud::Hud(int *health, int *souls, int *moonPos, sf::Vector2f windowSize)
{
	this->windowSize = windowSize;

	this->health = health;
	this->souls = souls;
	this->moonPosition = moonPosition;

	font.loadFromFile("BLKCHCRY.ttf");
	moonTexture.loadFromFile("moon2.png");
	soulTexture.loadFromFile("souls.png");
	healthTexture.loadFromFile("heartsbig.png");

	moonShape = sf::CircleShape(32);
	soulShape = sf::RectangleShape(sf::Vector2f(32, 32));
	healthShape = sf::RectangleShape(sf::Vector2f(32, 32));

	moonShape.setTexture(&moonTexture);
	soulShape.setTexture(&soulTexture);
	healthShape.setTexture(&healthTexture);

	text.setFont(font);
	text.setCharacterSize(40);

	moonShape.setPosition(windowSize.x / 2 - moonShape.getRadius(), 0);
	soulShape.setPosition(windowSize.x - soulShape.getSize().x, windowSize.y - soulShape.getSize().y);
	text.setPosition(soulShape.getPosition().x - 8,soulShape.getPosition().y);
}

void Hud::Draw(sf::RenderWindow *window)
{
	// muutetaan nykynen saulim‰‰r‰ stringiksi
	std::stringstream ss;
	ss << *souls;
	std::string str = ss.str();
	text.setString(str);


	// healthin piirto
	int i = 0;
	for (i; i < *health / 3; i++)
	{
		healthShape.setPosition(i*healthShape.getSize().x, 0);
		healthShape.setTextureRect(sf::IntRect(64, 0, 64, 64));
		window->draw(healthShape);
	}
	
	if (*health % 3 == 2)
	{
		healthShape.setPosition(i*healthShape.getSize().x, 0);
		healthShape.setTextureRect(sf::IntRect(64, 0, 64, 64));
		window->draw(healthShape);
	}

	if (*health % 3 == 1)
	{
		healthShape.setPosition(i*healthShape.getSize().x, 0);
		healthShape.setTextureRect(sf::IntRect(128, 0, 64, 64));
		window->draw(healthShape);
	}
	// soulien piirto

	window->draw(soulShape);
	window->draw(text);

	// kuun piirto
	moonShape.setTextureRect(sf::IntRect(*moonPosition, 0, 64, 64));
	window->draw(moonShape);
}
Hud::~Hud()
{
}
