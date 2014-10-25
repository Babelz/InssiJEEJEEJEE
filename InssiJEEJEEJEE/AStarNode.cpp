#include "AStarNode.h"


NodeType AStarNode::getNodeType() {
	return this->nodeType;
}
void AStarNode::setNodeType(NodeType nodeType) {
	this->nodeType = nodeType;
}

int AStarNode::getF() {
	return this->h + this->g + this->mod;
}
int AStarNode::getH() {
	return this->h;
}
int AStarNode::getG() {
	return this->g;
}

sf::Vector2f AStarNode::getPosition() {
	return position;
}

int AStarNode::getMod() {
	return this->mod;
}
void AStarNode::setMod(int mod) {
	this->mod = mod;
}

void AStarNode::setGoal(sf::Vector2f goal) {
	this->goal = goal;
}

AStarNode* AStarNode::getParent() {
	return this->parent;
}
void AStarNode::setParent(AStarNode* const parent) {
	this->parent = parent;
}

AStarNode::AStarNode(sf::Vector2f position, sf::Vector2f size) {
	this->position = position;
	this->size = size;
}

// Laskee montako nodea pitää liikkua jotta päästään goaliin.
void AStarNode::calculateH() {
	int nodes = 0;

	float startX = goal.x > position.x ? position.x : goal.x;
	float startY = goal.y > position.y ? position.y : goal.y;

	float endX = startX == position.x ? goal.x : position.x;
	float endY = startY == position.y ? goal.y : position.y;

	while (startX < endX) {
		startX += size.x;
		nodes++;
	}

	while (startY < endY) {
		startY += size.y;
		nodes++;
	}

	h = nodes * 10.f;
}
void AStarNode::calculateG() {
	// Jos parent null, hypätään pois.
	if (parent == 0) {
		return;
	}

	g = 14.0f;

	if ((parent->position.y + size.y == position.y || parent->position.y - size.y == position.y) &&
		position.y == parent->position.y) {
		g = 10.0f;
	} else if ((parent->position.x + size.x == position.y || parent->position.x - size.x) &&
		       position.y == parent->position.y) {
		g = 10.0f;
	}
}

void AStarNode::update() {	
	calculateH();
	calculateG();
}
void AStarNode::reset() {
	h = 0;
	g = 0;
	parent = 0;
}

AStarNode::~AStarNode(){
}
