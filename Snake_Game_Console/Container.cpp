#include <iostream>
#include <random>
#include "Container.h"

Container::Container(int width, int height) :
	Width(width),
	Height(height),
	MySnake(width / 2, height / 2),
	MyFruit(std::rand() % width, std::rand() % height)
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));
	int fruitX = std::rand() % Width;
	int fruitY = std::rand() % Height;
	MyFruit = Fruit(fruitX, fruitY);

	Array.resize(Height, std::vector<char>(Width));
	initialize(width, height);
}
void Container::initialize(int x, int y)
{
	{
		int snake_x = MySnake.get_x();
		int snake_y = MySnake.get_y();

		int fruit_x = MyFruit.get_x();
		int fruit_y = MyFruit.get_y();

		for (int i = 0; i < Width; i++)
		{
			Array[0][i] = '-';
		}
		for (int i = 1; i < Height - 1; i++)
		{
			for (int j = 0; j < Width; j++)
			{
				if (j == 0 || j == Width - 1)
				{
					Array[i][j] = '|';
				}
				else
				{
					Array[i][j] = ' ';
				}
			}
		}

		if ((snake_x < Width - 1 && snake_x > 0))
			Array[snake_y][snake_x] = '0';
		else
			std::exit(0);

		Array[fruit_x][fruit_x] = '*';

		for (int i = 0; i < Width; i++)
		{
			Array[Height - 1][i] = '-';
		}
	}
}
void Container::display_container()
{
	std::system("cls");
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			std::cout << Array[i][j];
		}
		std::cout << std::endl;
	}
}