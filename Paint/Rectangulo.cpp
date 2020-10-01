#include "Rectangulo.h"

Rectangulo::Rectangulo(){
//Figura rectangulo
figurarectangulo = new RectangleShape({ 150,60 });
figurarectangulo->setFillColor(Color::Transparent);
figurarectangulo->setOutlineColor(Color::White);
figurarectangulo->setOutlineThickness(3);
//imagen del rectangulo
figurarectangul = new Texture;
rectangul = new Sprite;
figurarectangul->loadFromFile("1.png");
rectangul->setTexture(*figurarectangul);
rectangul->setPosition(100, 100);
}
