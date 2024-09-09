#pragma once
#include <iostream>
#include <vector>


class Container
{
public:
	Container(int x, int y)
	{
		Width = x;
		Height = y;

		Array.resize(Height, std::vector<char>(Width));

		initialize(x, y);
	}

	void initialize(int x, int y)
	{

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
	}
	void display_container()
	{
		for (int i = 0; i < Height; i++)
		{
			for (int j = 0; j < Width; j++)
			{
				std::cout << Array[i][j];
			}
			std::cout << std::endl;
		}
	}


	int get_width()
	{
		return Width;
	}
	int get_height()
	{
		return Height;
	}


	void set_width(int width)
	{
		Width = width;
	}
	void set_height(int height)
	{
		Height = height;
	}
private:
	int Width{};
	int Height{};
	std::vector<std::vector<char>> Array;
};

