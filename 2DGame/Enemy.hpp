#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.hpp"

class Enemy: public Entity
{
public:

	Enemy(AnimationManager &a, Level &lev, int x, int y);
	void update(float time);
	void Collision(float Dx, float Dy);
};

#endif ENEMY_H
