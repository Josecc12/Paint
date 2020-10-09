#include "Linea.h"

Linea::Linea() {
	this->x1 = 0;
	this->x2 = 0;
	this->y1 = 0;
	this->y2 = 0;
	this->hiden = true;
	this->linea[2] = { Vertex(Vector2f(x1, y1), Vector2f(x2, y2)) };
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

/*void Linea::ModColor(Color a)
{
	linea.color(a);
}

void Linea::ModPosition(int x, int y)
{
	linea.setPosition(x, y);
}
*/
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

Vertex Linea::GetLinea() {

	return (this->linea, 2, Lines);
}