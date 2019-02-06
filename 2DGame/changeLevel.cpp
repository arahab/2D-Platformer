#include "changeLevel.hpp"

void changeLevel(Level &lvl, int &numberLevel)
{
	if (numberLevel == 1) { lvl.LoadFromFile("res/map/level1.tmx"); }
	if (numberLevel == 2) { lvl.LoadFromFile("res/map/level2.tmx"); }
	if (numberLevel == 3) { lvl.LoadFromFile("res/map/level3.tmx"); }
	if (numberLevel == 4) { lvl.LoadFromFile("res/map/level4.tmx"); }
	if (numberLevel == 5) { lvl.LoadFromFile("res/map/level5.tmx"); }
	if (numberLevel == 6) { lvl.LoadFromFile("res/map/level6.tmx"); }
	if (numberLevel == 7) { lvl.LoadFromFile("res/map/level7.tmx"); }
}