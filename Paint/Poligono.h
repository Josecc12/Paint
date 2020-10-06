#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <math.h>
using namespace std;
using namespace sf;
class Poligono
{
public:
	 Poligono();
	 void SetStartPoint(int x,int y);
	 void SetEndPoint(int x,int y);
	 int GetDistance();
	 CircleShape GetPoligono();
private:
	int x1, x2;
	int y1, y2;
	int lados;
	CircleShape poligono;

	
};

