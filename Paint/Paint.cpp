#include "Paint.h"
#include "Triangulo.h"
Paint::Paint(int x, int y)
{
	
	this->fps = 60; 
	this->prueba = CircleShape(45);
	prueba.setPosition(45, 45);
	this->poligono_counter=0;
	this->triangle_counter = 0;
	this->rectangulo_counter=0;
	this->circulo_counter = 0;
	this->linea_counter = 0;
	this->pen_counter = 0;
	this->pen_radius=15;
	this->reloj = new Clock;
	this->reloj2 = new Clock;
	this->tiempo = new Time;
	this->tiempo2 = new Time;
	this->color_selected = Color::White;
	window = new RenderWindow(VideoMode(x, y), "PAINT");
	window->setFramerateLimit(this->fps);
	this->event1 = new Event;
	
	//TOOLS
	this->pen_tool = false;
	this->fill_tool = false;
	this->eraser_tool = false;
	this->selector_tool = false;
	this->poligon_tool = false;
	this->rectangle_tool = false;
	this->line_tool = false;
	this->circle_tool = false;
	this->triangle_tool = false;

	
	
	//CREATE TEXTURES
	this->fill_texture = new Texture;
	this->eraser_texture = new Texture;
	this->pen_texture = new Texture;
	this->selector_texture = new Texture;
	this->poligon_texture = new Texture;
	this->rectangle_texture = new Texture;
	this->line_texture = new Texture;
	this->circle_texture = new Texture;
	this->triangle_texture = new Texture;


	//CREATE SPRITES
	this->fill_sprite = new Sprite;
	this->eraser_sprite = new Sprite;
	this->pen_sprite = new Sprite;
	this->selector_sprite = new Sprite;
	this->poligon_sprite = new Sprite;
	this->rectangle_sprite = new Sprite;
	this->line_sprite = new Sprite;
	this->circle_sprite = new Sprite;
	this->triangle_sprite = new Sprite;
	


	//LOAD FILES
	fill_texture->loadFromFile("../res/Fill.png");
	eraser_texture->loadFromFile("../res/Eraser.png");
	pen_texture->loadFromFile("../res/Pen.png");
	selector_texture->loadFromFile("../res/Selection.png");
	poligon_texture->loadFromFile("../res/Poligon.png");
	rectangle_texture->loadFromFile("../res/Rectangle.png");
	line_texture->loadFromFile("../res/Line.png");
	circle_texture->loadFromFile("../res/Circle.png");
	triangle_texture->loadFromFile("../res/Triangle.png");

	//TEXTURES & SPRITES
	fill_sprite->setTexture(*fill_texture);
	eraser_sprite->setTexture(*eraser_texture);
	pen_sprite->setTexture(*pen_texture);
	selector_sprite->setTexture(*selector_texture);
	poligon_sprite->setTexture(*poligon_texture);
	rectangle_sprite->setTexture(*rectangle_texture);
	line_sprite->setTexture(*line_texture);
	circle_sprite->setTexture(*circle_texture);
	triangle_sprite->setTexture(*triangle_texture);

	//POSITIONS SPRITES
	fill_sprite->setPosition(70, 0);
	eraser_sprite->setPosition(140, 0);
	pen_sprite->setPosition(210, 0);
	selector_sprite->setPosition(280, 0);
	poligon_sprite->setPosition(350, 0);
	rectangle_sprite->setPosition(420, 0);
	line_sprite->setPosition(490, 0);
	circle_sprite->setPosition(560, 0);
	triangle_sprite->setPosition(630, 0);

	//SPRITES SACALE
	fill_sprite->setScale(70.f / fill_sprite->getTexture()->getSize().x, 70.f / fill_sprite->getTexture()->getSize().y);
	eraser_sprite->setScale(70.f / eraser_sprite->getTexture()->getSize().x, 70.f / eraser_sprite->getTexture()->getSize().x);
	pen_sprite->setScale(70.f / pen_sprite->getTexture()->getSize().x, 70.f / pen_sprite->getTexture()->getSize().y);
	selector_sprite->setScale(70.f / selector_sprite->getTexture()->getSize().x, 70.f / selector_sprite->getTexture()->getSize().y);
	poligon_sprite->setScale(70.f / poligon_sprite->getTexture()->getSize().x, 70.f / poligon_sprite->getTexture()->getSize().y);
	rectangle_sprite->setScale(70.f / rectangle_sprite->getTexture()->getSize().x, 70.f / rectangle_sprite->getTexture()->getSize().y);
	line_sprite->setScale(70.f / line_sprite->getTexture()->getSize().x, 70.f / line_sprite->getTexture()->getSize().y);
	circle_sprite->setScale(70.f / circle_sprite->getTexture()->getSize().x, 70.f / circle_sprite->getTexture()->getSize().y);
	triangle_sprite->setScale(70.f / triangle_sprite->getTexture()->getSize().x, 70.f / triangle_sprite->getTexture()->getSize().y);
	
	//COLORS
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
	this->colors[6].setFillColor(Color::Magenta);
	for (int i = 0; i < 7; i++)
	{
		this->colors[i].setPosition(0,70 * i);
	}

	//TOOL ARRAYS
	for (int i = 0; i < 100; i++)
	{
		this->poligonos[i] = Poligono();
		this->triangulo[i] = Triangulo();
		this->rectangulos[i] = Rectangulo();
		this->circulos[i] = Circulo();
		this->lineas[i] = Linea();

	}
	for (int i = 0; i < 1000; i++)
	{
		this->pen[i] = CircleShape(45, 360);
		this->pen[i].setOrigin(0, 0);
		this->pen[i].setFillColor(Color::Black);
		this->pen[i].setRadius(1);
	}

	PaintLoop();
}

