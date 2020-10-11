#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <math.h>
using namespace std;
using namespace sf;

class Triangulo

{
public:
	Triangulo();
	void SetStartPoint(int x, int y);
	void SetEndPoint(int x, int y);
	void SetHiden();
	void ModColor(Color a);
	int GetDistance();
	bool GetHiden();
	void ModPosition(int x, int y);
	CircleShape GetTriangulo();
	string GetInfo();
private:
	int x1, x2;
	int y1, y2;
	int lados;
	bool hiden = true;
	CircleShape triangulo;

};

