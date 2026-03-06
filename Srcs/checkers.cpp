#include "../Headers/structure.h"
#include <iostream>


/*----Structure Sudokuboard----*/


//Sudokuboard CHECKING FUNCTIONS


//PRIVATE

//checks a row column or square for target
int Sudokuboard::check_set(char structure, int index, int target)
{
	int check = 0;
	switch (structure)
	{
	case 'r':
		for (int i = 0; i < 9; i++)
		{
			if (*row[index].slot[i] == target)
				check += 1;
		}
		break;
	case 'c':
		for (int i = 0; i < 9; i++)
		{
			if (*column[index].slot[i] == target)
				check += 1;
		}
		break;
	case 's':
		for (int i = 0; i < 9; i++)
		{
			if (*square[index].slot[i] == target)
				check += 1;
		}
		break;
	}
	return check;
}


//ensures there is no repeats of numbers in rows
bool Sudokuboard::check_correct()
{
	const char str[] = "rcs";

	for (int group = 0; group < 3; group++)//iterates rows, columns and squares
	{
		for (int set = 0; set < 9; set++)//iterates through 9 of each structure
		{
			for (int target = 1; target <= 9; target++)//iterates through each number check (1 - 9)
			{
				if (check_set(str[group], set, target) > 1)
				{
					switch (str[group])
					{
						case 'r':
							std::cout << "Row ";
							break;
						case 'c':
							std::cout << "Column ";
							break;
						case 's':
							std::cout << "Sqaure ";
					}
					std::cout << set + 1 << "has more than one" << target << "'s!\n";
					return false;
				}
			}
		}
	}
	return true;
}
