#include <vector>
#include "Direction.h"
#pragma once

class Snake
{
public:
	Snake(int x, int y)
	{
		X = x;
		Y = y;
	}

	inline int get_x() { return X; }
	inline int get_y() { return Y; }
	inline Direction get_direction() { return Direction; }
	inline int get_size() { return Size; }

	inline void set_x(int x) { X = x; }
	inline void set_y(int y) { Y = y; }
	inline void set_direction(Direction direction) { Direction = direction; }

	inline void increment_size() { Size++; }
	void grow_snake();
	void move_snake();


private:
	int X;
	int Y;
	Direction Direction = down;
	int Size = 1;
	std::vector<std::pair<int, int>> body;

};