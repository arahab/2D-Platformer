#ifndef COIN_H
#define COIN_H
#include "Entity.hpp"
class Coin : public Entity
{
public:
	Coin(AnimationManager &a, Level &lev, int x, int y);
	void update(float time);
};
#endif COIN_H
