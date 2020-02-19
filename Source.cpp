#include <SFML/Graphics.hpp>
#include "Color.hpp"
#include <time.h>
#include <string>
#include <stdlib.h> 
#include <vector>
#include "hero.h"
#include "enemy.h"
#include "button.h"
#include <sstream>
#include <stdio.h>
#include <windows.h>
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
String IntToStr(int x)
{
	char buf[20];
	sprintf_s(buf, "%d", x);
	return buf;
}

using namespace sf;

float frame;

int main()
{
	

	Text totalScore;
	Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		// ошибка...
	}
	// выбираем шрифт
	totalScore.setFont(font); // font это sf::Font

	// выбираем отображаемую строку
	totalScore.setString("Score:");
	// выбираем размер символов
	totalScore.setCharacterSize(24); // в пикселях, а не точках!

	// выбираем цвет
	totalScore.setFillColor(Color::White);
	// выбираем стиль текста
	totalScore.setStyle(Text::Bold | Text::Bold);

	
	const String way = ".\\test2.png";
	srand(time(NULL));
	RenderWindow window(sf::VideoMode(1600, 900), "Black and White");
	window.setFramerateLimit(60);
	std::vector<NME> enemies;
	IMAGE playButton(755, 400, 200, 200, ".\\button.png");
	IMAGE nameGame(500, 300, 650, 650, ".\\name.png");
	totalScore.setPosition(720, 600);
	int INTbestScore = 0;
	int INTtotalScore = 0;
	PLAYER Hero(200, 200, 2530, 1000, ".\\test.png", 0);
	Hero.sprite.setTextureRect(IntRect(100, 0, 100, 100));
	enemies.push_back(NME(400, 200, 2530, 1000, way, 0));
	bool playing = false;
	Clock clock;
	Clock clock1;
	Clock clockJump;
	while (window.isOpen())
	{	
		window.clear();
		
		if (playing == false) {
			Event event;
			
			enemies.clear();

			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			if (Mouse::isButtonPressed(Mouse::Left)){
				
				if (event.mouseButton.x < playButton.x + 100 and event.mouseButton.x > playButton.x and event.mouseButton.y > playButton.y and event.mouseButton.y < playButton.y + 100) {
					INTtotalScore = 0;
					PLAYER Hero(200, 200, 2530, 1000, ".\\test.png", 0);
					Hero.sprite.setTextureRect(IntRect(100, 0, 100, 100));
					enemies.push_back(NME(400, 200, 2530, 1000, way, 0));
					totalScore.setPosition(10, 10);
					playing = true;
					
				}
			}
			
			totalScore.setString("Best score: " + IntToStr(INTbestScore));
			window.draw(totalScore);
			window.draw(playButton.sprite);
			window.draw(nameGame.sprite);
			
			
		}
		if (playing == true) {
			float timeCooldownJump = clockJump.getElapsedTime().asMilliseconds() / 10;
			float timeCooldownQ = clock1.getElapsedTime().asMilliseconds() / 10;
			float time1 = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time1 = time1 / 4000;

			Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::Closed)
					window.close();
			}
			Hero.dir = 5;
			Hero.score = enemies[0].score;
			if (Keyboard::isKeyPressed(Keyboard::D)) {
				if (Hero.forcex >= 0) {
					Hero.dir = 1;
					//Hero.speed = 6;
					if (abs(Hero.forcex) < 12) {
						Hero.forcex += 2;
					}
					frame += 0.02 * time1;
					if (frame > 2) {
						frame -= 2;
					};

				}
				else {
					Hero.forcex += 1;
				}
			}


			if (Keyboard::isKeyPressed(Keyboard::A)) {
				if (Hero.forcex <= 0) {
					Hero.dir = 0;
					//Hero.speed = 6;
					if (abs(Hero.forcex) < 12) {
						Hero.forcex -= 2;
					}
					frame += 0.02 * time1;
					if (frame > 2) {
						frame -= 2;
					};

				}
				else {
					Hero.forcex -= 1;
				}
			}

			if (Keyboard::isKeyPressed(Keyboard::S)) {
				if (Hero.forcey >= 0) {
					Hero.dir = 2;
					//Hero.speed = 6;
					if (abs(Hero.forcey) < 12) {
						Hero.forcey += 2;
					}
					frame += 0.02 * time1;
					if (frame > 2) {
						frame -= 2;
					};

				}
				else {
					Hero.forcey += 1;
				}
			}
			//printf("%f\n", Hero.forcey);

			if (Keyboard::isKeyPressed(Keyboard::W)) {
				if (Hero.forcey <= 0) {
					Hero.dir = 3;
					//Hero.speed = 6;
					if (abs(Hero.forcey) < 12) {
						Hero.forcey -= 2;
					}
					frame += 0.02 * time1;
					if (frame > 2) {
						frame -= 2;
					};

				}
				else {
					Hero.forcey -= 1;
				}
			}
			/*if (Keyboard::isKeyPressed(Keyboard::W)) {
				if (Hero.staying == true and timeCooldownJump > 50) {
					Hero.forcey = -15;
					Hero.staying = false;
					clockJump.restart();
				}
			}*/
			if (enemies[0].levelHard > 10) {
				enemies.push_back(NME(400, 200, 2530, 1000, way, 1));
				enemies[0].levelHard = 0;
			}




			if (Keyboard::isKeyPressed(Keyboard::Q) and timeCooldownQ > 20) {
				clock1.restart();
				if (Hero.color == 0) {
					Hero.color = 1;
					Hero.sprite.setTextureRect(IntRect(100, 100, 100, 100));

				}

				else if (Hero.color == 1)
				{

					Hero.color = 0;
					Hero.sprite.setTextureRect(IntRect(100, 0, 100, 100));


				}
			}

			Hero.update();
			
			for (int i = 0; i < enemies.size(); i++) {
				enemies[i].image.loadFromFile(way);
				enemies[i].texture.loadFromImage(enemies[i].image);
				enemies[i].sprite.setTexture(enemies[i].texture);


				if (Hero.x >= enemies[i].x - 100 and Hero.x <= enemies[i].x + 100 and Hero.y >= enemies[i].y - 100 and Hero.y <= enemies[i].y + 100 and Hero.color == enemies[i].color) {
					if (Hero.score * 10 > INTbestScore){
					INTbestScore = Hero.score * 10;
					}
					totalScore.setPosition(720, 600);
					playing = false;
					
				}
				enemies[i].update();

				window.draw(enemies[i].sprite);
			}
			INTtotalScore = Hero.score*10;
			
			totalScore.setString("Total score: " + IntToStr(INTtotalScore));
			window.draw(totalScore);
			window.draw(Hero.sprite);
			
		}
		
		window.display();
	}

	return 0;
}