#include <SFML\Graphics.hpp>
#include<Windows.h>
#include <fstream>
#include <string>




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



int menu()
{
	//TODO
}

int creator()
{
	//TODO
}

int ocean_game()
{
	//TODO
}

int island_game(int number_of_island)
{
	//TODO
}

int main()
{
	int mode = 1; // Где находится пользователь: 1 - меню, 2 - редактор карты, 3 - океан, 4 - остров
	int number_of_island = 0; // Идентификатор острова, на который хочет отправиться игрок
	int x_screen = 1500;  // Размер окна по горизонтали.
	int y_screen = 800;   // Размер окна по вертикали.
	sf::RenderWindow window(sf::VideoMode(x_screen, y_screen), "Game_of_Life"); // Создаем окно, в котором все будет происходить
	window.setPosition(sf::Vector2i(0, 0)); // Помещаем окно в левый верхний угол
	window.setVerticalSyncEnabled(true); // Включаем вертикальную синхронизацию
	
	while (window.isOpen())
	{	
		if (mode == 1)
			mode = menu();

		if (mode == 2);
		{
			creator();
			mode = menu(); 
		}

		if (mode == 3)
		{
			number_of_island = ocean_game();
			island_game(number_of_island);
		}
		
	}
	
	return 0;
}
