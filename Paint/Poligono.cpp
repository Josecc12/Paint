#include "Poligono.h"
Poligono::Poligono()
{
	this->x1 = 0;
	this->x2 = 0;
	this->y1 = 0;
	this->y2 = 0;
	this->xo1 = 0;
	this->yo1 = 0;
	this->lados = 4;
	this->poligono = CircleShape(1, 1);
	poligono.setOutlineColor(Color::Yellow);
}

void Poligono::SetStartPoint(int x, int y)
{
	this->x1 = x;
	this->y1 = y;
	this->xo1 = x;
	this->yo1 = y;
	
}

void Poligono::SetEndPoint(int x, int y)
{
	this->x2 = x;
	this ->y2 = y;
	this->poligono.setPosition(this->x1, this->y1);

}

void Poligono::SetHiden()
{
	this->hiden = false;
}
void Poligono::ModColor(Color a)
{
	poligono.setFillColor(a);
}

void Poligono::ModPosition(int x,int y)
{
	poligono.setPosition(x, y);
}


int Poligono::GetDistance()
{
	int distancia = 0;
	distancia = sqrt((pow(x2 - x1, 2) + pow(y2 - y1,2)));
	return distancia;
}

bool Poligono::GetHiden()
{
	return this->hiden;
}

CircleShape Poligono::GetPoligono()
{
	poligono.setOutlineThickness(2);
	poligono.setRadius(GetDistance() / 2);
	poligono.setPointCount(lados);

	return poligono;
}