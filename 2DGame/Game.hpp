#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <vector>
#include <list>
#include <fstream>
#include <sstream>

#include "level.hpp"
#include "Animation.hpp"
#include "changeLevel.hpp"

#include "Coin.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "BlueBall.hpp"
#include "FireBall.hpp"
#include "MovingPlatform.hpp"
#include "MovingPlatformY.hpp"
#include "NextLevel.hpp"
#include "Spikes.hpp"

using namespace sf;
extern float CheckX, CheckY;
bool RunGame(RenderWindow &window, int &numberLevel);

#endif GAME_H