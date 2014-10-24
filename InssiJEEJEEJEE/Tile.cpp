#include "Tile.h"

int Tile::getModelId() {
	return modelId;
}
void Tile::setModel(TileModel* const model) {
	this->model = model;

	sprite.setScale(0.25f, 0.25f);
	sprite.setTexture(*model->getTexture());
	sprite.setPosition(getPosition().x, getPosition().y);
}

Tile::Tile(int modelId, sf::Vector2f position, b2Body* body) {
	this->modelId = modelId;
	this->body = body;
	
	setPosition(position.x, position.y);
}

void Tile::update(sf::Time &tpf) {
}

void Tile::draw(sf::RenderWindow &window) {
	if (model == 0) {
		return;
	}

	window.draw(sprite);
}

Tile::~Tile() {
}
