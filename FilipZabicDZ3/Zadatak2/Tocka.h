#pragma once
#include<string>
struct  Start
{
	int x;
	int y;
};
struct End
{
	int x;
	int y;
};
struct Current
{
	int x;
	int y;
};

struct Wall
{
	int x, x1;
	int y, y1;
	int length_x;
	int length_y;
};

class Tocka
{
public:
	Tocka();
	void define_start(int x, int y);
	void define_end(int x, int y);
	void move();
	void define_wall();
	void draw();
	bool get_stop();
	bool draw_wall(int i, int j);
private:
	static const unsigned int stupac = 20;
	static const unsigned int redak = 40;
	Start start;
	End end;
	Current current;
	Wall wall;
	bool stop = false;
};

