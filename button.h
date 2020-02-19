#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <stdlib.h> 
#include <vector>
using namespace sf;
class IMAGE
{
public:
	float w, h, x, y = 0;
	String name;
	Image image;
	Texture texture;
	Sprite sprite;
	IMAGE(int X, int Y, int W, int H, String NAME) {
		x = X;
		y = Y;
		w = W;
		h = H;
		name = NAME;
		image.loadFromFile(name);
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		sprite.setTextureRect(IntRect(0, 0, w, h));
		sprite.setPosition(x, y);
	}
};