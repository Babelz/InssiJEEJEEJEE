#include "Hud.h"


Hud::Hud(GameObject* owner, int *health, int *souls, int *moonPos, sf::Vector2f windowSize, Camera* camera) 
	: GameObjectComponent(owner)
{
	this->camera = camera;
	this->windowSize = windowSize;

	this->health = health;
	this->souls = souls;
	this->moonPosition = moonPos;

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


}
void Hud::update(sf::Time& tpf) { 
	moonShape.setPosition(windowSize.x / 2 - moonShape.getRadius() + camera->getPosition().x, camera->getPosition().y);
	soulShape.setPosition(windowSize.x - soulShape.getSize().x + camera->getPosition().x, windowSize.y - soulShape.getSize().y * 1.5f + camera->getPosition().y);
	text.setPosition(soulShape.getPosition().x - (text.getString().getSize() * 20.f), soulShape.getPosition().y - 10.f );
}
void Hud::draw(sf::RenderWindow& window)
{
	// muutetaan nykynen saulim‰‰r‰ stringiksi
	std::stringstream ss;
	ss << *souls;
	std::string str = ss.str();
	text.setString(str);



	// healthin piirto
	int i = 0;
	float x = camera->getPosition().x;
	float y = camera->getPosition().y;
	for (i; i < *health / 3; i++)
	{
		healthShape.setPosition(x + i*healthShape.getSize().x, y);
		healthShape.setTextureRect(sf::IntRect(0, 0, 64, 64));
		window.draw(healthShape);
	}
	
	if (*health % 3 == 2)
	{
		healthShape.setPosition(x + i*healthShape.getSize().x, y);
		healthShape.setTextureRect(sf::IntRect(64, 0, 64, 64));
		window.draw(healthShape);
	}

	if (*health % 3 == 1)
	{
		healthShape.setPosition(x + i*healthShape.getSize().x, y);
		healthShape.setTextureRect(sf::IntRect(128, 0, 64, 64));
		window.draw(healthShape);
	}
	// soulien piirto

	window.draw(soulShape);
	window.draw(text);

	// kuun piirto
	moonShape.setTextureRect(sf::IntRect(*moonPosition, 0, 64, 64));
	window.draw(moonShape);
}
Hud::~Hud()
{
}
