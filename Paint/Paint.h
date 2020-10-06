#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Color.hpp>
#include <string>
#include "Poligono.h"
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
	void ProcessCollision();
	void FillCollision();
	void SelectorCollision();

private:	
	int fps;
	bool pen_tool;
	bool fill_tool;
	bool eraser_tool;
	bool selector_tool;
	RenderWindow* window;
	bool poligon_tool = false;
	CircleShape pen;
	CircleShape prueba;
	RectangleShape colors[20];
	Texture *fill_texture;
	Texture *eraser_texture;
	Texture* pen_texture;
	Texture* selector_texture;
	Texture* poligon_texture;
	Sprite *fill_sprite;
	Sprite *eraser_sprite;
	Sprite *pen_sprite;
	Sprite* selector_sprite;
	Sprite* poligon_sprite;
	Event *event1;
	Vector2i position_mouse;
	Clock *reloj;
	Clock* reloj2;
	Time* tiempo;
	Time* tiempo2;
	Color color_selected;
	Poligono poligono;
};

