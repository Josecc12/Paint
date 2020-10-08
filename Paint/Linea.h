#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

using namespace std;
using namespace sf;

class Linea
{
private:
	Vector2f vector1;
	Vector2f vector2;

public:
	Linea();
	void SetStartPoint(int x, int y);
	void SetEndPoint(int x, int y);
	Vertex GetLinea();
};

