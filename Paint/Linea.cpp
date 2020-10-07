#include "Linea.h"

Linea::Linea() {
	this->vector1 = Vector2f(0, 0);
	this->vector2 = Vector2f(0, 0);
}

void Linea::SetStartPoint(int x, int y) {
	this->vector1 = Vector2f(x, y);
	cout << "Coordenada 1" << endl;
}

void Linea::SetEndPoint(int x, int y) {
	this->vector2 = Vector2f(x, y);
	cout << "Coordenada 2" << endl;
}

/*Vertex Linea::GetLinea() {
	Vertex line[] = {
		Vertex(this->vector1, this->vector2)
	};
	//return draw(line, 2, Lines);
}*/