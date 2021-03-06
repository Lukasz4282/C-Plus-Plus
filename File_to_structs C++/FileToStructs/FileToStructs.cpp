#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

int main()
{
	const int SIZE = 50;
	int i = 0;
	struct Records
	{
		string firstname;
		string secondname;
		float test1mark;
		float midtestmark;
		float annualmark;
	};

	Records record[SIZE];

	fstream file;
	file.open("input.txt");

	if (file.is_open())
	{
		int recCount = 0;  // keep track of actual number of records

		// loop until we reach the end of file, or until we hit SIZE records,
		// whichever comes first
		while (!file.eof() || recCount > SIZE)
		{
			file >> record[recCount].firstname >> record[recCount].secondname
				>> record[recCount].test1mark >> record[recCount].midtestmark >> record[recCount].annualmark;

			cout << record[i].firstname << "  ";
			cout << record[i].secondname << " ";
			cout << record[i].test1mark << "  ";
			cout << record[i].midtestmark << "  ";
			cout << record[i].annualmark << "  " << endl;
			++recCount;
			i++;
		}

		

		// now recCount == 15 if you have 15 items.
	}

	else cout << "Unable to open file";
}