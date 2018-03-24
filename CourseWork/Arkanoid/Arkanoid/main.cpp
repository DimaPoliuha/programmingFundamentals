#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "menu.h"
#include "pause.h"
#include "loose.h"
using namespace sf;

bool startgame() {
	RenderWindow window(VideoMode(800, 600), "Arkanoid, Dmytro Poliuha, TI-62");
	window.setFramerateLimit(60);//частота обновлений в секунду
	menu(window);//вызов меню

	SoundBuffer kickBuffer;//создаЄм буфер дл€ звука
	kickBuffer.loadFromFile("kick.ogg");//загружаем в него звук
	Sound kick(kickBuffer);//создаем звук и загружаем в него звук из буфера

	SoundBuffer destroyBuffer;
	destroyBuffer.loadFromFile("destroy.ogg");
	Sound destroy(destroyBuffer);

	SoundBuffer loosingBuffer;
	loosingBuffer.loadFromFile("loose.ogg");
	Sound loosing(loosingBuffer);

	Texture background;//подключаем задний фон
	background.loadFromFile("images/background1.png");
	Sprite sBackground(background);

	Texture ball;//подключаем шарик
	ball.loadFromFile("images/ball.png");
	Sprite sBall(ball);

	Texture paddle;//подключаем ползунок
	paddle.loadFromFile("images/paddle.png");
	Sprite sPaddle(paddle);
	sPaddle.setPosition(360, 560);
	
	Texture blocksWood;//подключаем дерев€нные блоки
	blocksWood.loadFromFile("images/blockWood.png");

	Texture blocksCloth;//подключаем зеленые блоки
	blocksCloth.loadFromFile("images/blockCloth.png");

	Texture blocksBrick;//подключаем кирпичные блоки
	blocksBrick.loadFromFile("images/blockBrick.png");

	Sprite block[100];//подключаем массив блоков

	int score = 0;

	////////////////расставл€ем блоки/////////////////
	int n = 0;
	for (int i = 1; i <= 9; i++)
		for (int j = 1; j <= 7; j++)
		{
			if (j == 1 && i == 5) {
				block[n].setTexture(blocksCloth);
				block[n].setPosition(i * 70, j * 36);
				n++;
			}
			if (j == 2 && i > 3 && i < 7) {
				block[n].setTexture(blocksCloth);
				block[n].setPosition(i * 70, j * 36);
				n++;
			}
			if (j == 3 && i > 2 && i < 8) {
				block[n].setTexture(blocksCloth);
				block[n].setPosition(i * 70, j * 36);
				n++;
			}
			if (j == 4 && i > 1 && i < 9) {
				block[n].setTexture(blocksWood);
				block[n].setPosition(i * 70, j * 36);
				n++;
			}
			if (j == 5) {
				block[n].setTexture(blocksWood);
				block[n].setPosition(i * 70, j * 36);
				n++;
			}
			if (j == 6) {
				block[n].setTexture(blocksBrick);
				block[n].setPosition(i * 70, j * 36);
				n++;
			}
			if (j == 7) {
				block[n].setTexture(blocksBrick);
				block[n].setPosition(i * 70, j * 36);
				n++;
			}
		}


	float dx = 6, dy = 5;
	float x = 390, y = 551;//начальное положение шарика

	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Tab)) {
			return true;//перезапуск
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			pause(window);//вызов паузы
		}

		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
		}

		x += dx;//скорость по х
		for (int i = 0; i<n; i++)
			if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i].getGlobalBounds()))
			{
				block[i].setPosition(-100, 0); 
				dx = -dx;
				destroy.play();//играем звук
				score++;
			}

		y += dy;//скорость по у
		for (int i = 0; i<n; i++)
			if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i].getGlobalBounds()))
			{
				block[i].setPosition(-100, 0); 
				dy = -dy;
				destroy.play();//играем звук
				score++;
			}

		//мен€ем направление, если ударилс€ об стену
		if (x<15 || x>785)  
			dx = -dx;
		if (y<30 || y>582)  
			dy = -dy;

		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			sPaddle.move(8, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			sPaddle.move(-8, 0);
		}

		if (FloatRect(x, y, 12, 12).intersects(sPaddle.getGlobalBounds())) {
			dy = -(rand() % 5 + 2);
			kick.play();//играем звук
		}

		sBall.setPosition(x, y);//шарик получает координаты

		window.clear();
		window.draw(sBackground);//рисуем задний фон
		window.draw(sBall);//рису€м м€ч
		window.draw(sPaddle);//рисуем ползунок

		if (y > 573) {
			score == 0;
			loosing.play();
			sPaddle.setPosition(360, 560);
			x = 390;
			y = 550;
			int n = 0;
			for (int i = 1; i <= 9; i++)
				for (int j = 1; j <= 7; j++)
				{
					if (j == 1 && i > 1 && i < 9) {
						block[n].setTexture(blocksBrick);
						block[n].setPosition(i * 70, j * 36);
						n++;
					}
					if (j == 2 && i > 2 && i < 8) {
						block[n].setTexture(blocksBrick);
						block[n].setPosition(i * 70, j * 36);
						n++;
					}
					if (j == 3 && (i <= 3 || i > 6)) {
						block[n].setTexture(blocksBrick);
						block[n].setPosition(i * 70, j * 36);
						n++;
					}
					if (j == 4 && i > 4 && i < 6) {
						block[n].setTexture(blocksWood);
						block[n].setPosition(i * 70, j * 36);
						n++;
					}
					if (j == 5) {
						block[n].setTexture(blocksWood);
						block[n].setPosition(i * 70, j * 36);
						n++;
					}
					if (j == 6 && (i <= 3 || i > 6)) {
						block[n].setTexture(blocksCloth);
						block[n].setPosition(i * 70, j * 36);
						n++;
					}
					if (j == 7) {
						block[n].setTexture(blocksCloth);
						block[n].setPosition(i * 70, j * 36);
						n++;
					}
				}
			loose(window);//вызов окна поражени€
		}

		if (score == 43) {
			return true;
		}

		for (int i = 0; i<n; i++)//рисуем блоки
			window.draw(block[i]);
		window.display();
	}
}

void gameRunning()//функци€ перезагружает игру
{
	if (startgame()) {
		gameRunning();//рекурсивный вызов
	}
}

int main()
{
	Music music;//создаем объект музыки
	music.openFromFile("musik.ogg");//загружаем файл
	music.play();//воспроизводим музыку
	music.setVolume(15);
	gameRunning();
	return 0;
}
