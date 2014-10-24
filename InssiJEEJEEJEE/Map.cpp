#include "Map.h"

int Map::getWidth() {
	return tiles->getWidth();
}
int Map::getHeight() {
	return tiles->getHeight();
}

Map::Map(JaggedVector<Tile>* tiles, ModelRegister* modelRegister, std::vector<sf::Vector2f> paths) {
	this->tiles = tiles;
	this->modelRegister = modelRegister;
	this->paths = paths;
}

void Map::initializeTiles() {
	for (int i = 0; i < tiles->getHeight(); i++) {
		for (int j = 0; j < tiles->getWidth(); j++) {
			Tile* tile = tiles->itemAtIndex(i, j);

			int modelId = tile->getModelId();
			TileModel* model = modelRegister->getModelWithId(modelId);
			tile->setModel(model);
		}
	}
}

void Map::update(sf::Time &tpf) {
	for (int i = 0; i < tiles->getHeight(); i++) {
		for (int j = 0; j < tiles->getWidth(); j++) {
			tiles->itemAtIndex(i, j)->update(tpf);
		}
	}
}
void Map::draw(sf::RenderWindow &window, int fromX, int toX, int fromY, int toY) {
	for (int i = 0; i < tiles->getHeight(); i++) {
		for (int j = 0; j < tiles->getWidth(); j++) {
			tiles->itemAtIndex(i, j)->draw(window);
		}
	}
}

Map::~Map() {
	delete(tiles);
	delete(modelRegister);
}
