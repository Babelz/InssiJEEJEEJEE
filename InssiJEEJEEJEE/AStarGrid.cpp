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
	int x = calcIndexX(position.x);
	int y = calcIndexY(position.y);

	return nodes.itemAtIndex(y, x);
}
bool AStarGrid::inBounds(int y, int x) {
	return x < nodes.getWidth() && y < nodes.getHeight() &&
		   x >= 0 && y >= 0;
}
int AStarGrid::calcIndexX(float x) {
	float mX = fmod(x, nodeSize.x);

	return (int)((x + mX) / nodeSize.x);
}
int AStarGrid::calcIndexY(float y) {
	float mY = fmod(y, nodeSize.y);

	return (int)((y + mY) / nodeSize.y);
}

bool AStarGrid::inBounds(sf::Vector2f position) {
	int x = calcIndexX(position.x);
	int y = calcIndexY(position.y);
	
	return inBounds(y, x);
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
		AStarNode* goalNode = getNode(position);
		goal = goalNode->getPosition();

		for (int i = 0; i < nodes.getHeight(); i++) {
			for (int j = 0; j < nodes.getWidth(); j++) {
				nodes.itemAtIndex(i, j)->setGoal(goal);
				nodes.itemAtIndex(i, j)->update();
			}
		}
	}
}
void AStarGrid::setStart(sf::Vector2f position) {
	AStarNode* const starNode = getNode(position);

	if (starNode != 0) {
		start = starNode->getPosition();
	}
}
AStarNode* AStarGrid::nodeAtIndex(int y, int x) {
	return nodes.itemAtIndex(y, x);
}
// Resetoi kaikki nodet.
void AStarGrid::resetNodes() {
	for (int i = 0; i < nodes.getHeight(); i++) {
		for (int j = 0; j < nodes.getWidth(); j++) {
			nodes.itemAtIndex(i, j)->reset();
		}
	}
}

AStarGrid::~AStarGrid() {
}
