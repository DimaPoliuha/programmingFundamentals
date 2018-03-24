#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "menu.h"
#include "pause.h"
#include "loose.h"
using namespace sf;

bool startgame() {
	RenderWindow window(VideoMode(800, 600), "Arkanoid, Dmytro Poliuha, TI-62");
	window.setFramerateLimit(60);//������� ���������� � �������
	menu(window);//����� ����

	SoundBuffer kickBuffer;//������ ����� ��� �����
	kickBuffer.loadFromFile("kick.ogg");//��������� � ���� ����
	Sound kick(kickBuffer);//������� ���� � ��������� � ���� ���� �� ������

	SoundBuffer destroyBuffer;
	destroyBuffer.loadFromFile("destroy.ogg");
	Sound destroy(destroyBuffer);

	SoundBuffer loosingBuffer;
	loosingBuffer.loadFromFile("loose.ogg");
	Sound loosing(loosingBuffer);

	Texture background;//���������� ������ ���
	background.loadFromFile("images/background1.png");
	Sprite sBackground(background);

	Texture ball;//���������� �����
	ball.loadFromFile("images/ball.png");
	Sprite sBall(ball);

	Texture paddle;//���������� ��������
	paddle.loadFromFile("images/paddle.png");
	Sprite sPaddle(paddle);
	sPaddle.setPosition(360, 560);
	
	Texture blocksWood;//���������� ���������� �����
	blocksWood.loadFromFile("images/blockWood.png");

	Texture blocksCloth;//���������� ������� �����
	blocksCloth.loadFromFile("images/blockCloth.png");

	Texture blocksBrick;//���������� ��������� �����
	blocksBrick.loadFromFile("images/blockBrick.png");

	Sprite block[100];//���������� ������ ������

	int score = 0;

	////////////////����������� �����/////////////////
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
	float x = 390, y = 551;//��������� ��������� ������

	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Tab)) {
			return true;//����������
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			pause(window);//����� �����
		}

		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
		}

		x += dx;//�������� �� �
		for (int i = 0; i<n; i++)
			if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i].getGlobalBounds()))
			{
				block[i].setPosition(-100, 0); 
				dx = -dx;
				destroy.play();//������ ����
				score++;
			}

		y += dy;//�������� �� �
		for (int i = 0; i<n; i++)
			if (FloatRect(x + 3, y + 3, 6, 6).intersects(block[i].getGlobalBounds()))
			{
				block[i].setPosition(-100, 0); 
				dy = -dy;
				destroy.play();//������ ����
				score++;
			}

		//������ �����������, ���� �������� �� �����
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
			kick.play();//������ ����
		}

		sBall.setPosition(x, y);//����� �������� ����������

		window.clear();
		window.draw(sBackground);//������ ������ ���
		window.draw(sBall);//������ ���
		window.draw(sPaddle);//������ ��������

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
			loose(window);//����� ���� ���������
		}

		if (score == 43) {
			return true;
		}

		for (int i = 0; i<n; i++)//������ �����
			window.draw(block[i]);
		window.display();
	}
}

void gameRunning()//������� ������������� ����
{
	if (startgame()) {
		gameRunning();//����������� �����
	}
}

int main()
{
	Music music;//������� ������ ������
	music.openFromFile("musik.ogg");//��������� ����
	music.play();//������������� ������
	music.setVolume(15);
	gameRunning();
	return 0;
}
