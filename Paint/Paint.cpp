#include "Paint.h"
Paint::Paint(int x, int y)
{
	this->fps = 60; 
	window = new RenderWindow(VideoMode(x,y),"PAINT");
	window->setFramerateLimit(this->fps);
	this->pen = CircleShape(5, 360);
	this->pen.setRadius(1);
	this->fill_texture = Texture();
	this->fill_sprite = Sprite();
	this->fill_texture.loadFromFile("./Fill.png");
	this->fill_sprite.setTexture(fill_texture);
	this->event1 = new Event;
	//colores
	for (int i = 0; i < 20; i++)
	{
		this->colors[i] = RectangleShape();
		this->colors[i].setSize(Vector2f(30, 30));
	}

	this->colors[0].setFillColor(Color::Red);
	this->colors[1].setFillColor(Color::Blue);
	this->colors[2].setFillColor(Color::Green);
	this->colors[3].setFillColor(Color::Cyan);
	this->colors[4].setFillColor(Color::Yellow);
	this->colors[5].setFillColor(Color::White);
	this->colors[0].setPosition(0, 0);
	this->colors[1].setPosition(30, 0);
	this->colors[2].setPosition(60, 0);
	this->colors[3].setPosition(90, 0);
	this->colors[4].setPosition(120, 0);
	this->colors[5].setPosition(150, 0);
	PaintLoop();
}

void Paint::Draw()
{
	for (int i = 0; i < 6; i++)	
	{
		window->draw(colors[i]);
	}
	
	window->draw(fill_sprite);
	window->draw(pen);
	window->display();
	
}

void Paint::PaintLoop()
{
	while (window->isOpen())
	{
		
		ProcessMouse();
		ProcessEvent();
		
		Draw();
	}
}

void Paint::ProcessEvent()
{
	//Procesa los clicks y movimientos
	while (this->window->pollEvent(*event1))
	{
		switch (event1->type)
		{
		case Event::Closed:
			window->close();
			break;

		case Event::MouseButtonPressed:

			if (Mouse::isButtonPressed(Mouse::Left))

			{
				ProcessCollsion();
				//Opcion para dibujar punto por punto

				pen.setRadius(30);
				pen.setPosition(Vector2f(position_mouse));
				
				
			}
		case Event::MouseMoved:

			//Opcion de dibujo libre

			//pen.setRadius(30);
			//pen.setPosition(Vector2f(position_mouse));
			
			break;
			 
		}
	

	}
}

void Paint::ProcessMouse()
{
	//obtiene la posicion del mouse de la ventana
	position_mouse = Mouse::getPosition(*window);
	position_mouse = (Vector2i)window->mapPixelToCoords(position_mouse);
}

void Paint::ProcessCollsion()
{
	//Analiza si las intereacciones entre los objetos y el mouse
	FloatRect boxmouse(Vector2f(position_mouse), { 10,10 });
	if (colors[0].getGlobalBounds().intersects(boxmouse))
	{
		pen.setFillColor(Color::Red);
		
	 }
	if (colors[1].getGlobalBounds().intersects(boxmouse))
	{
		pen.setFillColor(Color::Blue);

	}
	if (colors[2].getGlobalBounds().intersects(boxmouse))
	{
		pen.setFillColor(Color::Green);

	}
	if (colors[3].getGlobalBounds().intersects(boxmouse))
	{
		pen.setFillColor(Color::Cyan);

	}
	if (colors[4].getGlobalBounds().intersects(boxmouse))
	{
		pen.setFillColor(Color::Yellow);

	}
	if (colors[5].getGlobalBounds().intersects(boxmouse))
	{
		pen.setFillColor(Color::White);

	}
}