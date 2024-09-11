#include <iostream>
#include <conio.h>
#include "Snake.h"


void Snake::move_snake()
{
	int c = _getch();
	switch (c)
	{
	case 224:
		c = _getch();
		switch (c)
		{
		case 72:
			Direction = Direction::up;
			Y--;
			break;
		case 80:
			Direction = Direction::down;
			Y++;
			break;
		case 75:
			Direction = Direction::left;
			X--;
			break;
		case 77:
			Direction = Direction::right;
			X++;
			break;
		}
	}
}
void Snake::grow_snake() {
	//add tail depending on his size and make a for loop to display the whole snake instead of setting snake head directly in the array!
}