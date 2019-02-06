#include "Spikes.hpp"

Spikes::Spikes(AnimationManager &a, Level &lev, int x, int y) :Entity(a, x, y)
{
	option("Spikes", 0, "stay");
}

void Spikes::update(float time)
{
	anim.tick(time);
}
