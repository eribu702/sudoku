#include "../../Headers/structure.h"
#include <iostream>
#include <vector>


/*----Structure dynamicboard----*/

//PRIVATE

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

//sets a substructure's num_present[found_num] to true if the number exists
void dynamicboard::number_present(char structure, int structure_i, int found_num)
{
	switch (structure)
	{
		case 'r':
			row[structure_i].num_present[found_num - 1] = true;
			break;
		case 'c':
			column[structure_i].num_present[found_num - 1] = true;
			break;
		case 's':
			sqaure[structure_i].num_present[found_num - 1] = true;
			break;
	}
	return;
}


//PUBLIC


//PUBLIC CONSTRUCTOR
dynamicboard::dynamicboard(const int inp[9][9])
{
	for (int x = 0; x < 9; x++)
		for (int y = 0; y < 9; y++)
			grid[y][x] = inp[y][x];

	allocate_data_sets(grid);
	if (!initial_check())
	{
		std::cout << "This puzzle was input wrong!\n";
		return;
	}
	count_zeroes();
}


//PUBLIC FUNCTIONS

//PRINT FUNCTIONS

//prints a row, column or sqaure's contents
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
					std::cout << ", " << grid[xx + x][yy + y];//prints sencond two with commas and spacing

				std::cout << "    ";//happens after every 3 e.g. 1, 2, 3, *thing*
			}
			std::cout << '\n';//happens after every row
		}
		std::cout << '\n';//happens after every 3 rows
	}
}