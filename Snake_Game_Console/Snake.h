#include <vector>
#include "Direction.h"
#pragma once

class Snake
{
public:
	Snake(int x, int y);
	inline Direction get_direction() { return Direction; }
	inline int get_size() { return Size; }
	inline std::pair<int, int> get_coords(int i);

	inline void set_direction(Direction direction) { Direction = direction; }

	void grow_snake(std::pair<int, int> old_coords);
	std::pair<int, int> move_snake();

private:
	std::vector<std::pair<int, int>> body;
	Direction Direction = down;
	int Size = 1;
};