#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <stdlib.h> 
#include <vector>
using namespace sf;
class PLAYER
{
public:
	float x, y, w, h, vx, vy, speed, forcey, forcex, color = 0;
	int dir = 0, score = 1;
	bool staying = false;
	String name;
	Image image;
	const float gravity = 0.5;
	Texture texture;
	Sprite sprite;
	PLAYER(int X, int Y, int W, int H, String NAME, int COLOR) {
		x = X;
		y = Y;
		w = W;
		h = H;
		staying = false;
		name = NAME;
		color = COLOR; //0-white, 1-black
		image.loadFromFile(name);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, w, h));
		sprite.setPosition(x, y);
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
		if (x > 1500) {
			x = 1500;
		}
		if (y > 800) {
			y = 800;
		}
		if (x < 0) {
			x = 0;
		}
		if (y < 0) {
			y = 0;
		}
		x += vx;
		y += vy;


		sprite.setPosition(x, y);
	}
	void DelMe()
	{
		delete this;
	}
};