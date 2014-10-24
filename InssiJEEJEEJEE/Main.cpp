#include <SFML/Graphics.hpp>
#include <Box2D\Box2D.h>
#include "AStarGrid.h"
#include "AstarPathfinder.h"
#include "JamGame.h"
#include <wtypes.h>

int main()
{
	DWORD dwError, dwPriClass;
	SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);

	JamGame game(1280, 720);
	game.run();
	return 0;
}