#include "Paint.h"
Paint::Paint(int x, int y)
{
	
	this->fps = 60; 
	this->pen_tool = false;
	this->fill_tool = false;
	this->eraser_tool = false;
	this->selector_tool = false;
	this->poligon_tool = false;
	window = new RenderWindow(VideoMode(x,y),"PAINT");
	window->setFramerateLimit(this->fps);
	this->pen = CircleShape(45, 360);
	this->prueba = CircleShape(45,4);
	this->prueba.setPosition(45, 80);
	this->event1 = new Event;
	this->fill_texture = new Texture;
	this->eraser_texture = new Texture;
	this->pen_texture = new Texture;
	this->selector_texture = new Texture;
	this->poligon_texture = new Texture;
	this->fill_sprite = new Sprite;
	this->eraser_sprite = new Sprite;
	this->pen_sprite = new Sprite;
	this->selector_sprite = new Sprite;
	this->poligon_sprite = new Sprite;
	this->reloj = new Clock;
	this->reloj2 = new Clock;
	this->tiempo = new Time;
	this->tiempo2 = new Time;
	this->color_selected = Color::White;
	fill_texture->loadFromFile("../res/Fill.png");
	eraser_texture->loadFromFile("../res/Eraser.png");
	pen_texture->loadFromFile("../res/Pen.png");
	selector_texture->loadFromFile("../res/Selection.png");
	poligon_texture->loadFromFile("../res/Poligon.png");
	fill_sprite->setTexture(*fill_texture);
	eraser_sprite->setTexture(*eraser_texture);
	pen_sprite->setTexture(*pen_texture);
	selector_sprite->setTexture(*selector_texture);
	poligon_sprite->setTexture(*poligon_texture);
	fill_sprite->setPosition(420, 0);
	eraser_sprite->setPosition(490, 0);
	pen_sprite->setPosition(560, 0);
	selector_sprite->setPosition(630, 0);
	poligon_sprite->setPosition(700, 0);
	fill_sprite->setScale(70.f / fill_sprite->getTexture()->getSize().x, 70.f / fill_sprite->getTexture()->getSize().y);
	eraser_sprite->setScale(70.f / eraser_sprite->getTexture()->getSize().x, 70.f / eraser_sprite->getTexture()->getSize().x);
	pen_sprite->setScale(70.f / pen_sprite->getTexture()->getSize().x, 70.f / pen_sprite->getTexture()->getSize().y);
	selector_sprite->setScale(70.f / selector_sprite->getTexture()->getSize().x, 70.f / selector_sprite->getTexture()->getSize().y);
	poligon_sprite->setScale(70.f / poligon_sprite->getTexture()->getSize().x, 70.f / poligon_sprite->getTexture()->getSize().y);

	
	//colores
	for (int i = 0; i < 20; i++)
	{
		this->colors[i] = RectangleShape();
		this->colors[i].setSize(Vector2f(70, 70));
	}

	this->colors[0].setFillColor(Color::Red);
	this->colors[1].setFillColor(Color::Blue);
	this->colors[2].setFillColor(Color::Green);
	this->colors[3].setFillColor(Color::Cyan);
	this->colors[4].setFillColor(Color::Yellow);
	this->colors[5].setFillColor(Color::White);

	for (int i = 0; i < 6; i++)
	{
		this->colors[i].setPosition(70 * i, 0);
	}
	this->poligono = Poligono();
	PaintLoop();
}

void Paint::Draw()
{
	if (selector_tool == true)
	{
		window->clear();
	}
	
	if (pen_tool == true)
	{
		window->draw(pen);
	}

	
	for (int i = 0; i < 6; i++)	
	{
		window->draw(colors[i]);
	}
	window->draw(*poligon_sprite);
	window->draw(*fill_sprite);
	window->draw(*pen_sprite);
	window->draw(*eraser_sprite);
	window->draw(*selector_sprite);
	window->draw(prueba);
	
	window->display();
	
}

