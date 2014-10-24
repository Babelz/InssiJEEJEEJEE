#include "ForestMapGenerator.h"

b2Body* createTile(float, float, b2World&);

ForestMapGenerator::ForestMapGenerator() {
}

void ForestMapGenerator::generateRooms(std::vector<sf::Vector2f>& pathsToCenter) {
	// Tehd‰‰n temppelille tila keskelle.
	for (int i =  mapHeight / 2 - 5; i < mapHeight / 2 + 5; i++) {
		for (int j = mapWidth / 2 - 5; j < mapWidth / 2 + 5; j++) {
			pathsToCenter.push_back(sf::Vector2f(j * tileWidth, i * tileHeight));
		}
	}
}
void ForestMapGenerator::generateHouses(std::vector<sf::Vector2f>& room) {

}
std::vector<sf::Vector2f> ForestMapGenerator::resolvePaths() {
	grid = new AStarGrid(mapWidth, mapHeight, sf::Vector2f(tileWidth, tileHeight));
	AStarPathfinder pathFinder(grid);

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
		
		std::vector<sf::Vector2f> path = pathFinder.findPath();

		allPaths.reserve(allPaths.size() + path.size());
		allPaths.insert(allPaths.end(), path.begin(), path.end());

		for (int i = 0; i < mapHeight; i++) {
			for (int j = 0; j < mapWidth; j++) {
				grid->nodeAtIndex(i, j)->setMod(random.next(100, 2000));
			}
		}

		grid->resetNodes();
	}

	return allPaths;
}

Map* ForestMapGenerator::generate(World& const world) {
	JaggedVector<Tile>* tiles = new JaggedVector<Tile>(mapWidth, mapHeight);
	ModelRegister* modelRegister = new ModelRegister();

	// Modelien alustus.
	modelRegister->registerModel(new TileModel(0, "grass1.png", sf::Vector2f(tileWidth, tileHeight), true));
	modelRegister->registerModel(new TileModel(1, "grass2.png", sf::Vector2f(tileWidth, tileHeight), true));
	modelRegister->registerModel(new TileModel(2, "grass3.png", sf::Vector2f(tileWidth, tileHeight), true));
	modelRegister->registerModel(new TileModel(3, "road1.png", sf::Vector2f(tileWidth, tileHeight), false));
	modelRegister->registerModel(new TileModel(4, "road2.png", sf::Vector2f(tileWidth, tileHeight), false));
	modelRegister->registerModel(new TileModel(5, "road3.png", sf::Vector2f(tileWidth, tileHeight), false));

	std::vector<sf::Vector2f> paths = resolvePaths();
	generateRooms(paths);

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			// Alustetaan sijainti.
			sf::Vector2f position(j * tileWidth, i * tileHeight);

			int modelId = 0;
			if (std::find(paths.begin(), paths.end(), position) != paths.end()) {
				modelId = 5;//random.next(3, 5);
			} else {
				modelId = 2; //random.next(0, 2);
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
