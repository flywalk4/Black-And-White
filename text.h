#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <stdlib.h> 
#include <vector>
class TEXT {
public:
	float x, y = 0;
	String text;
	Font font;
	font.loadFromFile("arial.ttf");
	TEXT(int X, int Y, String TEXT){
		x = X;
		y = Y;
		text = TEXT;
		Text Text1;
		Text1.setFont(font);
		Text1.setPosition(x, y);
		Text1.setString(text);
		Text1.setCharacterSize(24);
		Text1.setFillColor(Color::White);
		Text1.setStyle(Text1::Bold);
	}
}