void Paint::Draw()
{
	for (int i = 0; i < 100; i++)
	{
		if (poligonos[i].GetHiden() == false) {
			window->draw(poligonos[i].GetPoligono());
		}
		if (rectangulos[i].GetHiden() == false) {
			window->draw(rectangulos[i].GetRectangulo());	
		}
		if (circulos[i].GetHiden() == false) {
			window->draw(circulos[i].GetCirculo());
		}
		if (triangulo[i].GetHiden() == false) {

			window->draw(triangulo[i].GetTriangulo());
		}
		if (lineas[i].GetHiden() == false) {
			window->draw(lineas[i].linea, 2, Lines);
		}
	}
	for (int i = 0; i < 1000; i++)
	{
		window->draw(pen[i]);
	}
	for (int i = 0; i < 7; i++)	
	{
		window->draw(colors[i]);
	}
	window->draw(*poligon_sprite);
	window->draw(*fill_sprite);
	window->draw(*pen_sprite);
	window->draw(*eraser_sprite);
	window->draw(*selector_sprite);
	window->draw(*rectangle_sprite);
	window->draw(*line_sprite);
	window->draw(*circle_sprite);
	window->draw(*triangle_sprite);
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
		window->clear();
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
				ColorCollision();
				
				if (poligon_tool == true)
				{
					poligonos[poligono_counter].SetStartPoint(position_mouse.x, position_mouse.y);
					
				}
				if (rectangle_tool == true)
				{
					rectangulos[rectangulo_counter].SetStartPoint(position_mouse.x, position_mouse.y);
				}
				if (line_tool == true)
				{
					lineas[linea_counter].SetEndPoint(position_mouse.x, position_mouse.y);
					lineas[linea_counter].ModColor(color_selected);
					lineas[linea_counter].SetHiden();
					linea_counter++;
					for (int i = 0; i < linea_counter; i++)
					{
						cout << lineas[i].GetInfo() << endl << endl;
					}
					if (linea_counter == 100) 
					{
						linea_counter = 0;
					}
				}
				if (circle_tool == true)
				{
					circulos[circulo_counter].SetStartPoint(position_mouse.x, position_mouse.y);
				}
				if (triangle_tool == true)
				{
					triangulo[triangle_counter].SetStartPoint(position_mouse.x, position_mouse.y);
				}
				if (fill_tool==true)
				{
					FillCollision();
				}
			}
			break;

		case Event::MouseButtonReleased:
			if (event1->key.code==Mouse::Left)
			{
				if (poligon_tool == true)
				{
					
					poligonos[poligono_counter].SetEndPoint(position_mouse.x, position_mouse.y);
					poligonos[poligono_counter].SetHiden();
					poligono_counter++;
					if (poligono_counter==100)
					{
						poligono_counter = 0;
					}	
				}
				if (rectangle_tool == true)
				{
					
					rectangulos[rectangulo_counter].SetEndPoint(position_mouse.x, position_mouse.y);
					rectangulos[rectangulo_counter].SetHiden();
					rectangulo_counter++;
					for (int i = 0; i < rectangulo_counter; i++) 
					{
						cout << rectangulos[i].GetInfo() << endl<<endl;
					}
					if (rectangulo_counter==100)
					{
						rectangulo_counter = 0;
					}
				}
				if (circle_tool == true)
				{
					
					circulos[circulo_counter].SetEndPoint(position_mouse.x, position_mouse.y);
					circulos[circulo_counter].SetHiden();
					circulo_counter++;
					for (int i = 0; i < circulo_counter; i++)
					{
						cout << circulos[i].GetInfo() << endl << endl;
					}
					if (circulo_counter == 100)
					{
						circulo_counter = 0;
					}
				}
				if (triangle_tool == true)
				{
					
					triangulo[triangle_counter].SetEndPoint(position_mouse.x, position_mouse.y);
					triangulo[triangle_counter].SetHiden();
					triangle_counter++;
					for (int i = 0; i < triangle_counter; i++) 
					{
						cout << triangulo[i].GetInfo() << endl << endl;
					}
					if (triangle_counter == 100)
					{
						triangle_counter = 0;
					}
				}
			}
			break;

		case Event::MouseMoved:

			//Opcion de dibujo libre
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (eraser_tool == true)
				{
					pen[pen_counter].setRadius(pen_radius);
					pen[pen_counter].setPosition(Vector2f(position_mouse));
					pen[pen_counter].setFillColor(Color::Black);
					pen_counter++;
					if (pen_counter==1000)
					{
						pen_counter = 0;
					}
				}

				if (pen_tool == true)
				{
					pen[pen_counter].setRadius(pen_radius);
					pen[pen_counter].setPosition(Vector2f(position_mouse));
					pen[pen_counter].setFillColor(color_selected);
					pen_counter++;
					if (pen_counter == 1000)
					{
						pen_counter = 0;
					}
				}
				if (selector_tool == true)
				{

					SelectorCollision();

				}

			
			}
		
			
			break;

		case Event::EventType::KeyPressed:

			if (pen_tool==true)
			{
				if (Keyboard::Up == event1->key.code)
				{
					pen_radius++;
				}
				if (Keyboard::Down == event1->key.code)
				{
					pen_radius--;
				}
			}
			if (poligon_tool==true)
			{
				if (Keyboard::Up == event1->key.code)
				{
					poligonos[poligono_counter].AumentarLados();
					cout << "Lados del poligono:" << poligonos[poligono_counter].GetLados() << endl;
				}
				if (Keyboard::Down == event1->key.code)
				{
					poligonos[poligono_counter].DisminuirLados();
					cout << "Lados del poligono:" << poligonos[poligono_counter].GetLados()<<endl;
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
		rectangle_tool = false;
		line_tool = false;
		circle_tool = false;
		triangle_tool = false;
	}
	if (fill_sprite->getGlobalBounds().intersects(boxmouse))
	{
		pen_tool = false;
		fill_tool = true;
		eraser_tool = false;
		selector_tool = false;
		poligon_tool = false;
		rectangle_tool = false;
		line_tool = false;
		circle_tool = false;
		triangle_tool = false;
		
	}
	if (eraser_sprite->getGlobalBounds().intersects(boxmouse))
	{
		pen_tool = false;
		fill_tool = false;
		eraser_tool = true;
		selector_tool = false;
		poligon_tool = false;
		rectangle_tool = false;
		line_tool = false;
		circle_tool = false;
		triangle_tool = false;

	}
	if (selector_sprite->getGlobalBounds().intersects(boxmouse))
	{
		pen_tool = false;
		fill_tool = false;
		eraser_tool = false;
		selector_tool = true;
		poligon_tool = false;
		rectangle_tool = false;
		line_tool = false;
		circle_tool = false;
		triangle_tool = false;
	}
	if (poligon_sprite->getGlobalBounds().intersects(boxmouse))
	{
		pen_tool = false;
		fill_tool = false;
		eraser_tool = false;
		selector_tool = false;
		poligon_tool = true;
		rectangle_tool = false;
		line_tool = false;
		circle_tool = false;
		triangle_tool = false;
	}
	if (rectangle_sprite->getGlobalBounds().intersects(boxmouse))
	{
		pen_tool = false;
		fill_tool = false;
		eraser_tool = false;
		selector_tool = false;
		poligon_tool = false;
		rectangle_tool = true;
		line_tool = false;
		circle_tool = false;
		triangle_tool = false;
	}
	if (line_sprite->getGlobalBounds().intersects(boxmouse))
	{
		pen_tool = false;
		fill_tool = false;
		eraser_tool = false;
		selector_tool = false;
		poligon_tool = false;
		rectangle_tool = false;
		line_tool = true;
		circle_tool = false;
		triangle_tool = false;
	}
	if (circle_sprite->getGlobalBounds().intersects(boxmouse))
	{
		pen_tool = false;
		fill_tool = false;
		eraser_tool = false;
		selector_tool = false;
		poligon_tool = false;
		rectangle_tool = false;
		line_tool = false;
		circle_tool = true;
		triangle_tool = false;
	}
	if (triangle_sprite->getGlobalBounds().intersects(boxmouse))
	{
		pen_tool = false;
		fill_tool = false;
		eraser_tool = false;
		selector_tool = false;
		poligon_tool = false;
		rectangle_tool = false;
		line_tool = false;
		circle_tool = false;
		triangle_tool = true;
	}
}

