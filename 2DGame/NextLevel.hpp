#ifndef NEXTLEVEL_H
#define NEXTLEVEL_H

#include "Entity.hpp"

class NextLevel: public Entity
{
public:
	NextLevel(AnimationManager &a, Level &lev, int x, int y);

	void update(float time);
};

#endif NEXTLEVEL_H
