#include "Coin.hpp"

Coin::Coin(AnimationManager &a, Level &lev, int x, int y) :Entity(a, x, y)
{
	option("Coin", 0, "stay");
}

void Coin::update(float time)
{
	if (isDead == true)
	{
		anim.set("dead");
		life = false;
	}

	anim.tick(time);
}
