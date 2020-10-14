#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

using namespace std;
using namespace sf;

class Linea
{
private:
	int x1, x2;
	int y1, y2;
	bool hiden;

public:
	Linea();
	void SetStartPoint(int x, int y);
	void SetEndPoint(int x, int y);
	void SetHiden();
	void ModColor(Color a);
	int GetDistance();
	bool GetHiden();
	void ModPosition(int x, int y);
	string GetInfo();
	Vertex linea[2];
};

