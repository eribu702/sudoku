#include "../../Headers/structure.h"
#include <iostream>


/*----Structure dynamicboard----*/


//DYNAMICBOARD CHECKING FUNCTIONS


//PRIVATE

//checks a row column or square for target
int dynamicboard::check(char structure, int index, int target)
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
bool dynamicboard::range_check(int index)
{
	for (int slot_i = 0; slot_i < 9; slot_i++)
	{
		if (*row[index].slot[slot_i] < 0 || *row[index].slot[slot_i] > 9)
			return false;
	}
	return true;
}



//PUBLIC

//counts empties
void dynamicboard::count_zeroes()
{
	for (int structure_i = 0; structure_i < 9; structure_i++)
	{
		row[structure_i].zeroes = check('r', structure_i, 0);

		column[structure_i].zeroes = check('c', structure_i, 0);

		square[structure_i].zeroes = check('s', structure_i, 0);
	}
}

//ensures there is no repeats of numbers in rows, columns or squares and records number presence in structures
bool dynamicboard::check_correct()
{
	const char str[] = "rcs";
	int target_found;

	for (int i = 0; i < 3; i++)//iterates rows, columns and squares
	{
		for (int structure_i = 0; structure_i < 9; structure_i++)//iterates through 9 of each structure
		{
			for (int check_target = 1; check_target <= 9; check_target++)//iterates through each number check (1 - 9)
			{
				target_found = check(str[i], structure_i, check_target);

				if (target_found > 1)
				{
					std::cout << str[i] << ' ' << structure_i << ' ' << check_target << '\n';
					return false;
				}
				else if (target_found == 1)
				{
					number_present(str[i], structure_i, check_target);
				}
			}
		}
	}
	return true;
}

//checks that sudoku puzzle is correcly input and follows sudoku rules
bool dynamicboard::initial_check()
{
	//CHECKS THAT ALL NUMBERS ARE BETWEEN 0-9
	for (int iterator = 0; iterator < 9; iterator++)
	{
		if (!range_check(iterator))
		{
			std::cout << "Row " << iterator + 1 << " contains a number out of range! (0-9)\n";
			return false;
		}
	}
	//checks that there is only one of each number per row, column or square and records each numbers presence in structures
	if (!check_correct())
		return false;
	return true;
}