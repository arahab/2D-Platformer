#include "NextLevel.hpp"

NextLevel::NextLevel(AnimationManager &a, Level &lev, int x, int y) :Entity(a, x, y)
{
	option("NextLevel", 0, "stay");
}

void NextLevel::update(float time)
{
	anim.tick(time);
}