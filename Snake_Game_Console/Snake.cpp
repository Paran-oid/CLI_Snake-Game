#include <iostream>
#include <conio.h>
#include <vector>
#include "Snake.h"
#include "Container.h"

Snake::Snake(int x, int y)
{
	body.push_back(std::make_pair(x, y));
}

std::pair<int, int> Snake::get_coords(int i)
{
	return Snake::body[i];
}

std::pair<int, int> Snake::move_snake()
{
	int old_y = get_coords(0).first;
	int old_x = get_coords(0).second;

	for (int i = Size - 1; i > 0; i--)
	{
		//basically each one is assigned to the one before-hand
		body[i] = body[i - 1];
	}

	int head_y = old_y;
	int head_x = old_x;

	int c = _getch();
	switch (c)
	{
	case 224:
		c = _getch();
		switch (c)
		{
		case 72:
			Direction = Direction::up;
			head_y--;
			break;
		case 80:
			Direction = Direction::down;
			head_y++;
			break;
		case 75:
			Direction = Direction::left;
			head_x--;
			break;
		case 77:
			Direction = Direction::right;
			head_x++;
			break;
		}

		body[0].first = head_y;
		body[0].second = head_x;
	}

	std::pair<int, int> old_values;
	old_values.first = old_y;
	old_values.second = old_x;

	return old_values;
}
void Snake::grow_snake(std::pair<int, int> old_coords) {
	Size++;
	body.push_back(old_coords);
}