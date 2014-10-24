#include "Tile.h"
#include "InssiMath.h"
int Tile::getModelId() {
	return modelId;
}
void Tile::setModel(TileModel* const model) {
	this->model = model;

	sprite.setTexture(*model->getTexture());
	sprite.setPosition(Convert::box2dToWorld(getPosition().x), Convert::box2dToWorld(getPosition().y));
	float scaleX = model->getSize().x / model->getTexture()->getSize().x;
	float scaleY = model->getSize().y / model->getTexture()->getSize().y;
	sprite.setScale(scaleX, scaleY);
	

	if (!model->getBlocked()) {
		body->GetWorld()->DestroyBody(body);
	}
}

Tile::Tile(int modelId, sf::Vector2f position, b2Body* body) {
	this->modelId = modelId;
	this->body = body;
	
	setPosition(Convert::worldToBox2d(position.x), Convert::worldToBox2d(position.y));
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
