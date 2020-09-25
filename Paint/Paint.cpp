#include "Paint.h"
Paint::Paint(int x, int y)
{
	this->fps = 60; 
	window = new RenderWindow(VideoMode(x,y),"PAINT");
	window->setFramerateLimit(this->fps);
	this->pen = CircleShape(5, 360);
	
	
	



	for (int i = 0; i < 20; i++)
	{
		this->colors[i] = RectangleShape();
		this->colors[i].setSize(Vector2f(30, 30));
	}
	this->colors[0].setFillColor(Color::Red);
	this->colors[1].setFillColor(Color::Blue);
	this->colors[0].setPosition(0, 0);
	this->colors[1].setPosition(30, 0);
	
	PaintLoop();
}

void Paint::Draw()
{
	for (int i = 0; i < 2; i++)	
	{
		window->draw(colors[i]);
	}
	Texture pen;
	if (!pen.loadFromFile("res/Pen.png"))
	{
		cout << "load file" << endl;
	}
	Sprite pensprite;
	pensprite.setTexture(pen);
	window->draw(pensprite);
	
	window->display();
	
}

void Paint::PaintLoop()
{
	while (window->isOpen())
	{
		Event event;
		while (window->pollEvent(event))
		{
			switch (event.type)
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

			case Event::MouseMoved:
				CircleShape circulo(5, 360);
				circulo.setRadius(40);
				circulo.setPosition(event.mouseMove.x, event.mouseMove.y);
				window->draw(circulo);

				break;
			
			}
		}
		
		Draw();
	}
}