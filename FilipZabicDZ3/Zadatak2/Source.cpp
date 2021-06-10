#include<iostream>
#include<Windows.h>
#include"Tocka.h"

using namespace std;

int main()
{
	Tocka tocka;
	int x, y;

	cout << "A redak: ";
	cin >> x;
	cout << "A stupac: ";
	cin >> y;
	tocka.define_start(x, y);

	cout << "B redak: ";
	cin >> x;
	cout << "B stupac: ";
	cin >> y;
	tocka.define_end(x, y);

	while (!tocka.get_stop())
	{
		system("cls");

		tocka.draw();
		tocka.move();
		Sleep(50);
	}


	return 0;
}