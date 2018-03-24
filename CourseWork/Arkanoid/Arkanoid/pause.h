#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;

////////////////////////меню///////////////////

void pause(RenderWindow & window) {
	Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
	menuTexture1.loadFromFile("images/continue.png");
	menuTexture2.loadFromFile("images/help.png");
	menuTexture3.loadFromFile("images/exit.png");
	aboutTexture.loadFromFile("images/about.png");
	menuBackground.loadFromFile("images/pause.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);

	SoundBuffer buttonsBuffer;
	buttonsBuffer.loadFromFile("button.ogg");
	Sound buttons(buttonsBuffer);

	bool isMenu = 1;
	int menuNum = 0;
	//позиции кнопок меню
	menu1.setPosition(250, 150);
	menu2.setPosition(280, 250);
	menu3.setPosition(300, 350);
	menuBg.setPosition(0, 0);

	while (isMenu)
	{
		menu1.setColor(Color::Black);
		menu2.setColor(Color::Black);
		menu3.setColor(Color::Black);
		menuNum = 0;
		window.clear();

		//выбор кнопки
		if (IntRect(250, 135, 265, 60).contains(Mouse::getPosition(window))) {
			menu1.setColor(Color::White);
			menuNum = 1;
		}
		if (IntRect(280, 245, 195, 60).contains(Mouse::getPosition(window))) {
			menu2.setColor(Color::White);
			menuNum = 2;
		}
		if (IntRect(300, 350, 155, 60).contains(Mouse::getPosition(window))) {
			menu3.setColor(Color::White);
			menuNum = 3;
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			buttons.play();
			if (menuNum == 1) {
				isMenu = false;//если нажали первую кнопку, то начинаем игру 
			}
			if (menuNum == 2) {
				window.draw(about);//если нажали вторую кнопку, то рисуем помощь 
				window.display();
				while (!Keyboard::isKeyPressed(Keyboard::Escape));
			}
			if (menuNum == 3) {//если нажали первую кнопку, закрываем игру
				window.close();
				isMenu = false;
			}
		}
		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
}