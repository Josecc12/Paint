#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window/Event.hpp>
using namespace sf;
using namespace std;
class Paint
{
public:
	Paint(int x,int y);	
	void Draw();
	void PaintLoop();

private:
	int fps;
	RenderWindow * window;
};

