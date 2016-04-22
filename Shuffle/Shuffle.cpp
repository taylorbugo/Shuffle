// Shuffle.cpp : Defines the entry point for the console application.

// program designed to repeat over and over again, but not truly random, only psuedo random, would need better
// random number generator to make a more uniform distribution and non-repeatable sequence

#include "stdafx.h"

using namespace std;

int main()
{
	int input = 0;
	int *output = nullptr;
	int *storage = nullptr;
	int remaining = 0;
	int location = 0;
	int offset = 0;
	cout << "Welcome to Shuffle" << endl << "Please enter a positive integer > 1 or enter -1 to exit" << endl << ">";
	cin >> input;
	while (input != -1)
	{
		if (input > 1)
		{
			output = new int[input];
			for (int index = 0; index < input; index++)
			{
				output[index] = (index + 1);
			}
			remaining = input;
			while (remaining > 0)
			{
				// This is only pseudo random, there are better random number generators that can be created.
				// if the program is restarted and the same input is used, you will see the exact same sequence.
				location = (rand() % remaining);
				cout << output[location];
				if (remaining > 1)
				{
					cout << ", ";
				}
				else
				{
					cout << endl << endl;
				}
				if (remaining > 1)
				{
					storage = new int[remaining - 1];
					for (int place = 0; place < (remaining - 1); place++)
					{
						if (place == location)
						{
							offset = 1;
						}
						storage[place] = output[place + offset];
					}
				}
				delete[] output;
				output = storage;
				remaining--;
				offset = 0;
			}
		}
		else if (input != -1)
		{
			cout << "Invalid input!" << endl;
		}
		cout << "Please enter a positive integer > 1 or enter -1 to exit" << endl << ">";
		cin >> input;
	}
	cout << "Goodbye" << endl;
	return 0;
}

