#include "Triangulo.h"

Triangulo::Triangulo()
{
	this->x1 = 0;
	this->x2 = 0;
	this->y1 = 0;
	this->y2 = 0;
	this->lados = 3;
	this->triangulo = CircleShape(1, 3);
	triangulo.setOutlineColor(Color::White);
	triangulo.setFillColor(Color::Black);
}

void Triangulo::SetStartPoint(int x, int y)
{
	this->x1 = x;
	this->y1 = y;
}

void Triangulo::SetEndPoint(int x, int y)
{
	this->x2 = x;
	this->y2 = y;
	this->triangulo.setPosition(this->x1, this->y1);

}

void Triangulo::SetHiden()
{
	this->hiden = false;
}
void Triangulo::ModColor(Color a)
{
	triangulo.setFillColor(a);
}

void Triangulo::ModPosition(int x, int y)
{
	triangulo.setPosition(x, y);
}

int Triangulo::GetDistance()
{
	int distancia = 0;
	distancia = sqrt((pow(x2 - x1, 2) + pow(y2 - y1, 2)));
	return distancia;
}

bool Triangulo::GetHiden()
{
	return this->hiden;
}

CircleShape Triangulo::GetTriangulo()
{
	triangulo.setOutlineThickness(2);
	triangulo.setRadius(GetDistance() / 2);
	triangulo.setPointCount(lados);

	return triangulo;
}