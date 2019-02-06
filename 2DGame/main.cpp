#include "Game.hpp"
#include "Menu.hpp"


int main()
{
	RenderWindow window(VideoMode(1024, 768), "2D Platformer");
	
	window.setFramerateLimit(60);
	
	int numberLevel = 0;
	window.setMouseCursorVisible(false);
	std::ifstream fin("res/utilityx86.txt");
	fin >> numberLevel;
	if (menu(window) == 1)
	{
		numberLevel = 1;

		std::ofstream fout2("res/utilityx64.txt", std::ios_base::trunc);
		fout2.close();
		fout2.open("res/utilityx64.txt", std::ios_base::out);
		fout2 << 0;
		fout2.close();
	}

	Music level1, level2, level3;
	level1.openFromFile("res/sound/level1.ogg");
	level2.openFromFile("res/sound/level2.ogg");
	level3.openFromFile("res/sound/level3.ogg");
	level1.setVolume(20);
	level2.setVolume(20);
	level3.setVolume(20);
	level1.setLoop(true);
	level2.setLoop(true);
	level3.setLoop(true);

	SoundBuffer respawn;
	respawn.loadFromFile("res/sound/respawn.ogg");
	Sound respawnSound(respawn);
	respawnSound.setVolume(70);

	if (numberLevel == 1)
	{
		text(window, numberLevel);
		respawnSound.play();

		level1.play();

		RunGame(window, numberLevel);
	}
	if (numberLevel == 2)
	{
		level1.stop();

		text(window, numberLevel);
		respawnSound.play();

		level2.play();

		RunGame(window, numberLevel);
	}
	if (numberLevel == 3)
	{
		level2.stop();

		text(window, numberLevel);
		respawnSound.play();

		level3.play();

		RunGame(window, numberLevel);
	}
	if (numberLevel == 4)
	{
		level3.stop();

		text(window, numberLevel);
		respawnSound.play();

		level1.play();

		RunGame(window, numberLevel);
	}
	if (numberLevel == 5)
	{
		level1.stop();

		text(window, numberLevel);
		respawnSound.play();

		level2.play();

		RunGame(window, numberLevel);
	}
	if (numberLevel == 6)
	{
		level2.stop();

		text(window, numberLevel);
		respawnSound.play();

		level3.play();

		RunGame(window, numberLevel);
	}
	if (numberLevel == 7)
	{
		level3.stop();

		text(window, numberLevel);
		respawnSound.play();

		level1.play();

		RunGame(window, numberLevel);
	}
	if (numberLevel == 8)
	{
		level1.stop();
		end(window, numberLevel);
	}

	std::ofstream fout("res/utilityx86.txt", std::ios_base::trunc);
	fout.close();
	fout.open("res/utilityx86.txt", std::ios_base::out);
	fout << numberLevel;
	fout.close();
	return 0;
}
