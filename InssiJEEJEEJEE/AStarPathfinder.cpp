#include "AStarPathfinder.h"

bool AStarPathfinder::getSkipCorners() {
	return this->skipCorners;
}
void AStarPathfinder::setSkipCorners(bool skipCorners) {
	this->skipCorners = skipCorners;
}

AStarPathfinder::AStarPathfinder(AStarGrid* const grid) {
	this->grid = grid;
}

// Privaatti implementaatio.
std::vector<sf::Vector2f> AStarPathfinder::internalFindPath(bool& foundPath) {
	if (!grid->hasGoal() || !grid->hasStart()) {
		throw "Grid must have goal and start.";
	}

	std::vector<AStarNode*> openList;
	std::vector<AStarNode*> closedList;

	int x = (int)(grid->getStartPosition().x / grid->getNodeSize().x);
	int y = (int)(grid->getStartPosition().y / grid->getNodeSize().y);

	AStarNode* current = grid->nodeAtIndex(y, x);
	openList.push_back(current);

	while (true) {
		if (openList.size() == 0 || 
			(current->getPosition().x == grid->getGoalPosition().x && current->getPosition().y == grid->getGoalPosition().y)) {
			break;
		}

		closedList.push_back(current);

		int x = (int)(current->getPosition().x / grid->getNodeSize().x);
		int y = (int)(current->getPosition().y / grid->getNodeSize().y);

		std::vector<AStarNode*> newNodes;

		// Ylä.
		if (grid->isWalkableAt(y - 1, x)) {
			newNodes.push_back(grid->nodeAtIndex(y - 1, x));
		}
		// Ala.
		if (grid->isWalkableAt(y + 1, x)) {
			newNodes.push_back(grid->nodeAtIndex(y + 1, x));
		}
		// Oikea.
		if (grid->isWalkableAt(y, x + 1)) {
			newNodes.push_back(grid->nodeAtIndex(y, x + 1));
		}
		// Vasen.
		if (grid->isWalkableAt(y, x - 1)) {
			newNodes.push_back(grid->nodeAtIndex(y, x - 1));
		}

		// Jos kulmat voidaan skipata, haetaan kulmista nodet.
		if (skipCorners) {
			// Oikea ylä.
			if (grid->isWalkableAt(y - 1, x + 1)) {
				newNodes.push_back(grid->nodeAtIndex(y - 1, x + 1));
			}
			// Vasen ylä.
			if (grid->isWalkableAt(y - 1, x - 1)) {
				newNodes.push_back(grid->nodeAtIndex(y - 1, x - 1));
			}
			// Oikea ala.
			if (grid->isWalkableAt(y + 1, x + 1)) {
				newNodes.push_back(grid->nodeAtIndex(y + 1, x + 1));
			}
			// Vasen ala.
			if (grid->isWalkableAt(y + 1, x - 1)) {
				newNodes.push_back(grid->nodeAtIndex(y + 1, x - 1));
			}
		}

		openList.erase(std::remove(openList.begin(), openList.end(), current), openList.end());

		for (int i = 0; i < newNodes.size(); i++)
		{
			// Node on jo suljetussa listassa, skipataan tarkistukset.
			if (std::find(closedList.begin(), closedList.end(), newNodes[i]) != closedList.end()) {
				continue;
			}

			// Koska nodea on avoimessa listassa, katsotaan jos sen kautta olisi halvempi liikkua.
			if (std::find(openList.begin(), openList.end(), newNodes[i]) != openList.end()) {
				if (newNodes[i]->getG() > current->getG()) {
					newNodes[i]->setParent(current);
					newNodes[i]->update();
				}
			} else {
				newNodes[i]->setParent(current);
				newNodes[i]->update();

				openList.push_back(newNodes[i]);
			}
		}

		std::sort(openList.begin(), openList.end(), 
			[](AStarNode* a, AStarNode* b) -> bool
		{
			int aF = a->getF();
			int bF = b->getF();

			return aF < bF;
		});

		if (openList.size() == 0) {
			break;
		}

		current = openList[0];
	}

	foundPath = current->getPosition().x == grid->getGoalPosition().x && current->getPosition().y == grid->getGoalPosition().y;

	std::vector<sf::Vector2f> path;

	while (current != 0) {
		path.push_back(current->getPosition());
		current = current->getParent();
	}

	std::reverse(path.begin(), path.end());

	return path;
}

std::vector<sf::Vector2f> AStarPathfinder::findPath(bool& foundPath) {
	return internalFindPath(foundPath);
}

std::vector<sf::Vector2f> AStarPathfinder::findPath() {
	return internalFindPath(foundPath);
}

AStarPathfinder::~AStarPathfinder() {
}
