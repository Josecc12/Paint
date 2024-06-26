#include "Circulo.h"
Circulo::Circulo()
{
	this->x1 = 0;
	this->x2 = 0;
	this->y1 = 0;
	this->y2 = 0;
	this->hiden = true;
	this->circulo = CircleShape();
	this->circulo.setFillColor(Color::Black);
	circulo.setOutlineColor(Color::White);
	circulo.setPointCount(360);
}

void Circulo::SetStartPoint(int x, int y)
{
	this->x1 = x;
	this->y1 = y;
}

void Circulo::SetEndPoint(int x, int y)
{
	this->x2 = x;
	this->y2 = y;
	this->circulo.setPosition(this->x1, this->y1);
}

void Circulo::SetHiden()
{
	this->hiden = false;
}
void Circulo::ModColor(Color a)
{
	circulo.setFillColor(a);
}

void Circulo::ModPosition(int x, int y)
{
	circulo.setPosition(x, y);
}


int Circulo::GetDistance()
{
	int distancia = 0;
	distancia = sqrt((pow(x2 - x1, 2) + pow(y2 - y1, 2)));
	return distancia;
}

bool Circulo::GetHiden()
{
	return this->hiden;
}

string Circulo::GetInfo() 
{
	string info = " ";
	float area = 0;
	area = (3.1416) * (pow((GetDistance()/2), 2));
	info += "Tipo de Objeto: Circulo \nPosicicion:" + to_string(circulo.getPosition().x) + "," + to_string(circulo.getPosition().y) + '\n';
	info += "Radio: " + to_string(GetDistance() / 2) = '\n';
	info +=	"Area: " + to_string(area);
	
	return info;
}

CircleShape Circulo::GetCirculo()
{
	circulo.setOutlineThickness(2);
	circulo.setRadius(GetDistance() / 2);
	return circulo;
}
