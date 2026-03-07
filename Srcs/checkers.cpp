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


//catch out of range or repeats, returns false if empty number (0)
void Sudokuboard::check_info(const int y, const int x)
{
	// checks numbers are in range
	if (grid[y][x] < 0 || grid[y][x] > 9) {
		std::cout << "Row " << y + 1 << " has the number: " << *row[y].slot[x] << '\n';
		std::cout << "Make sure all numbers are between 0 & 9!";
		std::exit(0);
	}

	//checks not zero
	if (grid[y][x] == 0) {
		number[y][x].row->zeroes++;
		number[y][x].column->zeroes++;
		number[y][x].square->zeroes++;
		return;
	}
	
	const int num = grid[y][x] - 1;//to avoid indexing like this: filled[grid[y][x] - 1]
	bool fail = false;
	
	//ensures number doesn't already exist in structures
	if (number[y][x].row->filled[num] == true) {
		std::cout << "Row ";
		fail = true;
	} else if (number[y][x].column->filled[num] == true) {
		std::cout << "Column ";
		fail = true;
	} else if (number[y][x].square->filled[num] == true) {
		std::cout << "Square ";
		fail = true;
	} if (fail) {
		std::cout << y + 1 << " has more than one " << grid[y][x] << "'s!\n";
		std::exit(0);
	}

	//number not zero, out of range or already existing, assign infomation
	number[y][x].row->filled[num] = true;
	number[y][x].column->filled[num] = true;
	number[y][x].square->filled[num] = true;
	number[y][x].filled = true;
}