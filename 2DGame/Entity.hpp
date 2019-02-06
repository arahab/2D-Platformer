#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Animation.hpp"
#include "level.hpp"
using namespace sf;
class Entity
{
public:
	float x,y,dx,dy,w,h;
	AnimationManager anim;
	std::vector<Object> obj;
	bool life, dir;
	float timer, timer_end;
	std::string Name;
	bool isDead;

	Entity(AnimationManager &A, int X, int Y);
	virtual void update(float time) = 0;
	void draw(RenderWindow &window);
	FloatRect getRect();
	void option(std::string NAME, float SPEED ,std::string FIRST_ANIM);
	virtual ~Entity();
};
#endif ENTITY_H
