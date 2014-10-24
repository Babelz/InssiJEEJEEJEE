#pragma once

#include "JaggedVector.h"
#include "AStarNode.h"
#include <ctgmath>
#include <iostream>

class AStarGrid
{
private:
	sf::Vector2f nodeSize;
	sf::Vector2f start;
	sf::Vector2f goal;

	JaggedVector<AStarNode> nodes;
	
	AStarNode* const getNode(sf::Vector2f position);
	bool inBounds(int y, int x);
	bool inBounds(sf::Vector2f position);
	int calcIndexX(float x);
	int calcIndexY(float y);
public:
	sf::Vector2f getStartPosition();
	sf::Vector2f getGoalPosition();
	bool hasStart();
	bool hasGoal();
	
	sf::Vector2f getNodeSize();

	AStarGrid(int width, int height, sf::Vector2f nodeSize);

	bool isWalkableAt(sf::Vector2f position);
	bool isWalkableAt(int y, int x);
	bool isUnwalkableAt(sf::Vector2f position);
	bool isUnwalkableAt(int y, int x);

	void setNodeUnwalkable(sf::Vector2f position);
	void setNodeWalkable(sf::Vector2f position);
	void setGoal(sf::Vector2f position);
	void setStart(sf::Vector2f position);
	AStarNode* nodeAtIndex(int y, int x);

	void updateNodse();
	void resetNodes();

	~AStarGrid();
};

