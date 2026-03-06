#include "../../Headers/structure.h"
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

//checks all rows for numbers out of 0-9 range, will return true if none found
bool Sudokuboard::range_check(int index)
{
	for (int slot_i = 0; slot_i < 9; slot_i++)
	{
		if (*row[index].slot[slot_i] < 0 || *row[index].slot[slot_i] > 9)
		{
			std::cout << "Row " << index + 1 << " contains a number out of range! (0-9)\n";
			return false;
		}
	}
	return true;
}



//PUBLIC

//ensures there is no repeats of numbers in rows
bool Sudokuboard::check_correct()
{
	const char str[] = "rcs";
	int target_found;

	for (int i = 0; i < 3; i++)//iterates rows, columns and squares
	{
		for (int structure_i = 0; structure_i < 9; structure_i++)//iterates through 9 of each structure
		{
			for (int check_target = 1; check_target <= 9; check_target++)//iterates through each number check (1 - 9)
			{
				if (check_set(str[i], structure_i, check_target) > 1)
				{
					switch (str[i])
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
					std::cout << structure_i + 1 << "has more than one" << check_target << "'s!\n";
					return false;
				}
			}
		}
	}
	return true;
}
