#pragma once
#include <iostream>
#include <vector>
#include "Snake.h"
#include "Fruit.h"

class Container
{
public:
	Snake MySnake;
	Fruit MyFruit;

	Container(int x, int y);
	void initialize(int x, int y);
	void display_container();
	void display_snake();

	inline int get_width() { return Width; }
	inline int get_height() { return Height; }
	inline void set_width(int width) { Width = width; };
	inline void set_height(int height) { Height = height; }
	inline void started() { firstTime = false; }


private:
	std::vector<std::vector<char>> Array;
	int Width{};
	int Height{};
	std::pair<int, int> SnakeOldCords{};
	bool firstTime = true;
};

