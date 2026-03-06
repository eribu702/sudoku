#include "../../Headers/structure.h"
#include <iostream>
#include <vector>


/*----Structure Sudokuboard----*/

//PRIVATE


void Sudokuboard::assign_memory()
{
	/*assigns slots their memory addresses and makes sure numbers are within range*/
	for (int y = 0; y < 9; y++)//iterate rows & sqaure structures
	{
		//assign sqaure information
		square[y].memory_handler(grid, y);

		for (int x = 0; x < 9; x++)//iterate slots
		{
			//assign row and column information
			row[y].slot[x] = &grid[y][x];
			column[y].slot[x] = &grid[x][y];

			//assign number information
			number[y][x].slot = &grid[y][x];
			number[y][x].row = &row[y];
			number[y][x].column = &column[x];
			number[y][x].square = &square[(x / 3) + ((y / 3) * 3)];
		}
		
		if (!range_check(y))//checks no numbers above or below 0-9
			return;
	}

	//checks that there is only one of each number per row
	if (!check_correct())
		return;
}

//PUBLIC

//CONTSRUCTOR
Sudokuboard::Sudokuboard(const int inp[9][9])
{//copies inp into grid[][]
	for (int x = 0; x < 9; x++)
		for (int y = 0; y < 9; y++)
			grid[y][x] = inp[y][x];

	assign_memory();
}


//PUBLIC FUNCTIONS

//PRINT FUNCTIONS

//prints a row, column or square's contents
void Sudokuboard::print_set(char structure, int i)
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
		std::cout << *square[i].slot[0];
		for (int slot = 1; slot < 9; slot++)
			std::cout << ", " << *square[i].slot[slot];
		std::cout << '\n';
		break;
	}
}

//print sudoku board to screen
void Sudokuboard::print()
{
	for (int y = 0; y < 9; y += 3)
	{
		for (int y2 = 0; y2 < 3; y2++)
		{
			for (int x = 0; x < 9; x += 3)
			{
				std::cout << grid[y + y2][x];//first number in sets of three

				for (int x2 = 1; x2 < 3; x2++)
					std::cout << ", " << grid[y + y2][x + x2];//next two

				std::cout << "   ";//spacing between squares
			}
			std::cout << '\n';//end of rows
		}
		std::cout << '\n';//every three rows
	}
}

//print number structures to screen
void Sudokuboard::print_numbers()
{
	for (int y = 0; y < 9; y += 3)
	{
		for (int y2 = 0; y2 < 3; y2++)
		{
			for (int x = 0; x < 9; x += 3)
			{
				std::cout << *number[y + y2][x].slot;//first number in sets of three

				for (int x2 = 1; x2 < 3; x2++)
					std::cout << ", " << *number[y + y2][x + x2].slot;//next two

				std::cout << "   ";//spacing between squares
			}
			std::cout << '\n';//end of rows
		}
		std::cout << '\n';//every three rows
	}
}