void Paint::ColorCollision()
{
	FloatRect boxmouse(Vector2f(position_mouse), { 10,10 });
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
	if (colors[6].getGlobalBounds().intersects(boxmouse))
	{
		color_selected = Color::Magenta;
	}
}


void Paint::FillCollision()
{
	FloatRect boxmouse(Vector2f(position_mouse), { 10,10 });
	for (int i = 0; i < 10; i++)
	{
		if (poligonos[i].GetPoligono().getGlobalBounds().intersects(boxmouse))
		{
			poligonos[i].ModColor(color_selected);
		}
		if (triangulo[i].GetTriangulo().getGlobalBounds().intersects(boxmouse))
		{
			triangulo[i].ModColor(color_selected);
		}
		if (rectangulos[i].GetRectangulo().getGlobalBounds().intersects(boxmouse))
		{
			rectangulos[i].ModColor(color_selected);
		}
		if (circulos[i].GetCirculo().getGlobalBounds().intersects(boxmouse))
		{
			circulos[i].ModColor(color_selected);
		}
	}
}


void Paint::SelectorCollision()
{
	FloatRect boxmouse(Vector2f(position_mouse), { 10,10 });
		for (int i = 0; i < 10; i++)
		{
			
			if (rectangulos[i].GetRectangulo().getGlobalBounds().intersects(boxmouse))
			{
				rectangulos[i].ModPosition(position_mouse.x, position_mouse.y);
			}
			if (poligonos[i].GetPoligono().getGlobalBounds().intersects(boxmouse))
			{
				poligonos[i].ModPosition(position_mouse.x, position_mouse.y);
			}
			if (triangulo[i].GetTriangulo().getGlobalBounds().intersects(boxmouse))
			{
				triangulo[i].ModPosition(position_mouse.x, position_mouse.y);
			}
			/*if (circulos[i].GetCirculo().getGlobalBounds().intersects(boxmouse))
			{
				circulos[i].ModPosition(position_mouse.x, position_mouse.y);
			}*/
		}
		
}
	