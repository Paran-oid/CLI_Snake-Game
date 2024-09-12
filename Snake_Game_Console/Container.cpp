#include <iostream>
#include <chrono>
#include <random>
#include "Container.h"

Container::Container(int width, int height) :
	Width(width),
	Height(height),
	MySnake(width / 2, height / 2),
	MyFruit(std::rand() % (width - 2) + 1, std::rand() % (height - 2) + 1)
{
	srand(static_cast<unsigned>(std::chrono::steady_clock::now().time_since_epoch().count()));
	std::srand(static_cast<unsigned>(std::time(nullptr)));
	Array.resize(Height, std::vector<char>(Width));
	initialize(width, height);
}
void Container::initialize(int x, int y)
{
	{
		int snake_x = MySnake.get_coords(0).second;
		int snake_y = MySnake.get_coords(0).first;

		int fruit_x = MyFruit.get_x();
		int fruit_y = MyFruit.get_y();

		if (firstTime)
		{
			if (fruit_x == snake_x && fruit_y == snake_y)
			{
				MyFruit.set_x(fruit_x + 1);
				MyFruit.set_y(fruit_y + 1);
			}
			started();
		}


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
		for (int i = 0; i < Width; i++)
		{
			Array[Height - 1][i] = '-';
		}

		Array[fruit_y][fruit_x] = '*';

		if ((snake_x < Width - 1 && snake_x > 0) && ((snake_y < Height - 1 && snake_y > 0)))
		{
			//if snake ate
			if (snake_x == fruit_x && snake_y == fruit_y)
			{
				MyFruit.set_x(std::rand() % (Width - 2) + 1);
				MyFruit.set_y(std::rand() % (Height - 2) + 1);
				fruit_x = MyFruit.get_x();
				fruit_y = MyFruit.get_y();
				Array[fruit_y][fruit_x] = '*';

				MySnake.grow_snake(SnakeOldCords);
				increment_score();
			}
			display_snake();
		}

		else
			std::exit(0);
	}
}
void Container::display_snake()
{
	for (int i = 0; i < MySnake.get_size(); i++)
	{
		int temp_x = MySnake.get_coords(i).first;
		int temp_y = MySnake.get_coords(i).second;
		Container::Array[temp_x][temp_y] = '0';
	}
}
void Container::display_container()
{
	std::system("cls");
	for (int i = 0; i < Width; i++)
	{
		if (i == Width / 4)
		{
			std::cout << "score is: " << Score;
		}
		else
		{
			std::cout << ' ';
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < Height; i++)
	{
		for (int j = 0; j < Width; j++)
		{
			std::cout << Array[i][j];
		}
		std::cout << std::endl;
	}
	SnakeOldCords = MySnake.move_snake();
}