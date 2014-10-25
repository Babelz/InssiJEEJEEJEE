#include "ForestMapGenerator.h"
#include <random>

b2Body* createTile(float, float, b2World&);

ForestMapGenerator::ForestMapGenerator() {
}

void ForestMapGenerator::generateRooms(std::vector<sf::Vector2f>& pathsToCenter) {
	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<int> smallRooms(1, 2);
	std::uniform_int_distribution<int> bigRooms(4, 6);

	std::uniform_int_distribution<int> smallRangeX(0, mapWidth - 3);
	std::uniform_int_distribution<int> smallRangeY(0, mapHeight - 3);

	std::uniform_int_distribution<int> bigRangeX(0, mapWidth - 7);
	std::uniform_int_distribution<int> bigRangeY(0, mapHeight - 4);

	std::uniform_int_distribution<int> mod(100, 2000);

	
	// Tehd‰‰n temppelille tila keskelle.
	for (int i =  mapHeight / 2 - 5; i < mapHeight / 2 + 5; i++) {
		for (int j = mapWidth / 2 - 5; j < mapWidth / 2 + 5; j++) {
			pathsToCenter.push_back(sf::Vector2f(j * tileWidth, i * tileHeight));
		}
	}

	AStarPathfinder pathfinder(grid);

	// Isot huoneet.
	int roomsNum = bigRooms(generator);

	int roomStartX = 0;
	int roomStartY = 0;

	for (int i = 0; i < roomsNum; i++) {
		int startX = bigRangeX(generator);
		int startY = bigRangeY(generator);

		sf::Vector2f start(startX * tileWidth, startY * tileHeight);
		
		for (int i = 0; i < mapHeight; i++) {
			for (int j = 0; j < mapWidth; j++) {
				grid->nodeAtIndex(i, j)->setMod(mod(generator));
			}
		}


		for (int y = startY; y < startY + 4; y++) {
			for (int x = startX; x < startX + 7; x++) {
				pathsToCenter.push_back(sf::Vector2f(x * tileWidth, y * tileHeight));
			}
		}

		grid->setStart(start);

		std::vector<sf::Vector2f> path = pathfinder.findPath();

		pathsToCenter.reserve(pathsToCenter.size() + path.size());
		pathsToCenter.insert(pathsToCenter.end(), path.begin(), path.end());


		grid->resetNodes();
	}
}
void ForestMapGenerator::generateHouses(std::vector<sf::Vector2f>& room) {

}
std::vector<sf::Vector2f> ForestMapGenerator::resolvePaths() {
		std::random_device rd;
		std::default_random_engine generator(rd());
		std::uniform_int_distribution<int> mod(100, 2000);

	grid = new AStarGrid(mapWidth, mapHeight, sf::Vector2f(tileWidth, tileHeight));
	AStarPathfinder pathfinder(grid);

	grid->setGoal(sf::Vector2f(tileWidth * mapWidth / 2, tileHeight * mapHeight / 2));

	std::vector<sf::Vector2f> startPoints;

	// Kaikki kulmat.
	startPoints.push_back(sf::Vector2f(0.f, 0.f));
	startPoints.push_back(sf::Vector2f((mapWidth * tileWidth) - tileWidth, 0.f));
	startPoints.push_back(sf::Vector2f(0.0f, (mapHeight * tileHeight) - tileHeight));
	startPoints.push_back(sf::Vector2f((mapWidth * tileWidth) - tileWidth, (mapHeight * tileHeight) - tileHeight));

	/*for (int i = 0; i < mapWidth; i += 10) {
		// Yl‰ ja ala kohdat keskelt‰.
		startPoints.push_back(sf::Vector2f(i * tileWidth, 0.0f));
		startPoints.push_back(sf::Vector2f(i * tileWidth, (mapHeight * tileHeight) - tileHeight));
	}*/

	std::vector<sf::Vector2f> allPaths;

	for (int i = 0; i < startPoints.size(); i++) {
		grid->setStart(startPoints[i]);
		
		std::vector<sf::Vector2f> path = pathfinder.findPath();

		allPaths.reserve(allPaths.size() + path.size());
		allPaths.insert(allPaths.end(), path.begin(), path.end());

		for (int i = 0; i < mapHeight; i++) {
			for (int j = 0; j < mapWidth; j++) {
				grid->nodeAtIndex(i, j)->setMod(mod(generator));
			}
		}

		grid->resetNodes();
	}

	return allPaths;
}

