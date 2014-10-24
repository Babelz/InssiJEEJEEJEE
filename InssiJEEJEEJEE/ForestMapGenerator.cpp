#include "ForestMapGenerator.h"

b2Body* createTile(float, float, b2World&);

ForestMapGenerator::ForestMapGenerator() {
}

Map* ForestMapGenerator::generate(World& const world) {
	int min = 0, max = 2;

	JaggedVector<Tile>* tiles = new JaggedVector<Tile>(80, 50);
	ModelRegister* modelRegister = new ModelRegister();

	modelRegister->registerModel(new TileModel(0, "grass1.png", sf::Vector2f(32.f, 32.f), false));
	modelRegister->registerModel(new TileModel(1, "grass2.png", sf::Vector2f(32.f, 32.f), false));
	modelRegister->registerModel(new TileModel(2, "grass3.png", sf::Vector2f(32.f, 32.f), false));

	for (int i = 0; i < tiles->getHeight(); i++) {
		for (int j = 0; j < tiles->getWidth(); j++) {
			// Haetaan randomilla model id.
			int modelId = min + (rand() % (int)(max - min + 1));

			// Haetaan model id:llä.
			TileModel* model = modelRegister->getModelWithId(modelId);

			// Alustetaan sijainti.
			sf::Vector2f position(j * model->getSize().x, i * model->getSize().y);

			// Alustetaan tile ja annetaan sille tieto modelin id:stä.
			Tile *tile = new Tile(model->getId(), position, createTile(position.x, position.y, world.world));

			tiles->setItemAtIndex(i, j, tile);
		}
	}

	modelRegister->registerModel(new TileModel(3, "blocked.png", sf::Vector2f(32.f, 32.f), false));
	
	Map* map = new Map(tiles, modelRegister);
	map->initializeTiles();

	return map;
}

ForestMapGenerator::~ForestMapGenerator() {
}
