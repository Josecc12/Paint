#include "Linea.h"

Linea::Linea() {
	this->x1 = 0;
	this->x2 = 0;
	this->y1 = 0;
	this->y2 = 0;
	this->hiden = true;
	this->linea[0] = Vertex(Vector2f( 120, 120));
	this->linea[1] = Vertex(Vector2f( 240, 240));
}

void Linea::SetStartPoint(int x, int y) {
	this->x1 = x;
	this->y1 = y;
}

void Linea::SetEndPoint(int x, int y) {
	this->x2 = x;
	this->y2 = y;
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