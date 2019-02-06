#ifndef FIREBALL_H
#define FIREBALL_H

#include "Entity.hpp"

class fireBall : public Entity
{
public:
	fireBall(AnimationManager &a, Level &lev, int x, int y);

	void update(float time);
};

#endif FIREBALL_H
