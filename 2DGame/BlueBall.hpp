#ifndef BLUEBALL_H
#define BLUEBALL_H

#include "Entity.hpp"

class blueBall : public Entity
{
public:
	blueBall(AnimationManager &a, Level &lev, int x, int y);

	void update(float time);
};

#endif BLUEBALL_H
