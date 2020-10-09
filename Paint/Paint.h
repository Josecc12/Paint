#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Color.hpp>
#include <string>
#include "Poligono.h"
#include "Rectangulo.h"
#include "Circulo.h"
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
	void ColorCollision();
	void FillCollision();
	void SelectorCollision();

private:	
	int fps;
	int pen_radius;
	int poligono_counter;
	int rectangulo_counter;
	int circulo_counter;
	int pen_counter;
	bool pen_tool;
	bool fill_tool;
	bool eraser_tool;
	bool selector_tool;
	bool poligon_tool;
	bool rectangle_tool;
	bool line_tool;
	bool circle_tool;
	bool triangle_tool;
	Event* event1;
	Vector2i position_mouse;
	Clock* reloj;
	Clock* reloj2;
	Time* tiempo;
	Time* tiempo2;
	Color color_selected;
	RenderWindow* window;

	//TEXTURAS
	Texture *fill_texture;
	Texture *eraser_texture;
	Texture* pen_texture;
	Texture* selector_texture;
	Texture* poligon_texture;
	Texture* rectangle_texture;
	Texture* line_texture;
	Texture* circle_texture;
	Texture* triangle_texture;

	//SPRITES
	Sprite *fill_sprite;
	Sprite *eraser_sprite;
	Sprite *pen_sprite;
	Sprite* selector_sprite;
	Sprite* poligon_sprite;
	Sprite* rectangle_sprite;
	Sprite* line_sprite;
	Sprite* circle_sprite;
	Sprite* triangle_sprite;

	//ARRAYS
	Poligono poligonos[10];
	RectangleShape colors[20];
	CircleShape pen[1000];
	Rectangulo rectangulos[10];
	Circulo circulos[10];
};
