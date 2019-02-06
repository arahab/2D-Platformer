#include "Game.hpp"

float CheckX = 0, CheckY = 0;
bool RunGame(RenderWindow &window, int &numberLevel)
{
	///////////// инициализация ///////////////////////////

	View view(FloatRect(0, 0, 640, 480));

	Level lvl;


	SoundBuffer kill;
	kill.loadFromFile("res/sound/YUH.wav");
	Sound killSound(kill);
	killSound.setVolume(30);

	SoundBuffer coin;
	coin.loadFromFile("res/sound/coin.ogg");
	Sound coinSound(coin);
	coinSound.setVolume(20);

	changeLevel(lvl, numberLevel);

	Image background;
	background.loadFromFile("res/images/black.png");
	Texture backgroundTexture;
	backgroundTexture.loadFromImage(background);
	Sprite backgroundSprite(backgroundTexture);
	backgroundSprite.setOrigin(backgroundTexture.getSize().x / 2, backgroundTexture.getSize().y / 2);

	Image background2;
	background2.loadFromFile("res/images/blue.png");
	Texture background2Texture;
	background2Texture.loadFromImage(background2);
	Sprite background2Sprite(background2Texture);
	background2Sprite.setOrigin(background2Texture.getSize().x / 2, background2Texture.getSize().y / 2);

	Image heroImage;
	heroImage.loadFromFile("res/images/Ugandatest.png");
	Texture heroTexture;
	//heroTexture.setSmooth(true);
	heroTexture.loadFromImage(heroImage);

	Image easyEnemyImage;
	easyEnemyImage.loadFromFile("res/images/Shrek.png");
	Texture easyEnemyTexture;
	//easyEnemyTexture.setSmooth(true);
	easyEnemyTexture.loadFromImage(easyEnemyImage);

	Image doorImage;
	doorImage.loadFromFile("res/images/door.png");
	Texture doorTexture;
	doorTexture.setSmooth(true);
	doorTexture.loadFromImage(doorImage);

	Image spikesImage;
	spikesImage.loadFromFile("res/images/spikes.png");
	Texture spikesTexture;
	spikesTexture.setSmooth(true);
	spikesTexture.loadFromImage(spikesImage);

	Image movePlatformImage;
	movePlatformImage.loadFromFile("res/images/movingPlatform.png");
	Texture movePlatformTexture;
	movePlatformTexture.setSmooth(true);
	movePlatformTexture.loadFromImage(movePlatformImage);

	Image movePlatformImageY;
	movePlatformImageY.loadFromFile("res/images/movingPlatformY.png");
	Texture movePlatformTextureY;
	movePlatformTextureY.setSmooth(true);
	movePlatformTextureY.loadFromImage(movePlatformImageY);

	Image blueBallImage;
	blueBallImage.loadFromFile("res/images/BlueBall.png");
	Texture blueBallTexture;
	blueBallTexture.setSmooth(true);
	blueBallTexture.loadFromImage(blueBallImage);

	Image fireBallImage;
	fireBallImage.loadFromFile("res/images/FireBall.png");
	Texture fireBallTexture;
	fireBallTexture.setSmooth(true);
	fireBallTexture.loadFromImage(fireBallImage);

	Image coinImage;
	coinImage.loadFromFile("res/images/bitcoin.png");
	Texture coinTexture;
	coinTexture.setSmooth(true);
	coinTexture.loadFromImage(coinImage);


	AnimationManager anim;
	anim.loadFromXML("res/player.xml", heroTexture);
	anim.animList["jump"].loop = 0;

	AnimationManager anim2;
	anim2.loadFromXML("res/enemy.xml", easyEnemyTexture);
	anim2.animList["dead"].loop = 0;

	AnimationManager anim3;
	anim3.loadFromXML("res/spikes.xml", spikesTexture);

	AnimationManager anim4;
	anim4.loadFromXML("res/nextlevel.xml", doorTexture);

	AnimationManager anim5;
	anim5.loadFromXML("res/movingPlatform.xml", movePlatformTexture);

	AnimationManager anim6;
	anim6.loadFromXML("res/movingPlatformY.xml", movePlatformTextureY);

	AnimationManager anim7;
	anim7.loadFromXML("res/BlueBall.xml", blueBallTexture);

	AnimationManager anim8;
	anim8.loadFromXML("res/FireBall.xml", fireBallTexture);

	AnimationManager anim9;
	anim9.loadFromXML("res/Coin.xml", coinTexture);

	Font font;
	font.loadFromFile("res/7526.ttf");
	Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	text.setFillColor(Color(218, 165, 32));//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый

	std::list<Entity*>  entities;
	std::list<Entity*>::iterator it;
	std::list<Entity*>::iterator it2;

	std::vector<Object> e = lvl.GetObjects("EasyEnemy");
	for (int i = 0; i < e.size(); i++)
		entities.push_back(new Enemy(anim2, lvl, e[i].rect.left, e[i].rect.top));

	e = lvl.GetObjects("Coin");
	for (int i = 0; i < e.size(); i++)
		entities.push_back(new Coin(anim9, lvl, e[i].rect.left, e[i].rect.top));

	e = lvl.GetObjects("Spikes");
	for (int i = 0; i < e.size(); i++)
		entities.push_back(new Spikes(anim3, lvl, e[i].rect.left, e[i].rect.top));

	e = lvl.GetObjects("NextLevel");
	for (int i = 0; i < e.size(); i++)
		entities.push_back(new NextLevel(anim4, lvl, e[i].rect.left, e[i].rect.top));

	e = lvl.GetObjects("MovingPlatform");
	for (int i = 0; i < e.size(); i++)
		entities.push_back(new MovingPlatform(anim5, lvl, e[i].rect.left, e[i].rect.top));

	e = lvl.GetObjects("MovingPlatformY");
	for (int i = 0; i < e.size(); i++)
		entities.push_back(new MovingPlatformY(anim6, lvl, e[i].rect.left, e[i].rect.top));

	e = lvl.GetObjects("BlueBall");
	for (int i = 0; i < e.size(); i++)
		entities.push_back(new blueBall(anim7, lvl, e[i].rect.left, e[i].rect.top));

	e = lvl.GetObjects("FireBall");
	for (int i = 0; i < e.size(); i++)
		entities.push_back(new fireBall(anim8, lvl, e[i].rect.left, e[i].rect.top));


	Object pl = lvl.GetObject("player");
	Player p(anim, lvl, pl.rect.left, pl.rect.top);
	if ((CheckX != 0) && (CheckY != 0)) {
		p.x = CheckX;
		p.y = CheckY;
	}

	std::ifstream fin("res/utilityx64.txt");
	fin >> p.cash;

	Clock clock;

	/////////////////// основной цикл  /////////////////////
	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time = time / 800;  // здесь регулируем скорость игры

		if (time > 40) time = 40;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)) p.key["L"] = true;
		if (Keyboard::isKeyPressed(Keyboard::Right)) p.key["R"] = true;
		if (Keyboard::isKeyPressed(Keyboard::Space)) p.key["Space"] = true;
		if (Keyboard::isKeyPressed(Keyboard::LShift)) p.key["Shift"] = true;
		if (Keyboard::isKeyPressed(Keyboard::A)) p.key["A"] = true;
		if (Keyboard::isKeyPressed(Keyboard::D)) p.key["D"] = true;


		for (it = entities.begin(); it != entities.end();)
		{
			Entity *b = *it;
			b->update(time);
			it++;
		}
		if (p.isDead == true)
		{
			RunGame(window, numberLevel);
			return false;
		}
		for (it = entities.begin(); it != entities.end(); it++)//проходимся по эл-там списка
		{

			if ((*it)->life == false)
			{
				Entity *b = *it;
				it = entities.erase(it);
				delete b;
			}

			if ((*it)->getRect().intersects(p.getRect()))//если прямоугольник спрайта объекта пересекается с игроком
			{
				if ((*it)->Name == "EasyEnemy") {//и при этом имя объекта EasyEnemy,то..

					if ((p.y - 1 < (*it)->y) && (p.dy >0))
					{
						if ((*it)->isDead != true)
						{
							p.dy = -0.3;
							killSound.play();
							(*it)->isDead = true;
						}
					}//если прыгнули на врага,то даем врагу скорость 0,отпрыгиваем от него чуть вверх,даем ему здоровье 0
					else
					{//иначе враг подошел к нам сбоку и нанес урон
						if ((*it)->dx < 0)//если враг идет вправо
						{
							(*it)->dx = 0;
							p.isDead = true;
						}
						if ((*it)->dx > 0)//если враг идет влево
						{
							(*it)->dx = 0;
							p.isDead = true;
						}
					}
				}
			}
			if ((((*it)->Name == "MovingPlatform") || (((*it)->Name == "MovingPlatformY"))) && ((*it)->getRect().intersects(p.getRect())))//если игрок столкнулся с объектом списка и имя этого объекта movingplatform
			{
				Entity *movPlat = *it;
				if (p.dy>0)//при этом игрок находится в состоянии после прыжка, т.е падает вниз
					if (p.y + p.h<movPlat->y + movPlat->h)//если игрок находится выше платформы, т.е это его ноги минимум (тк мы уже проверяли что он столкнулся с платформой)
					{
						p.y = movPlat->y - p.h + 3; p.x += movPlat->dx*time; p.dy = 0; p.STATE = Player::stay; // то выталкиваем игрока так, чтобы он как бы стоял на платформе
					}
			}
			if (((*it)->Name == "NextLevel") && ((*it)->getRect().intersects(p.getRect())))//дверь на следующий уровень
			{
				numberLevel++;
				std::ofstream fout("res/utilityx86.txt", std::ios_base::trunc);
				fout.close();
				fout.open("res/utilityx86.txt", std::ios_base::out);
				fout << numberLevel;
				fout.close();

				std::ofstream fout2("res/utilityx64.txt", std::ios_base::trunc);
				fout2.close();
				fout2.open("res/utilityx64.txt", std::ios_base::out);
				fout2 << p.cash;
				fout2.close();

				return false;
			}
			if ((((*it)->Name == "BlueBall") || ((*it)->Name == "Fireball")) && ((*it)->getRect().intersects(p.getRect())))
			{
				p.isDead = true;
			}
			if (((*it)->Name == "Spikes") && ((*it)->getRect().intersects(p.getRect())))//встретил шипы
			{
				if ((p.x - ((*it)->x)) <= -1.5 || (p.x - ((*it)->x)) >= 1.5)
				{
					p.isDead = true;
				}
			}
			if (((*it)->Name == "Coin") && ((*it)->getRect().intersects(p.getRect())))//встретил шипы
			{
				if ((*it)->isDead != true)
				{
					coinSound.play();
					p.cash++;
					(*it)->isDead = true;
				}
			}
			for (it2 = entities.begin(); it2 != entities.end(); it2++)
			{
				if ((*it)->getRect() != (*it2)->getRect())//при этом это должны быть разные прямоугольники
					if (((*it)->getRect().intersects((*it2)->getRect())) && ((*it)->Name == "EasyEnemy") && ((*it2)->Name == "EasyEnemy"))//если столкнулись два объекта и они враги
					{
						(*it)->dx *= -1;//меняем направление движения врага
						if ((*it)->dx < 0)
							(*it)->anim.set("moveLeft");
						if ((*it)->dx > 0)
							(*it)->anim.set("moveRight");
					}
			}
			if (p.isDead == true)
			{
				CheckX = p.sx;
				CheckY = p.sy;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape)) { return false; }
		p.update(time);
		/////////////////////отображаем на экран////////////////////
		view.setCenter(p.x, p.y);
		window.setView(view);

		backgroundSprite.setPosition(view.getCenter());
		background2Sprite.setPosition(view.getCenter());
		if (numberLevel == 3 || numberLevel == 6)
			window.draw(background2Sprite);
		else
			window.draw(backgroundSprite);

		lvl.Draw(window);

		for (it = entities.begin(); it != entities.end(); it++)
			(*it)->draw(window);

		p.draw(window);

		std::ostringstream playerCash;    // объявили переменную
		playerCash << p.cash;		//занесли в нее число очков, то есть формируем строку
		text.setString("COINS " + playerCash.str());//задаем строку тексту и вызываем сформированную выше строку методом .str() 
		text.setPosition(view.getCenter().x + 215, view.getCenter().y - 240);//задаем позицию текста, центр камеры
		window.draw(text);

		window.display();
	}

}