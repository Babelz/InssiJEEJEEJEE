#include "AStarGrid.h"

sf::Vector2f AStarGrid::getStartPosition() {
	return start;
}
sf::Vector2f AStarGrid::getGoalPosition() {
	return goal;
}

bool AStarGrid::hasStart() {
	return start.x >= 0.0f && start.y >= 0.0f;
}
bool AStarGrid::hasGoal() {
	return goal.x >= 0.0f && goal.y >= 0.0f;
}

sf::Vector2f AStarGrid::getNodeSize() {
	return nodeSize;
}

AStarGrid::AStarGrid(int width, int height, sf::Vector2f nodeSize) {
	this->nodeSize = nodeSize;
	
	nodes = JaggedVector<AStarNode>(width, height);

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			sf::Vector2f nodePosition(j * nodeSize.x, i * nodeSize.y);
			AStarNode* node = new AStarNode(nodePosition, nodeSize);
			node->setNodeType(WALKABLE);
	
			nodes.setItemAtIndex(i, j, node);
		}
	}
}

AStarNode* const AStarGrid::getNode(sf::Vector2f position) {
	float mX = fmod(position.x, nodeSize.x);
	float mY = fmod(position.y, nodeSize.y);

	int x = (int)((position.x + mX) / nodeSize.y);
	int y = (int)((position.y + mY) / nodeSize.y);

	return nodes.itemAtIndex(y, x);
}
bool AStarGrid::inBounds(int y, int x) {
	return (x < nodes.getWidth() && y < nodes.getHeight()) &&
		   x >= 0 && y >= 0;
}
bool AStarGrid::inBounds(sf::Vector2f position) {
	float mX = fmod(position.x, nodeSize.x);
	float mY = fmod(position.y, nodeSize.y);

	int x = (int)((position.x + mX) / nodeSize.x);
	int y = (int)((position.y + mY) / nodeSize.y);

	return (x < nodes.getWidth() && y < nodes.getHeight()) &&
		   x >= 0 && y >= 0;
}

bool AStarGrid::isWalkableAt(sf::Vector2f position) {
	if (!inBounds(position)) {
		return false;
	}

	return getNode(position)->getNodeType() == WALKABLE;
}
bool AStarGrid::isWalkableAt(int y, int x) {
	if (!inBounds(y, x)) {
		return false;
	}

	return nodes.itemAtIndex(y, x)->getNodeType() == WALKABLE;
}
bool AStarGrid::isUnwalkableAt(sf::Vector2f position) {
	if (!inBounds(position)) {
		return false;
	}

	return getNode(position)->getNodeType() == UNWALKABLE;
}
bool AStarGrid::isUnwalkableAt(int y, int x) {
	if (!inBounds(y, x)) {
		return false;
	}

	return nodes.itemAtIndex(y, x)->getNodeType() == UNWALKABLE;
}

void AStarGrid::setNodeUnwalkable(sf::Vector2f position) {
	getNode(position)->setNodeType(UNWALKABLE);
}
void AStarGrid::setNodeWalkable(sf::Vector2f position) {
	getNode(position)->setNodeType(WALKABLE);
}
void AStarGrid::setGoal(sf::Vector2f position) {
	AStarNode* const goalNode = getNode(position);
	
	if (goalNode != 0) {
		goal = position;
	}
}
void AStarGrid::setStart(sf::Vector2f position) {
	AStarNode* const starNode = getNode(position);

	if (starNode != 0) {
		start = position;
	}
}
AStarNode* AStarGrid::nodeAtIndex(int y, int x) {
	return nodes.itemAtIndex(y, x);
}

void AStarGrid::updateNodse() {
	for (int i = 0; i < nodes.getHeight(); i++) {
		for (int j = 0; j < nodes.getWidth(); j++) {
			nodes.itemAtIndex(i, j)->update();
		}
	}
}
void AStarGrid::resetNodes() {
	for (int i = 0; i < nodes.getHeight(); i++) {
		for (int j = 0; j < nodes.getWidth(); j++) {
			nodes.itemAtIndex(i, j)->reset();
		}
	}
}

AStarGrid::~AStarGrid()
{
}
