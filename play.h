#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <stdlib.h> 
#include <vector>
#include "hero.h"
#include "enemy.h"
#include "button.h"


using namespace sf;

float frame;
Event event;
void play()
{	
	
	srand(time(NULL));
	RenderWindow window(sf::VideoMode(1600, 900), "game!");
	window.setFramerateLimit(60);
	std::vector<NME> enemies;
	PLAYER Hero(200, 200, 2530, 1000, "C:\\Users\\shali\\Desktop\\Èãðà\\Game\\Game\\texture\\test2.png", 0);
	enemies.push_back(NME(400, 200, 2530, 1000, "C:\\Users\\shali\\Desktop\\Èãðà\\Game\\Game\\texture\\test2.png", 0));
	BUTTON playButton(800, 400, 200, 200, "C:\\Users\\shali\\Desktop\\button.png");
	
	Hero.sprite.setTextureRect(IntRect(100, 0, 100, 100));
	bool playing = false;
	Clock clock;
	Clock clock1;
	Clock clockJump;
	while (window.isOpen())
	{	
		if (playing == false){
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					if (event.mouseButton.x < playButton.x + 100 and event.mouseButton.x > playButton.x and event.mouseButton.y > playButton.y and event.mouseButton.y < playButton.y + 100) {
						playing = true;
					}
				}
			}
		window.draw(playButton.sprite);
		window.display();
		}
		else if (playing == true){
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
				enemies.push_back(NME(400, 200, 2530, 1000, "C:\\Users\\shali\\Desktop\\Èãðà\\Game\\Game\\texture\\test2.png", 1));
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
			window.clear();
			for (int i = 0; i < enemies.size(); i++) {
				enemies[i].image.loadFromFile("C:\\Users\\shali\\Desktop\\Èãðà\\Game\\Game\\texture\\test2.png");
				enemies[i].texture.loadFromImage(enemies[i].image);
				enemies[i].sprite.setTexture(enemies[i].texture);
			
			
				if (Hero.x >= enemies[i].x - 100 and Hero.x <= enemies[i].x + 100 and Hero.y >= enemies[i].y - 100 and Hero.y <= enemies[i].y + 100 and Hero.color == enemies[i].color) {
					Hero.x = 1;
					Hero.score += 1;
				
				}
				enemies[i].update();
			
				window.draw(enemies[i].sprite);
			}
		
			window.draw(Hero.sprite);
			window.display();
		}
	}

	
}