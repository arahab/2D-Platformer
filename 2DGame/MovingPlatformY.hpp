#ifndef MOVINGPLATFORMY_H
#define MOVINGPLATFORMY_H

#include "Entity.hpp"

class MovingPlatformY : public Entity
{
public:
	MovingPlatformY(AnimationManager &a, Level &lev, int x, int y);

	void update(float time);
};

#endif MOVINGPLATFORMY_H
