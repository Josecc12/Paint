#include "Paint.h"
Paint::Paint(int x, int y)
{
	this->fps = 45; 
	window = new RenderWindow(VideoMode(x,y),"PAINT");
	window->setFramerateLimit(this->fps);
	
	PaintLoop();
}

void Paint::Draw()
{
	window->draw(CircleShape(65));
	window->display();
	
}

void Paint::PaintLoop()
{
	while (window->isOpen())
	{
		Event event;
		while (window->pollEvent(event))
		{
			switch (event.type)//
			{
			case Event::Closed:
				window->close();
				break;

			case Event::MouseButtonPressed:
				cout << "se presiono el boton del mouse" << endl;
				switch (event.key.code)
				{
				case Mouse::Left:
					cout << "click izquierdo " << endl;
					break;
				case Mouse::Right:
					cout << "Click derecho" << endl;
					break;
				}
				break;

			case Event::MouseButtonReleased:
				switch (event.key.code)
				{
				case Mouse::Left:
					cout << "Click izquierdo soltado" << endl;
					break;
				}
				break;

			case Event::MouseWheelMoved:
				cout << "scroll del mouse" << endl;
				break;

			}
		}
		Draw();
	}
}