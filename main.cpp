#include <SFML\Graphics.hpp>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iterator>




class Game_Unit
{
public:
	int island; // на каком острове находится
	sf::Time age; // возраст
	int x;     // координата x
	int y;	   // координата y
	sf::Texture image; // Изображение
	sf::Sprite view;   // Изображение



	Game_Unit(int x_new, int y_new,std::string name_of_image_new,  int isl) 
	{
		age = sf::Time(sf::seconds(0));
		x = x_new;
		y = y_new;
		image.loadFromFile(name_of_image_new);
		view.setTexture(image);
		view.setPosition(x, y);
		island = isl;
	}

	void setPosition(int x_new, int y_new)
	{
		view.setPosition(x, y);
	}
	void UpdatePosition()
	{
		view.setPosition(x, y);
	}

	void setImage(std::string name_of_image_new)
	{
		image.loadFromFile(name_of_image_new);
		view.setTexture(image);
	}

	~Game_Unit() {}

};

class Wolf : public Game_Unit
{
public:
	
	int gender;  // Пол: 1 - мальчик, 2 - девочка
	int fullness; // Сытость



	Wolf(int x, int y, std::string name_of_image, int gender_new, int fullness_new, int isl) : Game_Unit(x, y, name_of_image,isl)
	{
		gender = gender_new;
		fullness = fullness_new;
		
	}

	
	void Move()
	{
		srand(time(0));
		int c = rand() % 4;
		if (c = 0)
		{
			if (x > 0)
				x = x - 50;
		}
		if (c = 1)
		{
			if (y > 0)
				y = y - 50;
		}
		if (c = 2)
		{
			if (x < 1250)
				x = x + 50;
		}
		if (c = 3)
		{
			if (y < 750)
				y = y + 50;
		}
		view.setPosition(x, y);
	}

	void TryToEat()
	{
		//TODO
	}

	void TryToDeath()
	{
		//TODO
	}

	void TryToMate()
	{
		//TODO
	}

	//TODO
};

class Hare : public Game_Unit
{
public:

	int gender;
	int fullness;



	Hare(int x, int y, std::string name_of_image, int gender_new, int fullness_new, int isl) : Game_Unit(x, y, name_of_image, isl)
	{
		gender = gender_new;
		fullness = fullness_new;
	}

	void Move()
	{
		age = age + sf::microseconds(10);
		srand(time(0));
		int c = rand() % 4;
		if (c = 0)
		{
			if (x > 0)
				x = x - 50;
		}
		if (c = 1)
		{
			if (y > 0)
				y = y - 50;
		}
		if (c = 2)
		{
			if (x < 1250)
				x = x + 50;
		}
		if (c = 3)
		{
			if (y < 750)
				y = y + 50;
		}
		view.setPosition(x, y);
	}

	void TryToEat()
	{
	}

	void TryToDeath()
	{
		//TODO
	}

	void TryToMate()
	{
		//TODO
	}

	
	//TODO
};

class Grass : public Game_Unit
{
public:

	int amount;

	Grass(int x, int y, std::string name_of_image, int amoun, int isl) : Game_Unit(x, y, name_of_image, isl)
	{
		amount = amoun;
	}

	void TryToGrow()
	{
		if (amount < 50)
		{
			amount++;
		}
		else
		{
			amount = 0;
		}
	}

};


class Island
{
public:
	
	int number;
	int x;
	int y;
	sf::RectangleShape island;
	int amount_of_wolfs_male;
	int amount_of_wolfs_female;
	int amount_of_hares_male;
	int amount_of_hares_female;
	sf::Text awf;
	sf::Text awm;
	sf::Text hwf;
	sf::Text hwm;



	Island(int num, int x_i, int y_i)
	{
		number = num;
		x = x_i;
		y = y_i;
		island.setFillColor(sf::Color(255, 161, 84));
		island.setSize(sf::Vector2f(50, 50));
		amount_of_wolfs_male = 0;
		amount_of_wolfs_female = 0;
		amount_of_hares_male = 0;
		amount_of_hares_female = 0;
		island.setPosition(x, y);
		
		awf.setString("W_F: " + std::to_string(amount_of_wolfs_female));
		awm.setString("W_M: " + std::to_string(amount_of_wolfs_male));
		hwm.setString("H_M: " + std::to_string(amount_of_hares_male));
		hwf.setString("H_F: " + std::to_string(amount_of_hares_female));
		awf.setCharacterSize(12);
		awm.setCharacterSize(12);
		hwm.setCharacterSize(12);
		hwf.setCharacterSize(12);
		awm.setFillColor(sf::Color::Black);
		awf.setFillColor(sf::Color::Black);
		hwm.setFillColor(sf::Color::Black);
		hwf.setFillColor(sf::Color::Black);

			
	}	

