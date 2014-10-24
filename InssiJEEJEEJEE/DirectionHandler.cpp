#include "DirectionHandler.h"

void DirectionHandler::setOffset(sf::Vector2f offset) {
	this->offset = offset;
}

DirectionHandler::DirectionHandler() {
	offset = sf::Vector2f(0.f, 0.0f);
}


bool DirectionHandler::checkVertical() {
	switch (vertical)
	{
	case UP:
		return (int)position.y <= (int)goal.y;
	case DOWN:
		return (int)position.y >= (int)goal.y;
	default:
		return (int)position.y == (int)goal.y;
	}
}
bool DirectionHandler::checkHorizontal() {
	switch (horizontal)
	{
	case LEFT:
		return (int)position.x <= (int)goal.x;
	case RIGHT:
		return (int)position.x >= (int)goal.x;
	default:
		return (int)position.x == (int)goal.x;
	}
}

void DirectionHandler::changeDirection(sf::Vector2f position, sf::Vector2f goal) {
	this->position = position + offset;
	this->goal = goal;
	
	if (position.x == goal.x) {
		horizontal = HorizontalDirection::HORSTILL;
	} else {
		horizontal = position.x < goal.x ? HorizontalDirection::RIGHT : HorizontalDirection::LEFT;
	}

	if (position.y == goal.y) {
		vertical = VerticalDirection::VERSTILL;
	} else {
		vertical = position.y < goal.y ? VerticalDirection::DOWN : VerticalDirection::UP;
	}
}
sf::Vector2f DirectionHandler::translate() {
	int x = horizontal;
	int y = vertical;

	return sf::Vector2f(x, y);
}
bool DirectionHandler::passedGoal(sf::Vector2f currentPosition) {
	currentPosition += offset;

	bool hor = checkHorizontal();
	bool ver = checkVertical();

	if (hor && ver) {
		return true;
	}

	if (horizontal != HorizontalDirection::HORSTILL && vertical != VerticalDirection::VERSTILL) {
		return hor && ver;
	} else if (horizontal == HorizontalDirection::HORSTILL) {
		return ver;
	} else if (vertical == VerticalDirection::VERSTILL) {
		return hor;
	}
}

DirectionHandler::~DirectionHandler() {
}
