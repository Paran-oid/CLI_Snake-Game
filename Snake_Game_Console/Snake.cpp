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

	int c = _getch();
	int old_y = get_coords(0).first, head_y = get_coords(0).first;
	int old_x = get_coords(0).second, head_x = get_coords(0).second;
	switch (c)
	{
	case 224:
		c = _getch();
		switch (c)
		{
			switch (Direction)
			{
			case Direction::up:

			}
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

	if (Size > 1)
	{
		int l = 0;
		for (int r = 1; r < Size; r++)
		{
			if (body[r].first - body[l].first > 0)
			{
				body[l].first++;
			}
			else if (body[r].first - body[l].first < 0)
			{
				body[r].first--;
			}
			else if (body[r].second - body[l].second != 0)
			{
				body[r].second++;
			}
			else
			{
				body[r].second--;
			}
			l++;
		}
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