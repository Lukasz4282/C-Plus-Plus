#include "pch.h"
#include <iostream>

using namespace std;

void hanoi(int n, int start, int finish, int temp);

int main()
{
	int length;
	cout << "Please enter the size of the pyramid: ";
	cin >> length;

	hanoi(length, 1, 3, 2);
}

void hanoi(int n, int start, int finish, int temp)
{
	if (n == 1)
		cout << "Move top disk from pole " << start << " to top of pole " << finish << endl;
	else
	{
		hanoi(n - 1, start, temp, finish);
		cout << "Move top disk from pole " << start << " to top of pole " << finish << endl;
		hanoi(n - 1, temp, finish, start);
	}
}
