#pragma once

#include "AStarGrid.h"
#include <vector>
#include <algorithm>

class AStarPathfinder
{
private:
	AStarGrid* grid;
	bool skipCorners;

	// Käytetään jos käyttäjällä ei kiinnosta löytyikö polku.
	bool foundPath;

	std::vector<sf::Vector2f> internalFindPath(bool& foundPath);
	int calcIndexX(float x);
	int calcIndexY(float y);
public:
	bool getSkipCorners();
	void setSkipCorners(bool skipCorners);

	AStarPathfinder(AStarGrid* const grid);

	std::vector<sf::Vector2f> findPath(bool& foundPath);
	std::vector<sf::Vector2f> findPath();

	~AStarPathfinder();
};

