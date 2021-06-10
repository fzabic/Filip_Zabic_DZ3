#include "Tocka.h"
#include<iostream>
Tocka::Tocka()
{
}

void Tocka::define_start(int x, int y)
{
	start.x = x;
	start.y	= y;

	current.x = x;
	current.y= y;
}

void Tocka::define_end(int x, int y)
{
	end.x = x;
	end.y = y;
}

void Tocka::move()
{
	if (current.y!=end.y)
	{
		if (current.y>end.y)
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
			if (start.x==i && start.y==j)
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