#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window/Event.hpp>
using namespace sf;
using namespace std;
class Rectangulo
{
public:
	Rectangulo();
	
private:
	RectangleShape* figurarectangulo;
	Texture* figurarectangul;
	Sprite* rectangul;
};

