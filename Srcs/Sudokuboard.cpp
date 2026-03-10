#include "../Headers/structure.h"
#include <iostream>
#include <vector>



/*----Structure Sudoku----*/

//PRIVATE


//PUBLIC

//CONTSRUCTOR
Sudoku::Sudoku(const int inp[9][9])
{
	/*assigns slots their memory addresses and makes sure numbers are within range*/
	for (int y = 0; y < 9; y++)//iterate rows & sqaure structures
	{
		for (int x = 0; x < 9; x++)//iterate slots
		{//copies inp into grid[][]
			grid[y][x].slot = inp[y][x];

			//assign row and column and sqaure information
			row[y].slot[x] = &grid[y][x].slot;
			column[x].slot[y] = &grid[y][x].slot;
			square[y / 3 * 3 + (x / 3)].slot[y % 3 * 3 + (x % 3)] = &grid[y][x].slot;;

			//assign number information
			grid[y][x].row = &row[y];
			grid[y][x].column = &column[x];
			grid[y][x].square = &square[(x / 3) + ((y / 3) * 3)];

			check_info(y, x);
		}
	}
}


//PUBLIC FUNCTIONS

//PRINT FUNCTIONS

//prints a row, column or square's contents
void Sudoku::print_set(char structure, int i)
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
void Sudoku::print()
{
	for (int y = 0; y < 9; y += 3)
	{
		for (int y2 = 0; y2 < 3; y2++)
		{
			for (int x = 0; x < 9; x += 3)
			{
				std::cout << grid[y + y2][x].slot;//first number in sets of three

				for (int x2 = 1; x2 < 3; x2++)
					std::cout << ", " << grid[y + y2][x + x2].slot;//next two

				std::cout << "   ";//spacing between squares
			}
			std::cout << '\n';//end of rows
		}
		std::cout << '\n';//every three rows
	}
}



//prints all empty numbers using empty vector
void Sudoku::print_empties()
{
	std::cout << "There are " << empty.size() << " zeroes in this Sudoku grid.\n\n";
	for (int i = 0; i < empty.size(); i++)
	{
		int y = (empty[i]->coordinate / 9); int x = (empty[i]->coordinate % 9);
		std::cout << i + 1 << ' ' << y << ' ' << x << '\n';
	}

}