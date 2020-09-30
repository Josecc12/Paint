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
	void ProcessEvent();
	void ProcessMouse();
	void ProcessCollsion();

private:
	int fps;
	RenderWindow * window;
	CircleShape pen;
	RectangleShape colors[20];
	Texture fill_texture;
	Sprite fill_sprite;
	Event *event1;
	Vector2i position_mouse;
};

