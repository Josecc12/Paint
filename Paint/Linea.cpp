#include "Linea.h"

Linea::Linea() {
	this->x1 = 120;
	this->x2 = 0;
	this->y1 = 120;
	this->y2 = 0;
	this->hiden = true;
	this->linea[0] = Vertex(Vector2f( this->x1, this->y1));
	this->linea[1] = Vertex(Vector2f( this->x2, this->y2));
}

void Linea::SetStartPoint(int x, int y) {
	this->x1 = x;
	this->y1 = y;
	this->linea[0] = Vector2f(this->x1, this->y1);
}

void Linea::SetEndPoint(int x, int y) {
	this->x2 = x;
	this->y2 = y;
	this->linea[1] = Vector2f(this->x2, this->y2);
}

void Linea::SetHiden() {
	this->hiden = false;
}

void Linea::ModColor(Color a)
{
	linea[0].color = a;
	linea[1].color = a;
}

void Linea::ModPosition(int x, int y)
{
	linea[0].position = Vector2f(x, y);
}

int Linea::GetDistance()
{
	int distancia = 0;
	distancia = sqrt((pow(x2 - x1, 2) + pow(y2 - y1, 2)));
	return distancia;
}

bool Linea::GetHiden()
{
	return this->hiden;
}