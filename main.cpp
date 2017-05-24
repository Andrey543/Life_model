#include <SFML\Graphics.hpp>
#include<Windows.h>
#include <fstream>
#include <string>


/*

class Game_Unit
{
protected:

	sf::Time age; // возраст
	int x;     // координата x
	int y;	   // координата y
	sf::Texture image; // Изображение
	sf::Sprite view;   // Изображение

public:

	Game_Unit(int age_new, int x_new, int y_new, std::string name_of_image_new)
	{
		//TODO
	}

	void setAge(int age_new)
	{
		//TODO
	}

	void setPosition(int x_new, int y_new)
	{
		//TODO
	}

	void setImage(std::string name_of_image_new)
	{
		//TODO
	}

	int getXPos()
	{
		return x;
	}

	int getYPos()
	{
		return y;
	}

	int getAge()
	{
		//TODO
	}
	//TODO
	~Game_Unit() {}

};

class Wolf : public Game_Unit
{
private:

	int gender;
	int fullness;

public:

	Wolf(int age, int x, int y, std::string name_of_image, int gender_new, int fullness_new) : Game_Unit(age, x, y, name_of_image)
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

class Hare : public Game_Unit
{
private:

	int gender;
	int fullness;

public:

	Hare(int age, int x, int y, std::string name_of_image, int gender_new, int fullness_new) : Game_Unit(age, x, y, name_of_image)
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

	Grass(int age, int x, int y, std::string name_of_image, int fullness_new) : Game_Unit(age, x, y, name_of_image)
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


*/
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

int creator(sf::RenderWindow * window)
{
	//TODO

	return 0;
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
