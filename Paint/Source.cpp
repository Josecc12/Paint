#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <iostream>
#include "Paint.h"
using namespace std;
using namespace sf;

int main()
{
	Paint* paint1;
	//x,y
	paint1 = new Paint(1000,600);
	paint1->PaintLoop();
	return 0;
}