#pragma once
#include "SFML\Graphics\Texture.hpp"

class TileModel
{
private:
	int id;
	sf::Texture* texture;
	sf::Vector2f size;
	bool blocked;
public:
	int getId();
	sf::Texture* const getTexture();
	sf::Vector2f getSize();
	bool getBlocked();

	TileModel(int id, std::string textureName, sf::Vector2f size, bool blocked);
	~TileModel();
};

