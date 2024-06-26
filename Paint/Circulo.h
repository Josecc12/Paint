#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <math.h>
using namespace std;
using namespace sf;
class Circulo
{
public:
	Circulo();
	void SetStartPoint(int x, int y);
	void SetEndPoint(int x, int y);
	void SetHiden();
	void ModColor(Color a);
	int GetDistance();
	bool GetHiden();
	void ModPosition(int x, int y);
	string GetInfo();
	CircleShape GetCirculo();
private:
	int x1, x2;
	int y1, y2;
	bool hiden;
	CircleShape circulo;
};
