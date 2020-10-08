#include "Rectangulo.h"
Rectangulo::Rectangulo() {
	this->x1=0;
	this->x2=0;
	this->y1=0;
	this->y2=0;
	this->rectangulo=RectangleShape();
	this->hiden=true;
	this->rectangulo.setOutlineColor(Color::White);
	this->rectangulo.setFillColor(Color::Black);
}
void Rectangulo::SetStartPoint(int x, int y)
{
	this->x1 = x;
	this->y1 = y;
	

}
void Rectangulo::SetEndPoint(int x, int y)
{
	this->x2 = x;
	this->y2 = y;
	this->rectangulo.setPosition(this->x1, this->y1);
	

}
float Rectangulo::GetHeight() {
	float altura;
	altura = y2 - y1;
	return altura;
}
float Rectangulo::GetWidth() {
	float ancho;
	ancho = x2 - x1;
	return ancho;
}
RectangleShape Rectangulo::GetRectangulo()
{
	rectangulo.setOutlineThickness(2);
	rectangulo.setSize(sf::Vector2f(GetWidth(), GetHeight()));
	return rectangulo;
}
void Rectangulo::SetHiden() {
	this->hiden = false;
}
bool Rectangulo::GetHiden()
{
	return this->hiden;
}
void Rectangulo::ModColor(Color a)
{
	rectangulo.setFillColor(a);
}
void Rectangulo::ModPosition(int x, int y)
{
	rectangulo.setPosition(x, y);
}