Map* ForestMapGenerator::generate(World& const world) {
	JaggedVector<Tile>* tiles = new JaggedVector<Tile>(mapWidth, mapHeight);
	ModelRegister* modelRegister = new ModelRegister();

	std::random_device rd;
	std::default_random_engine generator(rd());
	std::uniform_int_distribution<int> dirtModels(0, 2);
	std::uniform_int_distribution<int> forestModels(3, 10);

	// Modelien alustus.
	modelRegister->registerModel(new TileModel(0, "dirt1.png", sf::Vector2f(tileWidth, tileHeight), false));
	modelRegister->registerModel(new TileModel(1, "dirt2.png", sf::Vector2f(tileWidth, tileHeight), false));
	modelRegister->registerModel(new TileModel(2, "dirt3.png", sf::Vector2f(tileWidth, tileHeight), false));
	modelRegister->registerModel(new TileModel(3, "tree1.png", sf::Vector2f(tileWidth, tileHeight), true));
	modelRegister->registerModel(new TileModel(4, "tree2.png", sf::Vector2f(tileWidth, tileHeight), true));
	modelRegister->registerModel(new TileModel(5, "tree3.png", sf::Vector2f(tileWidth, tileHeight), true));

	modelRegister->registerModel(new TileModel(6, "grass1.png", sf::Vector2f(tileWidth, tileHeight), true));
	modelRegister->registerModel(new TileModel(7, "grass2.png", sf::Vector2f(tileWidth, tileHeight), true));
	modelRegister->registerModel(new TileModel(8, "grass3.png", sf::Vector2f(tileWidth, tileHeight), true));
	modelRegister->registerModel(new TileModel(9, "grass4.png", sf::Vector2f(tileWidth, tileHeight), true));
	modelRegister->registerModel(new TileModel(10, "grass5.png", sf::Vector2f(tileWidth, tileHeight), true));
	/*
	modelRegister->registerModel(new TileModel(0, "floor1.png", sf::Vector2f(tileWidth, tileHeight), false));
	modelRegister->registerModel(new TileModel(1, "floor2.png", sf::Vector2f(tileWidth, tileHeight), false));
	modelRegister->registerModel(new TileModel(2, "floor3.png", sf::Vector2f(tileWidth, tileHeight), false));
	modelRegister->registerModel(new TileModel(3, "lava1.png", sf::Vector2f(tileWidth, tileHeight), true));
	*/
	std::vector<sf::Vector2f> paths = resolvePaths();
	generateRooms(paths);

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			// Alustetaan sijainti.
			sf::Vector2f position(j * tileWidth, i * tileHeight);

			int modelId = 0;
			if (std::find(paths.begin(), paths.end(), position) != paths.end()) {
				modelId = dirtModels(generator);
			} else {
				modelId = forestModels(generator);
			}

			// Haetaan model id:ll‰.
			TileModel* model = modelRegister->getModelWithId(modelId);

			// Alustetaan tile ja annetaan sille tieto modelin id:st‰.
			Tile *tile = new Tile(model->getId(), position, createTile(position.x, position.y, *world.getBoxWorld()));

			tiles->setItemAtIndex(i, j, tile);
		}
	}

	grid->resetNodes();

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			grid->nodeAtIndex(i, j)->setNodeType(UNWALKABLE);
			grid->nodeAtIndex(i, j)->setMod(0);
		}
	}

	for (int i = 0; i < paths.size(); i++) {
		grid->setNodeWalkable(paths[i]);
	}
	
	Map* map = new Map(tiles, modelRegister, paths, tileWidth, tileHeight, grid);
	map->initializeTiles();

	return map;
}

ForestMapGenerator::~ForestMapGenerator() {
}