	void Update_statictic()
	{
		awf.setString("W_F: " + std::to_string(amount_of_wolfs_female));
		awm.setString("W_M: " + std::to_string(amount_of_wolfs_male));
		hwm.setString("H_M: " + std::to_string(amount_of_hares_male));
		hwf.setString("H_F: " + std::to_string(amount_of_hares_female));
	}
};


void Game_Tick(sf::RenderWindow * window, std::vector<Wolf> * wolfs, std::vector<Hare> * hares, std::vector<Grass> * grasses, std::vector<Island> *islands);

int menu(sf::RenderWindow * window)
{
	sf::Texture background_image; // Картинка, для фона меню
	background_image.loadFromFile("background_1300_800.png"); // Подгружаем картинку
	sf::Sprite background; // Элемент фона
	background.setTexture(background_image);
	(*window).clear(sf::Color::Green);
	sf::Text start;
	sf::Text field_editor;
	sf::Text back;
	sf::Text exit;

	sf::Font font;
	font.loadFromFile("Corner-Regular.otf");

	start.setFont(font);
	field_editor.setFont(font);
	exit.setFont(font);

	start.setString("START");
	field_editor.setString("FIELD EDITOR");
	exit.setString("EXIT");

	start.setColor(sf::Color::Black);
	field_editor.setColor(sf::Color::Black);
	exit.setColor(sf::Color::Black);

	start.setCharacterSize(40);
	field_editor.setCharacterSize(40);
	exit.setCharacterSize(40);

	start.setStyle(sf::Text::Bold);
	field_editor.setStyle(sf::Text::Bold);
	exit.setStyle(sf::Text::Bold);

	start.setPosition(100, 100);
	field_editor.setPosition(100, 150);
	exit.setPosition(100, 200);

	std::string defy = "hare_0.png";

	sf::Texture tro;
	tro.loadFromFile(defy);
	sf::Sprite tri;
	tri.setTexture(tro);
	tri.setPosition(0, 0);
	

	(*window).draw(background);
	(*window).draw(tri);
	(*window).draw(start);
	(*window).draw(field_editor);
	(*window).draw(exit);
	(*window).display();

	int counter_of_point = 0;
	while ((*window).isOpen())
	{

		sf::Event event;
		while ((*window).pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				(*window).close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
			{
				if (counter_of_point == 1)
					return 3;
				if (counter_of_point == 2)
					return 2;
				if (counter_of_point == 3)
					(*window).close();

			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
			{
				counter_of_point--;
				if (counter_of_point <= 0)
					counter_of_point = 3;

			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
			{
				counter_of_point++;
				counter_of_point = counter_of_point % 3;
				if (counter_of_point == 0)
					counter_of_point = 3;

			}
			if (counter_of_point == 1)
			{
				start.setColor(sf::Color::Yellow);
				field_editor.setColor(sf::Color::Black);
				exit.setColor(sf::Color::Black);
			}
				
			if (counter_of_point == 2)
			{
				start.setColor(sf::Color::Black);
				field_editor.setColor(sf::Color::Yellow);
				exit.setColor(sf::Color::Black);
			}
				
			if (counter_of_point == 3)
			{
				start.setColor(sf::Color::Black);
				field_editor.setColor(sf::Color::Black);
				exit.setColor(sf::Color::Yellow);
			}
		
				
			(*window).draw(background);
			(*window).draw(tri);
			(*window).draw(start);
			(*window).draw(field_editor);
			(*window).draw(exit);
			(*window).display();
		}
	}
}

void creator_of_island(sf::RenderWindow * window, std::vector<Wolf> * wolfs, std::vector<Hare> * hares, std::vector<Grass> * grasses, std::vector<Island> *islands, int numer);

void creator(sf::RenderWindow * window, std::vector<Wolf> * wolfs, std::vector<Hare> * hares, std::vector<Grass> * grasses, std::vector<Island> * islands)
{
	std::ofstream output("output.txt");
	output << "entered1" << std::endl;

	sf::Texture ocean_texture;
	ocean_texture.loadFromFile("ocean_color_1300_800.png");
	sf::Sprite ocean;
	ocean.setTexture(ocean_texture);

	sf::Text back;
	sf::Font font;
	font.loadFromFile("Corner-Regular.otf");
	back.setFont(font);
	back.setCharacterSize(40);
	back.setString("BACK");
	back.setColor(sf::Color::Black);
	back.setStyle(sf::Text::Bold);
	back.setPosition(1200, 5);
	(*window).clear();
	(*window).draw(ocean);
	(*window).draw(back);	
	(*window).display();

	int x, y; // координаты места под остров
	x = 0;
	y = 0;
	sf::RectangleShape candidat(sf::Vector2f(50, 50));
	candidat.setFillColor(sf::Color(25,40,255));
	candidat.setPosition(x, y);
	int need_to_go_back = 0;
	int num_isl = 0;
	while ((*window).isOpen())
	{

		sf::Event event;
		while ((*window).pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				(*window).close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
			{
				if (need_to_go_back == 1)
					return;
				if (need_to_go_back == 0)
				{
					need_to_go_back++;
					back.setColor(sf::Color::Yellow);
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
			{
				if (y > 0)
				{
					y = y - 50;
					candidat.setPosition(x, y);
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
			{
				if (y < 750)
				{
					y = y + 50;
					candidat.setPosition(x, y);
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
			{
				if (x < 1250)
				{
					x = x + 50;
					candidat.setPosition(x, y);
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
			{
				if (x > 0)
				{
					x = x - 50;
					candidat.setPosition(x, y);
				}
			}
			(*window).clear();
			(*window).draw(ocean);
			(*window).draw(candidat);
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::I)
			{
				
				(*islands).push_back(Island(num_isl,x,y));
				(*islands)[num_isl].Update_statictic();
				(*islands)[num_isl].island.setFillColor(sf::Color(255, 161, 84));
				(*islands)[num_isl].island.setPosition((*islands)[num_isl].x, (*islands)[num_isl].y);
				(*window).draw((*islands)[num_isl].island);
				(*islands)[num_isl].awf.setFont(font);
				(*islands)[num_isl].awm.setFont(font);
				(*islands)[num_isl].hwm.setFont(font);
				(*islands)[num_isl].hwf.setFont(font);
				(*islands)[num_isl].awm.setPosition((*islands)[num_isl].x, (*islands)[num_isl].y);
				(*islands)[num_isl].awf.setPosition((*islands)[num_isl].x, (*islands)[num_isl].y + 13);
				(*islands)[num_isl].hwm.setPosition((*islands)[num_isl].x, (*islands)[num_isl].y + 25);
				(*islands)[num_isl].hwf.setPosition((*islands)[num_isl].x, (*islands)[num_isl].y + 37);
				(*window).draw((*islands)[num_isl].awm);
				(*window).draw((*islands)[num_isl].awf);
				(*window).draw((*islands)[num_isl].hwm);
				(*window).draw((*islands)[num_isl].hwf);
				creator_of_island(window, wolfs, hares, grasses, islands, num_isl);
				num_isl++;
				
			}
			(*window).clear();
			(*window).draw(ocean);
			(*window).draw(candidat);
			for (int i = 0; i < (*islands).size(); i++)
			{

				(*islands)[i].Update_statictic();
				(*window).draw((*islands)[i].island);
				(*window).draw((*islands)[i].awm);
				(*window).draw((*islands)[i].awf);
				(*window).draw((*islands)[i].hwm);
				(*window).draw((*islands)[i].hwf);
			}
			(*window).draw(back);
			(*window).display();
		}
	}
}

void creator_of_island(sf::RenderWindow * window, std::vector<Wolf> * wolfs, std::vector<Hare> * hares, std::vector<Grass> * grasses, std::vector<Island> *islands, int numer)
{
	sf::Texture island_texture;
	island_texture.loadFromFile("island_color_1300_800.png");
	sf::Sprite island;
	island.setTexture(island_texture);

	sf::Text back;
	sf::Font font;
	font.loadFromFile("Corner-Regular.otf");
	back.setFont(font);
	back.setCharacterSize(40);
	back.setString("BACK");
	back.setColor(sf::Color::Black);
	back.setStyle(sf::Text::Bold);
	back.setPosition(1200, 5);
	(*window).clear();
	(*window).draw(island);
	(*window).draw(back);
	(*window).display();

	int x, y; // координаты места под остров
	x = 0;
	y = 0;
	sf::RectangleShape candidat(sf::Vector2f(50, 50));
	candidat.setFillColor(sf::Color(25, 40, 255));
	candidat.setPosition(x, y);
	int need_to_go_back = 0;
	int counter = 0;
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			(*grasses).push_back(Grass(i * 50, j * 50, "grass_0.png", 0, numer));
		}
	}
	while ((*window).isOpen())
	{

		sf::Event event;
		while ((*window).pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				(*window).close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
			{
				if (need_to_go_back == 1)
					return;
				if (need_to_go_back == 0)
				{
					need_to_go_back++;
					back.setColor(sf::Color::Yellow);
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
			{
				if (y > 0)
				{
					y = y - 50;
					candidat.setPosition(x, y);
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
			{
				if (y < 750)
				{
					y = y + 50;
					candidat.setPosition(x, y);
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
			{
				if (x < 1250)
				{
					x = x + 50;
					candidat.setPosition(x, y);
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
			{
				if (x > 0)
				{
					x = x - 50;
					candidat.setPosition(x, y);
				}
			}
			(*window).clear();
			(*window).draw(island);
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Z) //Волк
			{
				Wolf wolf_exm(x, y, "wolf_0.png", numer, 40, 1);
				/*(*wolfs).push_back(Wolf(x, y, "wolf_0.png", numer, 40, 1));
				(*islands)[numer].amount_of_wolfs_male++;
				(*wolfs).back().UpdatePosition();
				(*window).draw((*wolfs).back().view);*/
				(*wolfs).push_back(wolf_exm);
				(*islands)[numer].amount_of_wolfs_male++;
				wolf_exm.UpdatePosition();
				(*window).draw(wolf_exm.view);

			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::X) //Волчица
			{
				(*wolfs).push_back(Wolf(x, y, "wolf_0.png", numer, 40, 2));
				(*islands)[numer].amount_of_wolfs_female++;
				(*wolfs).back().UpdatePosition();
				(*window).draw((*wolfs).back().view);
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::C) //Заяц
			{
				(*hares).push_back(Hare(x, y, "hare_0.png", numer, 40, 1));
				(*islands)[numer].amount_of_hares_male++;
				(*hares).back().UpdatePosition();
				(*window).draw((*hares).back().view);
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::V) //Зайчиха
			{
				(*hares).push_back(Hare(x, y, "hare_0.png", numer, 40, 2));
				(*islands)[numer].amount_of_hares_female++;
				(*wolfs).back().UpdatePosition();
				(*window).draw((*wolfs).back().view);
			}
			for (int i = 0; i < (*wolfs).size(); i++)
			{
				(*window).draw((*wolfs)[i].view);
			}
			for (int i = 0; i < (*hares).size(); i++)
			{
				(*window).draw((*hares)[i].view);
			}
			(*window).draw(candidat);
			(*window).draw(back);
			(*window).display();
		}
	}
}

int ocean_game(sf::RenderWindow * window, std::vector<Island> * exp, std::vector<Wolf> * wolfs, std::vector<Hare> * hares, std::vector<Grass> * grasses)
{	std::ofstream output("output.txt");
	output << "entered" << std::endl;
	sf::Texture ocean_texture;
	ocean_texture.loadFromFile("ocean_color_1300_800.png");
	sf::Sprite ocean;
	ocean.setTexture(ocean_texture);

	sf::Font font;
	font.loadFromFile("Corner-Regular.otf");
	(*window).draw(ocean);	
	for (int i = 0; i < (*exp).size(); i++)
	{
		(*exp)[i].Update_statictic();
		(*exp)[i].island.setFillColor(sf::Color(255, 161, 84));
		(*exp)[i].island.setPosition((*exp)[i].x, (*exp)[i].y);
		(*window).draw((*exp)[i].island);
		(*exp)[i].awf.setFont(font);
		(*exp)[i].awm.setFont(font);
		(*exp)[i].hwm.setFont(font);
		(*exp)[i].hwf.setFont(font);
		(*exp)[i].awm.setPosition((*exp)[i].x, (*exp)[i].y);
		(*exp)[i].awf.setPosition((*exp)[i].x, (*exp)[i].y + 13);
		(*exp)[i].hwm.setPosition((*exp)[i].x, (*exp)[i].y + 25);
		(*exp)[i].hwf.setPosition((*exp)[i].x, (*exp)[i].y + 37);
		(*window).draw((*exp)[i].awm);
		(*window).draw((*exp)[i].awf);
		(*window).draw((*exp)[i].hwm);
		(*window).draw((*exp)[i].hwf);
	}
	(*window).display();
	while ((*window).isOpen())
	{
		Game_Tick(window, wolfs, hares, grasses, exp);
		sf::Event event;
		while ((*window).pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				(*window).close();
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i localPosition = sf::Mouse::getPosition(*window);
				int x_mouse = localPosition.x;
				int y_mouse = localPosition.y;
				for (int i = 0; i < (*exp).size(); i++)
				{
					if (((*exp)[i].x <= x_mouse) && ((*exp)[i].x + 50 >= x_mouse) && ((*exp)[i].y <= y_mouse) && ((*exp)[i].y + 50 >= y_mouse))
					{
						return i;
					}
				}
			}
			(*window).clear();
			(*window).draw(ocean);
			for (int i = 0; i < (*exp).size(); i++)
			{
				(*window).draw((*exp)[i].island);
				(*window).draw((*exp)[i].awm);
				(*window).draw((*exp)[i].awf);
				(*window).draw((*exp)[i].hwm);
				(*window).draw((*exp)[i].hwf);
			}
			(*window).display();
		}		
	}
}

void island_game(int number_of_island, sf::RenderWindow * window, std::vector<Island> * exp)
{
	int need_to_go_back = 0;
	sf::Text back;
	sf::Font font;
	font.loadFromFile("Corner-Regular.otf");
	back.setFont(font);
	back.setCharacterSize(40);
	back.setString("BACK");
	back.setColor(sf::Color::Black);
	back.setStyle(sf::Text::Bold);
	back.setPosition(1200, 5);
	sf::Texture island_texture;
	island_texture.loadFromFile("island_color_1300_800.png");
	sf::Sprite island;
	island.setTexture(island_texture);
	(*window).clear();
	(*window).draw(island);
	(*window).draw(back);
	(*window).display();
		
	while ((*window).isOpen())
	{

		sf::Event event;
		while ((*window).pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				(*window).close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Return)
			{
				if (need_to_go_back == 1)
					return;
				if (need_to_go_back == 0)
				{
					need_to_go_back++;
					back.setColor(sf::Color::Yellow);
				}
			}
			
			(*window).clear();
			(*window).draw(island);
			(*window).draw(back);
			(*window).display();
		}
	}

}

void Game_Tick(sf::RenderWindow * window, std::vector<Wolf> * wolfs, std::vector<Hare> * hares, std::vector<Grass> * grasses, std::vector<Island> *islands)
{
	for (int i = 0; i < (*grasses).size(); i++)
	{
		(*grasses)[i].TryToGrow();
	}

	for (int i = 0; i < (*wolfs).size(); i++)
	{	
		if (i >= (*wolfs).size())
		{
			break;
		}
		else
		{

			if ((*wolfs)[i].age > sf::seconds(10))
			{
				(*islands)[(*wolfs)[i].island].amount_of_wolfs_male--;
				(*wolfs).erase((*wolfs).begin() + i);
				i--;
				
			}
			else
			{
				for (int i = 0; i < (*hares).size(); i++)
				{
					if (((*wolfs)[i].x == (*hares)[i].x) && ((*wolfs)[i].y == (*hares)[i].y) && ((*wolfs)[i].island == (*hares)[i].island))
					{
						(*wolfs)[i].fullness = (*wolfs)[i].fullness + (*hares)[i].fullness;
						(*hares)[i].fullness = -1;
						(*wolfs)[i].Move();
					}
				}
			}
		}
	}

	for (int i = 0; i < (*hares).size(); i++)
	{
		if (i >= (*hares).size())
		{
			break;
		}
		else
		{
			if (((*hares)[i].fullness == -1) || ((*hares)[i].age > sf::seconds(10)))
			{
				(*islands)[(*hares)[i].island].amount_of_hares_male--;
				(*hares).erase((*hares).begin() + i);
				i--;
				
			}
			else
			{
				for (int i = 0; i < (*grasses).size(); i++)
				{
					if (((*grasses)[i].x == (*hares)[i].x) && ((*grasses)[i].y == (*hares)[i].y) && ((*grasses)[i].island == (*hares)[i].island))
					{
						if ((*grasses)[i].amount > 10)
						{
							(*hares)[i].fullness = 10 + (*hares)[i].fullness;
							(*grasses)[i].amount = (*grasses)[i].amount - 10;
						}
						else
						{
							(*hares)[i].fullness = (*grasses)[i].amount + (*hares)[i].fullness;
							(*grasses)[i].amount = 0;
						}
						(*hares)[i].Move();
					}
				}
			}
		}
	}
}

int main()
{
	int mode = 1; // Где находится пользователь: 1 - меню, 2 - редактор карты, 3 - океан, 4 - остров
	int number_of_island = 0; // Идентификатор острова, на который хочет отправиться игрок
	int x_screen = 1300;  // Размер окна по горизонтали.
	int y_screen = 800;   // Размер окна по вертикали.
	sf::RenderWindow window(sf::VideoMode(x_screen, y_screen), "Game_of_Life"); // Создаем окно, в котором все будет происходить
	window.setPosition(sf::Vector2i(0, 0)); // Помещаем окно в левый верхний угол
	window.setVerticalSyncEnabled(true); // Включаем вертикальную синхронизацию
	std::vector<Wolf> wolfs;
	std::vector<Hare> hares;
	std::vector<Grass> grasses;
	std::vector<Island> islands;

	/*islands.push_back(Island(1, 650, 400));
	wolfs.push_back(Wolf(0, 0, "wolf_0.png", 1, 40, 1));
	islands[0].amount_of_wolfs_male++;
	wolfs.push_back(Wolf(0, 150, "wolf_0.png", 1, 40, 2));
	islands[0].amount_of_wolfs_female++;
	wolfs.push_back(Wolf(100, 700, "wolf_0.png", 1, 40, 2));
	islands[0].amount_of_wolfs_female++;
	wolfs.push_back(Wolf(600, 0, "wolf_0.png", 1, 40, 1));
	islands[0].amount_of_wolfs_male++;
	wolfs.push_back(Wolf(1200, 750, "wolf_0.png", 1, 40, 1));
	islands[0].amount_of_wolfs_male++;
	wolfs.push_back(Wolf(500, 500, "wolf_0.png", 1, 40, 1));
	islands[0].amount_of_wolfs_male++;
	wolfs.push_back(Wolf(300, 400, "wolf_0.png", 1, 40, 1));
	islands[0].amount_of_wolfs_male++;
	
	hares.push_back(Hare(0, 100, "hare_0.png", 1, 40, 2));
	islands[0].amount_of_hares_female++;
	hares.push_back(Hare(0, 100, "hare_0.png", 1, 40, 1));
	islands[0].amount_of_hares_male++;
	hares.push_back(Hare(1000, 100, "hare_0.png", 1, 40, 1));
	islands[0].amount_of_hares_male++;
	hares.push_back(Hare(0, 100, "hare_0.png", 1, 40, 2));
	islands[0].amount_of_hares_female++;
	hares.push_back(Hare(50,400, "hare_0.png", 1, 40, 1));
	islands[0].amount_of_hares_male++;
	hares.push_back(Hare(50, 100, "hare_0.png", 1, 40, 1));
	islands[0].amount_of_hares_male++;
	hares.push_back(Hare(50, 150, "hare_0.png", 1, 40, 2));
	islands[0].amount_of_hares_female++;
	hares.push_back(Hare(550, 700, "hare_0.png", 1, 40, 1));
	islands[0].amount_of_hares_male++;
	hares.push_back(Hare(800, 100, "hare_0.png", 1, 40, 2));
	islands[0].amount_of_hares_female++;
	hares.push_back(Hare(700, 100, "hare_0.png", 1, 40, 2));
	islands[0].amount_of_hares_female++;
	hares.push_back(Hare(500, 100, "hare_0.png", 1, 40, 1));
	islands[0].amount_of_hares_male++;
	hares.push_back(Hare(500, 100, "hare_0.png", 1, 40, 2));
	islands[0].amount_of_hares_female++;
	hares.push_back(Hare(0, 700, "hare_0.png", 1, 40, 1));
	islands[0].amount_of_hares_male++;

	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			grasses.push_back(Grass(i * 50, j * 50, "grass_0.png", 0, 1));
		}
	}*/

	while (window.isOpen())
	{	
		if (mode == 1)
			mode = menu(&window);

		if (mode == 2)
		{
			creator(&window, &wolfs, &hares, &grasses, &islands); 
			mode = menu(&window);
		}
		
		if (mode == 3)
		{
			number_of_island = ocean_game(&window, &islands, &wolfs, &hares, &grasses);
			island_game(number_of_island, &window, &islands);
		}	
	}	
	return 0;
}
