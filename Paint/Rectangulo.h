#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <math.h>
using namespace std;
using namespace sf;
class Rectangulo
{
public:
	Rectangulo();
	void SetStartPoint(int x, int y);
	void SetEndPoint(int x, int y);
	void ModPosition(int x, int y);
	void ModColor(Color a);
	float GetHeight();
	float GetWidth();
	RectangleShape GetRectangulo();


private:
	int x1, x2 ;
	int y1, y2;
	bool rectangulo ;
	RectangleShape rectangulo;


};
