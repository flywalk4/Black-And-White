#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <stdlib.h> 
#include <vector>
using namespace sf;
class NME
{
public:
	float x, y, w, h, vx, vy, speed, forcey, forcex, color = 0, hardness = 1;
	int dir, position, levelHard, score = 0;
	bool staying = false;
	String name;
	Image image;
	
	const float gravity = 0.5;
	Texture texture;
	Sprite sprite;
	NME(int X, int Y, int W, int H, String NAME, int COLOR) {
		x = X;
		y = Y;
		w = W;
		h = H;
		name = NAME;
		color = COLOR; //0-white, 1-black
		image.loadFromFile(".\\test2.png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, w, h));
		sprite.setPosition(x, y);
		create();
	}
	void update() {

		vy = forcey;

		vx = forcex;

		if (forcex != 0 and dir == 5) {

			if (forcex >= 0) {
				forcex -= 1;
			}
			else if (forcex <= 0) {
				forcex += 1;
			}
		}
		if (abs(forcex) < 0.01) {
			forcex = 0;
		}
		if (forcey != 0 and dir == 5) {

			if (forcey >= 0) {
				forcey -= 1;
			}
			else if (forcey <= 0) {
				forcey += 1;
			}
		}
		if (abs(forcey) < 0.01) {
			forcey = 0;
		}

		x += vx;
		y += vy;


		sprite.setPosition(x, y);
		if (x > 1700 or x < -100 or y>1000 or y < -100) {
			forcex = 0;
			forcey = 0;
			create();
			levelHard += 1;
			score += 1;

		}
	}
	void create() {
		position = rand() % 4;
		color = rand() % 2;
		if (color == 1) {
			sprite.setTextureRect(IntRect(100, 0, 100, 100));

		}
		if (color == 0) {
			sprite.setTextureRect(IntRect(0, 100, 100, 100));

		}
		if (hardness < 6) {
			hardness += 0.5;
		}

		if (position == 0)
		{
			x = -100;
			y = rand() % 900;
			forcex += rand() % 15 + hardness;
			if (rand() % 2 == 0) {

				if (rand() % 2 == 0) {

					forcey -= hardness;
				}
				else {
					forcey += hardness;
				}
			}

		}
		if (position == 1)
		{
			x = rand() % 1600;
			y = -100;

			forcey += rand() % 15 + hardness;
			if (rand() % 2 == 0) {

				if (rand() % 2 == 0) {

					forcex -= hardness;
				}
				else {
					forcex += hardness;
				}
			}
		}
		if (position == 2)
		{
			x = 1600;
			y = rand() % 900;
			forcex -= rand() % 15 + hardness;
			if (rand() % 2 == 0) {

				if (rand() % 2 == 0) {

					forcey -= hardness;
				}
				else {
					forcey += hardness;
				}
			}

		}
		if (position == 3)
		{
			x = rand() % 1600;
			y = 1000;

			forcey -= rand() % 15 + hardness;
			if (rand() % 2 == 0) {

				if (rand() % 2 == 0) {

					forcex -= hardness;
				}
				else {
					forcex += hardness;
				}
			}
		}


	}
};