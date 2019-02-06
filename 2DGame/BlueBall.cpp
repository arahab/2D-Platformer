#include "BlueBall.hpp"

blueBall::blueBall(AnimationManager &a, Level &lev, int x, int y) :Entity(a, x, y)
{
	option("BlueBall", 0, "move");
	dy = 0.1;
}

void blueBall::update(float time)
{
	y += dy * time;
	timer += time;
	if (timer>1000) { dy *= -1; timer = 0; }
	anim.tick(time);
}