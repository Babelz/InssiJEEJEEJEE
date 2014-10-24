#include "TileModel.h"
#include "SFML\Graphics\Texture.hpp"

int TileModel::getId() {
	return id;
}
sf::Texture* const TileModel::getTexture() {
	return texture;
}
sf::Vector2f TileModel::getSize() {
	return size;
}
bool TileModel::getBlocked() {
	return blocked;
}

TileModel::TileModel(int id, std::string textureName, sf::Vector2f size, bool blocked) {
	this->id = id;
	this->size = size;
	this->blocked = blocked;

	texture = new sf::Texture();
	texture->loadFromFile(textureName);
}


TileModel::~TileModel() {
}
