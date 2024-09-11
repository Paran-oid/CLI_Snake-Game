#pragma once

class Fruit
{
public:
	Fruit(int x, int y);

	inline int get_x() { return X; }
	inline int get_y() { return Y; }

	inline void set_x(int x) { X = x; }
	inline void set_y(int y) { Y = y; }

private:
	int X;
	int Y;
};

