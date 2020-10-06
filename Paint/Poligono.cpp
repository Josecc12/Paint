#include "Poligono.h"
Poligono::Poligono()
{
	this->x1 = 0;
	this->x2 = 0;
	this->y1 = 0;
	this->y2 = 0;
	this->lados = 4;
	this->poligono = CircleShape(1, 1);
}

void Poligono::SetStartPoint(int x, int y)
{
	this->x1 = x;
	this->y1 = y;
	cout << "COORDENADA 1" << endl;
}

void Poligono::SetEndPoint(int x, int y)
{
	this->x2 = x;
	this ->y2 = y;
	cout << "COORDENADA 2" << endl;
}

int Poligono::GetDistance()
{
	int distancia = 0;
	distancia = sqrt((pow(x2 - x1, 2) + pow(y2 - y1,2)));
	return distancia;
}

CircleShape Poligono::GetPoligono()
{
	poligono = CircleShape(GetDistance());
	poligono.setPosition(x1, y1);
	return poligono;
}