#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <stdlib.h> 
#include <vector>
#include "hero.h"

using namespace sf;

float frame;



void controlUpdate(){
	PLAYER Hero(200, 200, 2530, 1000, "C:\\Users\\shali\\Desktop\\Игра\\Game\\Game\\texture\\test2.png", 0);
	Hero.sprite.setTextureRect(IntRect(100, 0, 100, 100));
	Clock clock;
	Clock clock1;
	Clock clockJump;
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

}