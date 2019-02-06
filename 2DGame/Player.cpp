#include "Player.hpp"

Player::Player(AnimationManager &a, Level &lev, int x, int y) :Entity(a, x, y)
{
	option("Player", 0, "stay");
	STATE = stay;
	cash = 0;
	obj = lev.GetAllObjects();
}

void Player::Keyboard()
{
	if (key["L"] || key["A"])
	{
		dir = 1;
		dx = -0.1;
		if (key["Shift"]) dx = -0.15;
		if (STATE == stay) STATE = walk;
	}

	if (key["R"] || key["D"])
	{
		dir = 0;
		dx = 0.1;
		if (key["Shift"]) dx = 0.15;
		if (STATE == stay) STATE = walk;
	}
	if (key["Space"])
	{
		if (STATE == stay || STATE == walk) { dy = -0.3; STATE = jump; anim.play("jump"); }
	}

	if (!(key["R"] || key["L"] || key["A"] || key["D"]))
	{
		dx = 0;
		if (STATE == walk) STATE = stay;
	}

	key["R"] = key["L"] = key["Space"] = key["Shift"] = key["A"] = key["D"] = false;
}

void Player::Animation(float time)
{
	if (STATE == stay) anim.set("stay");
	if (STATE == walk) anim.set("walk");
	if (STATE == jump) anim.set("jump");

	if (dir) anim.flip(1);

	if (isDead == true) {
		dx = 0;
		dy = 0;
		timer += time;
		if (timer>1000) { life = false; timer = 0; }
		anim.set("hit");
	}

	anim.tick(time);
}

void Player::update(float time)
{
	Keyboard();

	Animation(time);

	dy += 0.00065*time;

	x += dx * time;
	Collision(0);

	y += dy * time;
	Collision(1);

}

void Player::Collision(int num)
{

	for (int i = 0; i<obj.size(); i++)
		if (getRect().intersects(obj[i].rect))
		{
			if (obj[i].name == "solid")
			{
				if (dy>0 && num == 1) { y = obj[i].rect.top - h;  dy = 0;   STATE = stay; }
				if (dy<0 && num == 1) { y = obj[i].rect.top + obj[i].rect.height;  dy = 0; }
				if (dx>0 && num == 0) { x = obj[i].rect.left - w; }
				if (dx<0 && num == 0) { x = obj[i].rect.left + obj[i].rect.width; }
			}

			if (obj[i].name == "SlopeLeft")
			{
				FloatRect r = obj[i].rect;
				int y0 = (x + w / 2 - r.left) * r.height / r.width + r.top - h;
				if (y>y0)
					if (x + w / 2>r.left)
					{
						y = y0; dy = 0; STATE = stay;
					}
			}

			if (obj[i].name == "SlopeRight")
			{
				FloatRect r = obj[i].rect;
				int y0 = -(x + w / 2 - r.left) * r.height / r.width + r.top + r.height - h;
				if (y > y0)
					if (x + w / 2<r.left + r.width)
					{
						y = y0; dy = 0; STATE = stay;
					}
			}
			if (obj[i].name == "CheckPoint")
			{
				sx = x;
				sy = y;
			}

		}
}
