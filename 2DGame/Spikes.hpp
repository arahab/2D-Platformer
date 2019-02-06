#ifndef SPIKES_H
#define SPIKES_H
#include "Entity.hpp"
class Spikes : public Entity
{
public:
	Spikes(AnimationManager &a, Level &lev, int x, int y);
	void update(float time);
};
#endif SPIKES_H
