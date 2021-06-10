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

class Tocka
{
public:
	Tocka();
	void define_start(int x, int y);
	void define_end(int x, int y);
	void move();
	void draw();
	bool get_stop();
private:
	static const unsigned int stupac = 20;
	static const unsigned int redak = 40;
	Start start;
	End end;
	Current current;
	bool stop= false;
};

