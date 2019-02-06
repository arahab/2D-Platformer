#include "MovingPlatformY.hpp"

MovingPlatformY::MovingPlatformY(AnimationManager &a, Level &lev, int x, int y) :Entity(a, x, y)
{
	option("MovingPlatformY", 0, "move");
	dy = -0.1;
}

void MovingPlatformY::update(float time)
{
	y += dy * time;
	timer += time;
	if (timer>1000) { dy *= -1; timer = 0; }
	anim.tick(time);
}