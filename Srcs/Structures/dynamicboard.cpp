#include "../../Headers/structure.h"
#include <iostream>
#include <vector>


/*----Structure dynamicboard----*/

//PRIVATE
#pragma region PRIVATE

	//PRIVATE FUNCTIONS

	//calls allocation functions
	void dynamicboard::allocate_data_sets(int grid[9][9])
	{
		for (int i = 0; i < 9; i++)
		{
			row[i].memory_handler(grid, i);

			column[i].memory_handler(grid, i);

			sqaure[i].memory_handler(grid, i);
		}
	}

	//checks a row column or sqaure
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
				if (*sqaure[index].slot[i] == target)
					check += 1;
			}
			break;
		}
		return check;
	}


#pragma endregion

//PUBLIC
#pragma region PUBLIC

	//PUBLIC CONSTRUCTOR
	dynamicboard::dynamicboard(const int inp[9][9])
	{
		for (int x = 0; x < 9; x++)
			for (int y = 0; y < 9; y++)
				grid[y][x] = inp[y][x];

		allocate_data_sets(grid);
	}


	//PUBLIC FUNCTIONS

	//fill functions
	
	//fills row[i] with inp
	void dynamicboard::fill(char structure, int i, int inp)
	{
		switch (structure)
		{
			case 'r':
				for (int slot = 0; slot < 9; slot++)
					*row[i].slot[slot] = inp;
				break;
			case 'c':
				for (int slot = 0; slot < 9; slot++)
					*column[i].slot[slot] = inp;
				break;
			case 's':
				for (int slot = 0; slot < 9; slot++)
					*sqaure[i].slot[slot] = inp;
				break;
		}
	}

	//print functions
	
	void dynamicboard::print_set(char structure, int i)
	{
		switch (structure)
		{
		case 'r':
			std::cout << *row[i].slot[0];
			for (int slot = 1; slot < 9; slot++)
				std::cout << ", " << *row[i].slot[slot];
			std::cout << '\n';
			break;

		case 'c':
			std::cout << *column[i].slot[0];
			for (int slot = 1; slot < 9; slot++)
				std::cout << ", " << *column[i].slot[slot];
			std::cout << '\n';
			break;

		case 's':
			std::cout << *sqaure[i].slot[0];
			for (int slot = 1; slot < 9; slot++)
				std::cout << ", " << *sqaure[i].slot[slot];
			std::cout << '\n';
			break;
		}
	}

	//print board to screen
	void dynamicboard::print()
	{
		for (int x = 0; x < 9; x += 3)//iterate rows
		{
			for (int xx = 0; xx < 3; xx++)//iterate rows in sets of 3
			{
				for (int y = 0; y < 9; y += 3)//iterate slots
				{
					std::cout << grid[xx + x][y];//happens before sets of 3 (prints first character)
					for (int yy = 1; yy < 3; yy++)//iterate rows:slots in sets of 3
					{
						std::cout << ", " << grid[xx + x][yy + y];//prints sencond two with commas and spacing
					}
					std::cout << "    ";//happens after every 3 e.g. 1, 2, 3, *thing*
				}
				std::cout << '\n';//happens after every row
			}
			std::cout << '\n';//happens after every 3 rows
		}
	}


	//check functions
	
	//checks every row, column and sqaure for repeats of the same number
	bool dynamicboard::check_correctness()
	{
		const char str[] = "rcs";

		for (int i = 0; i < 3; i++)//iterates rows, columns and sqaures
		{
			for (int structure_i = 0; structure_i < 9; structure_i++)//iterates through 9 of each structure
			{
				for (int check_target = 1; check_target <= 9; check_target++)//iterates through each number check
				{
					if (check(str[i], structure_i, check_target) > 1)
					{
						std::cout << str[i] << ' ' << structure_i << ' ' << check_target << '\n';
						return false;
					}
				}
			}
		}
		return true;
	}


#pragma endregion