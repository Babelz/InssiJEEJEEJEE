#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>
#include "AStarGrid.h"
#include "AstarPathfinder.h"
#include "JamGame.h"
int main()
{
	JamGame game(1280, 720);
	game.run();
	return 0;
}