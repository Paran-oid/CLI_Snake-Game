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

	inline void set_x(int x) { X = x; }
	inline void set_y(int y) { Y = y; }
	inline void set_direction(Direction direction) { Direction = direction; }


	void move_snake();


private:
	int X;
	int Y;
	Direction Direction = down;
	int Size = 1;
};