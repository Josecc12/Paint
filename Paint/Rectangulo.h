#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <math.h>
#include <string>
using namespace std;
using namespace sf;
class Rectangulo
{
public:
	Rectangulo();
	void SetStartPoint(int x, int y);
	void SetEndPoint(int x, int y);
	void ModPosition(int x, int y);
	void SetHiden();
	bool GetHiden();
	void ModColor(Color a);
	int GetHeight();
	int GetWidth();
	string GetInfo();
	RectangleShape GetRectangulo();


private:
	int x1, x2 ;
	int y1, y2;
	bool hiden ;
	RectangleShape rectangulo;


};