void Paint::PaintLoop()
{
	while (window->isOpen())
	{
		*tiempo = reloj->getElapsedTime();
		if (tiempo->asSeconds() > 1 / fps)
		{
			ProcessMouse();
			ProcessEvent();
			Draw();
			reloj->restart();
		}
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
				ProcessCollision();
				//Opcion para dibujar punto por punto
				if (fill_tool == true)
				{
					if (Mouse::isButtonPressed(Mouse::Left))
					{
						FillCollision();
						window->draw(pen);
					}
				}
				if (poligon_tool == true)
				{
					poligono.SetStartPoint(position_mouse.x, position_mouse.y);
					cout << position_mouse.x << "," << position_mouse.y << endl;
				}
			}
			break;

		case Event::MouseButtonReleased:
			if (event1->key.code==Mouse::Left)
			{
				if (poligon_tool == true)
				{
					poligono.SetEndPoint(position_mouse.x, position_mouse.y);
					cout << position_mouse.x << "," << position_mouse.y << endl;
					window->draw(poligono.GetPoligono());
				}
			}

		case Event::MouseMoved:

			//Opcion de dibujo libre
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (eraser_tool == true)
				{
					pen.setFillColor(color_selected);
					pen.setPosition(Vector2f(position_mouse));
					window->draw(pen);
				}

				if (pen_tool == true)
				{
					pen.setFillColor(color_selected);
					*tiempo2 = reloj2->getElapsedTime();
						if (tiempo2->asSeconds() > 1 / fps)
						{
							pen.setPosition(Vector2f(position_mouse));
							
							*tiempo2 = reloj2->restart();
						}
				}

				if (selector_tool == true)
				{
					
						SelectorCollision();
					
				}
			}
			
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

void Paint::ProcessCollision()
{
	//Analiza si las intereacciones entre los objetos y el mouse
	FloatRect boxmouse(Vector2f(position_mouse), { 10,10 });
	if (pen_sprite->getGlobalBounds().intersects(boxmouse))
	{
		pen_tool = true;
		fill_tool = false;
		eraser_tool = false;
		selector_tool = false;
		poligon_tool = false;
	}
	if (fill_sprite->getGlobalBounds().intersects(boxmouse))
	{
		pen_tool = false;
		fill_tool = true;
		eraser_tool = false;
		selector_tool = false;
		poligon_tool = false;
		cout << "Fill tool" << endl;
	}
	if (eraser_sprite->getGlobalBounds().intersects(boxmouse))
	{
		pen_tool = false;
		fill_tool = false;
		eraser_tool = true;
		selector_tool = false;
		poligon_tool = false;
		color_selected = Color::Black;
	}
	if (selector_sprite->getGlobalBounds().intersects(boxmouse))
	{
		pen_tool = false;
		fill_tool = false;
		eraser_tool = false;
		selector_tool = true;
		poligon_tool = false;
		cout << "Selector" << endl;
	}
	if (poligon_sprite->getGlobalBounds().intersects(boxmouse))
	{
		pen_tool = false;
		fill_tool = false;
		eraser_tool = false;
		selector_tool = false;
		poligon_tool = true;
	}
	if (colors[0].getGlobalBounds().intersects(boxmouse))
	{
		color_selected = Color::Red;
	}
	if (colors[1].getGlobalBounds().intersects(boxmouse))
	{
		color_selected = Color::Blue;
	}
	if (colors[2].getGlobalBounds().intersects(boxmouse))
	{
		color_selected = Color::Green;
	}
	if (colors[3].getGlobalBounds().intersects(boxmouse))
	{
		color_selected = Color::Cyan;
	}
	if (colors[4].getGlobalBounds().intersects(boxmouse))
	{
		color_selected = Color::Yellow;
	}
	if (colors[5].getGlobalBounds().intersects(boxmouse))
	{
		color_selected = Color::White;
	}
}

void Paint::FillCollision()
{
	FloatRect boxmouse(Vector2f(position_mouse), { 10,10 });
	if (pen.getGlobalBounds().intersects(boxmouse))
	{
		cout << "fill" << endl;
		pen.setFillColor(color_selected);
		pen.setFillColor(color_selected);
	}
}

void Paint::SelectorCollision()
{
	FloatRect boxmouse(Vector2f(position_mouse), { 10,10 });
	
		if (prueba.getGlobalBounds().intersects(boxmouse))
		{
			prueba.setPosition(Vector2f(position_mouse));
			cout << "Moviendose" << endl;
		
		}
		
}
