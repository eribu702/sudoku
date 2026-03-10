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
			grid[y][x].I = inp[y][x];

			//assign row and column and sqaure information
			row[y].position[x] = &grid[y][x].I;
			column[x].position[y] = &grid[y][x].I;
			square[y / 3 * 3 + (x / 3)].position[y % 3 * 3 + (x % 3)] = &grid[y][x].I;;

			//assign number information
			grid[y][x].row = &row[y];
			grid[y][x].column = &column[x];
			grid[y][x].square = &square[y / 3 * 3 + (x / 3)];

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
		std::cout << *row[i].position[0];
		for (int i = 1; i < 9; i++)
			std::cout << ", " << *row[i].position[i];
		std::cout << '\n';
		break;

	case 'c':
		std::cout << *column[i].position[0];
		for (int i = 1; i < 9; i++)
			std::cout << ", " << *column[i].position[i];
		std::cout << '\n';
		break;

	case 's':
		std::cout << *square[i].position[0];
		for (int i = 1; i < 9; i++)
			std::cout << ", " << *square[i].position[i];
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
				std::cout << grid[y + y2][x].I;//first number in sets of three

				for (int x2 = 1; x2 < 3; x2++)
					std::cout << ", " << grid[y + y2][x + x2].I;//next two

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

	for (int y = 0; y < 9; y += 3) {
		for (int y2 = 0; y2 < 3; y2++) {
			for (int x = 0; x < 9; x += 3) {
				if (grid[y + y2][x].I > 0)
					std::cout << '_';//first number in sets of three
				else
					std::cout << 0;

				for (int x2 = 1; x2 < 3; x2++) {
					if (grid[y + y2][x + x2].I > 0)
						std::cout << ", _";//next two
					else
						std::cout << ", " << 0;
				}
				std::cout << "   ";//spacing between squares
			}
			std::cout << '\n';//end of rows
		}
		std::cout << '\n';//every three rows
	}

	for (int i = 0; i < empty.size(); i++)
	{
		std::cout << i << ":   coord: " << empty[i]->coordinate;
		std::cout << "   Y: " << empty[i]->coordinate / 9;
		std::cout << "   X: " << empty[i]->coordinate % 9 << '\n';
	}
}