#include "ForestMapGenerator.h"

b2Body* createTile(float, float, b2World&);

ForestMapGenerator::ForestMapGenerator() {
}

void ForestMapGenerator::generateRooms(int mapWidth, int mapHeight, int tileWidth, int tileHeight, std::vector<sf::Vector2f>& pathsToCenter) {
	// Tehd‰‰n temppelille tila keskelle.
	for (int i =  mapHeight / 2 - 5; i < mapHeight / 2 + 5; i++) {
		for (int j = mapWidth / 2 - 5; j < mapWidth / 2 + 5; j++) {
			pathsToCenter.push_back(sf::Vector2f(j * tileWidth, i * tileHeight));
		}
	}

	// Tehd‰‰n randomin verran pieni‰ "huoneita".
	int rooms = 2 + (rand() % (int)(4 - 2 + 1));

	for (int i = 0; i < rooms; i++) {
		int x = rooms = 0 + (rand() % (int)((mapWidth - 5) - 0 + 1));
		int y = rooms = 0 + (rand() % (int)((mapHeight - 3) - 0 + 1));

		for (int j = y; j < y + 3; j++) {
			for (int h = x; h < x + 5; h++) {
				pathsToCenter.push_back(sf::Vector2f(h * tileWidth, j * tileHeight));
			}
		}
	}

	// Tehd‰‰n randomin verran isoja "huoneita".
	rooms = 1 + (rand() % (int)(3 - 1 + 1));

	for (int i = 0; i < rooms; i++) {
		int x = rooms = 0 + (rand() % (int)((mapWidth - 10) - 0 + 1));
		int y = rooms = 0 + (rand() % (int)((mapHeight - 5) - 0 + 1));

		for (int j = y; j < y + 5; j++) {
			for (int h = x; h < x + 10; h++) {
				pathsToCenter.push_back(sf::Vector2f(h * tileWidth, j * tileHeight));
			}
		}
	}
}
std::vector<sf::Vector2f> ForestMapGenerator::resolvePaths(int mapWidth, int mapHeight, int tileWidth, int tileHeight) {
	AStarGrid grid(mapWidth, mapHeight, sf::Vector2f(tileWidth, tileHeight));
	AStarPathfinder pathFinder(&grid);

	grid.setGoal(sf::Vector2f(tileWidth * mapWidth / 2, tileHeight * mapHeight / 2));

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			grid.nodeAtIndex(i, j)->setMod(rand());
		}
	}

	std::vector<sf::Vector2f> startPoints;
	startPoints.push_back(sf::Vector2f(0.f, 0.f));
	startPoints.push_back(sf::Vector2f((mapWidth * tileWidth) - tileWidth, 0.f));
	startPoints.push_back(sf::Vector2f(0.0f, (mapHeight * tileHeight) - tileHeight));
	startPoints.push_back(sf::Vector2f((mapWidth * tileWidth) - tileWidth, (mapHeight * tileHeight) - tileHeight));
	
	startPoints.push_back(sf::Vector2f((mapWidth * tileWidth) / 2, 0.0f));
	startPoints.push_back(sf::Vector2f((mapWidth * tileWidth) / 2, (mapHeight * tileHeight) - tileHeight));
	startPoints.push_back(sf::Vector2f((mapWidth * tileWidth) / 4, 0.0f));
	startPoints.push_back(sf::Vector2f((mapWidth * tileWidth) / 4, (mapHeight * tileHeight) - tileHeight));
	startPoints.push_back(sf::Vector2f((mapWidth * tileWidth) / 3, 0.0f));
	startPoints.push_back(sf::Vector2f((mapWidth * tileWidth) / 3, (mapHeight * tileHeight) - tileHeight));

	std::vector<sf::Vector2f> allPaths;

	for (int i = 0; i < startPoints.size(); i++) {
		grid.setStart(startPoints[i]);
		
		std::vector<sf::Vector2f> path = pathFinder.findPath();

		allPaths.reserve(allPaths.size() + path.size());
		allPaths.insert(allPaths.end(), path.begin(), path.end());

		grid.resetNodes();
	}

	return allPaths;
}

Map* ForestMapGenerator::generate(World& const world) {
	int tileWidth = 32, tileHeight = 32;
	int mapWidth = 80, mapHeight = 50;

	JaggedVector<Tile>* tiles = new JaggedVector<Tile>(mapWidth, mapHeight);
	ModelRegister* modelRegister = new ModelRegister();

	// Modelien alustus.
	modelRegister->registerModel(new TileModel(0, "grass1.png", sf::Vector2f(tileWidth, tileHeight), true));
	modelRegister->registerModel(new TileModel(1, "grass2.png", sf::Vector2f(tileWidth, tileHeight), true));
	modelRegister->registerModel(new TileModel(2, "grass3.png", sf::Vector2f(tileWidth, tileHeight), true));
	modelRegister->registerModel(new TileModel(3, "road1.png", sf::Vector2f(tileWidth, tileHeight), false));
	modelRegister->registerModel(new TileModel(4, "road2.png", sf::Vector2f(tileWidth, tileHeight), false));
	modelRegister->registerModel(new TileModel(5, "road3.png", sf::Vector2f(tileWidth, tileHeight), false));

	std::vector<sf::Vector2f> paths = resolvePaths(mapWidth, mapHeight, tileWidth, tileHeight);
	generateRooms(mapWidth, mapHeight, tileWidth, tileHeight, paths);

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			// Alustetaan sijainti.
			sf::Vector2f position(j * tileWidth, i * tileHeight);

			int modelId = 0;
			if (std::find(paths.begin(), paths.end(), position) != paths.end()) {
				modelId = 3 + (rand() % (int)(5 - 3 + 1));
			} else {
				modelId = 0 + (rand() % (int)(2 - 0 + 1));
			}

			// Haetaan model id:ll‰.
			TileModel* model = modelRegister->getModelWithId(modelId);

			// Alustetaan tile ja annetaan sille tieto modelin id:st‰.
			Tile *tile = new Tile(model->getId(), position, createTile(position.x, position.y, world.world));

			tiles->setItemAtIndex(i, j, tile);
		}
	}
	
	Map* map = new Map(tiles, modelRegister, paths);
	map->initializeTiles();

	return map;
}

ForestMapGenerator::~ForestMapGenerator() {
}
