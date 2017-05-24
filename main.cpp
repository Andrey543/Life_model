#include <SFML\Graphics.hpp>
#include <Windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>




class Game_Unit
{
public:
	int island; // на каком острове находится
	sf::Time age; // возраст
	int x;     // координата x
	int y;	   // координата y
	sf::Texture image; // Изображение
	sf::Sprite view;   // Изображение



	Game_Unit(sf::Time age_new, int x_new, int y_new, std::string name_of_image_new, int isl)
	{
		age = age_new;
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



	Wolf(sf::Time age, int x, int y, std::string name_of_image, int gender_new, int fullness_new, int isl) : Game_Unit(age, x, y, name_of_image,isl)
	{
		gender = gender_new;
		fullness = fullness_new;
	}

	
	void Move(int direction)
	{
		srand(time(0));
		int c = rand() % 4;
		if (c = 0)
		{
			if (x > 0)
				x = x - 25;
		}
		if (c = 1)
		{
			if (y > 0)
				y = y - 25;
		}
		if (c = 2)
		{
			if (x < 1275)
				x = x + 25;
		}
		if (c = 3)
		{
			if (y < 775)
				y = y + 25;
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
private:

	int gender;
	int fullness;

public:

	Hare(sf::Time age, int x, int y, std::string name_of_image, int gender_new, int fullness_new, int isl) : Game_Unit(age, x, y, name_of_image, isl)
	{
		//TODO
	}

	void updateFullness(int meal)
	{
		//TODO
	}

	int getFullness()
	{
		//TODO
	}

	int ChoiceDirection()
	{
		//TODO
	}

	void Move(int direction)
	{
		//TODO
	}

	
	//TODO
};

class Grass : public Game_Unit
{
public:

	Grass(sf::Time age, int x, int y, std::string name_of_image, int fullness_new, int isl) : Game_Unit(age, x, y, name_of_image, isl)
	{
		//TODO
	}

	void updateFullness(int meal)
	{
		//TODO
	}

	int getFullness()
	{
		//TODO
	}

};




class Island
{
private:
	
	int number;
	int x;
	int y;
	sf::RectangleShape island;
	int amount_of_wolfs_male;
	int amount_of_wolfs_female;
	int amount_of_hares_male;
	int amount_of_hares_female;

public:

	Island(int num, int x_i, int y_i, int male_wolfs, int female_wolfs, int male_hares, int female_hares)
	{
		number = num;
		x = x_i;
		y = y_i;
		island.setFillColor(sf::Color(255, 161, 84));
		amount_of_wolfs_male = male_wolfs;
		amount_of_wolfs_female = female_wolfs;
		amount_of_hares_male = male_hares;
		amount_of_hares_female = female_hares;
	}

	int getAmountOfMaleWolfs()
	{
		return amount_of_wolfs_male;
	}

	int getAmountOfFemaleWolfs()
	{
		return amount_of_wolfs_female;
	}

	int getAmountOfMaleHares()
	{
		return amount_of_hares_male;
	}

	int getAmountOfFemaleHares()
	{
		return amount_of_hares_female;
	}


	void setAmountOfMaleWolfs(int number)
	{
		amount_of_wolfs_male = number;
	}

	void setAmountOfFemaleWolfs(int number)
	{
		amount_of_wolfs_female = number;
	}

	void setAmountOfMaleHares(int number)
	{
		amount_of_hares_male = number;
	}

	void setAmountOfFemaleHares(int number)
	{
		amount_of_hares_female = number;
	}
};



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

	
	(*window).draw(background);
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
			(*window).draw(start);
			(*window).draw(field_editor);
			(*window).draw(exit);
			(*window).display();
		}
	}
}

void creator(sf::RenderWindow * window)
{

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
	sf::RectangleShape candidat(sf::Vector2f(25, 25));
	candidat.setFillColor(sf::Color(25,40,255));
	candidat.setPosition(x, y);
	int need_to_go_back = 0;
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
					y = y - 25;
					candidat.setPosition(x, y);
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
			{
				if (y < 775)
				{
					y = y + 25;
					candidat.setPosition(x, y);
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
			{
				if (x < 1275)
				{
					x = x + 25;
					candidat.setPosition(x, y);
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
			{
				if (x > 0)
				{
					x = x - 25;
					candidat.setPosition(x, y);
				}
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left)
			{

			}
			(*window).clear();			
			(*window).draw(ocean);
			(*window).draw(candidat);
			(*window).draw(back);
			(*window).display();
		}
	}
}

int ocean_game(sf::RenderWindow * window)
{
	//TODO

	return 0;
}

int island_game(int number_of_island, sf::RenderWindow * window)
{
	//TODO

	return 0;
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


	
	while (window.isOpen())
	{	
		if (mode == 1)
			mode = menu(&window);

		if (mode == 2)
		{
			creator(&window);
			mode = menu(&window);
		}

		if (mode == 3)
		{
			number_of_island = ocean_game(&window);
			island_game(number_of_island, &window);
		}
		
			
		
		
	}
	
	return 0;
}
