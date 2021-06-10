#include "Tocka.h"
#include<iostream>
Tocka::Tocka()
{
}

void Tocka::define_start(int x, int y)
{
	start.x = x;
	start.y = y;

	current.x = x;
	current.y = y;

	define_wall();
}

void Tocka::define_end(int x, int y)
{
	end.x = x;
	end.y = y;
}

void Tocka::define_wall()
{
	wall.x = 1;
	wall.x1 = wall.x;
	wall.y = 20;
	wall.y1 = wall.y;

	wall.length_x = -1;
	wall.length_y = 10;
}

void Tocka::move()
{
	wall.x1 = wall.x;
	wall.y1 = wall.y;

	for (int i = 0; i <= wall.length_x; i++)
	{
		if (current.y == wall.y - 1)
		{
			if (current.x == wall.x || current.x == wall.x - 1)
			{
				current.x++;
				return;
			}
		}
		if (current.y == wall.y1 && current.x==wall.x-1)
		{
			if (wall.y+wall.length_x==40)
			{
				current.y--;
			}
			else
			{
				current.y++;
			}
			return;
		}		
		wall.y1++;
	}

	for (int i = 0; i <= wall.length_y; i++)
	{
		if (current.x == wall.x - 1)
		{
			if (current.y == wall.y || current.y == wall.y - 1)
			{
				current.y++;
				return;
			}
		}
		if (current.x == wall.x1 && current.y == wall.y - 1)
		{
			if (wall.x + wall.length_y == 20)
			{
				current.x--;
			}
			else
			{
				current.x++;
			}
			return;
		}

		wall.x1++;
	}

	if (current.y != end.y)
	{
		if (current.y > end.y)
		{
			current.y--;
		}
		else
		{
			current.y++;
		}
	}

	else if (current.x != end.x)
	{
		if (current.x > end.x)
		{
			current.x--;
		}
		else
		{
			current.x++;
		}
	}

	else if (current.x == end.x && current.y == end.y)
	{
		stop = true;
	}
}

void Tocka::draw()
{
	for (int i = 1; i <= stupac; i++)
	{
		for (int j = 1; j <= redak; j++)
		{
			if (draw_wall(i, j))
			{
				std::cout << "X";
			}

			else if (start.x == i && start.y == j)
			{
				std::cout << "A";
			}

			else if (current.x == i && current.y == j)
			{
				std::cout << "*";
			}

			else if (end.x == i && end.y == j)
			{
				std::cout << "B";
			}

			else
			{
				std::cout << "-";
			}
		}
		std::cout << std::endl;
	}
}

bool Tocka::get_stop()
{
	return stop;
}

bool Tocka::draw_wall(int i, int j)
{
	int length;
	int a;
	int b;
	if (wall.length_x> wall.length_y)
	{
		length = wall.length_x;
		a = wall.y;
		b = j;
		if (i!=wall.x)
		{
			return false;
		}
	}
	else
	{
		length = wall.length_y;
		a = wall.x;
		b = i;
		if (j != wall.y)
		{
			return false;
		}
	}

	for (int i = 0; i <=length; i++)
	{
		if (a==b)
		{
			return true;
		}
		a++;
	}
	return false;
}