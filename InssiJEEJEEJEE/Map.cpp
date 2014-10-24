#include "Map.h"

Map::Map(JaggedVector<Tile>* tiles, ModelRegister* modelRegister) {
	this->tiles = tiles;
	this->modelRegister = modelRegister;
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
void Map::draw(sf::RenderWindow &window) {
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
