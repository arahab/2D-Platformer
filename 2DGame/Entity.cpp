#include "Entity.hpp"

Entity::Entity(AnimationManager &A, int X, int Y)
	{
		anim = A;
		x = X;
		y = Y;
		dir = 0;

		isDead = false;
		life = true;
		timer = 0;
		timer_end = 0;
		dx = dy = 0;
	}

void Entity::draw(RenderWindow &window)
	{
		anim.draw(window, x, y + h);
	}

FloatRect Entity::getRect()
	{
		return FloatRect(x, y, w, h);
	}

void Entity::option(std::string NAME, float SPEED = 0, std::string FIRST_ANIM = "")
	{
		Name = NAME;
		if (FIRST_ANIM != "") anim.set(FIRST_ANIM);
		w = anim.getW();
		h = anim.getH();
		dx = SPEED;
	}

Entity::~Entity(){}
