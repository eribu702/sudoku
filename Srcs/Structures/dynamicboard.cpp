#include "../../Headers/structure.h"
#include <iostream>
#include <vector>


/*----Structure dynamicboard----*/

//PRIVATE
#pragma region PRIVATE

	//PRIVATE FUNCTIONS

	//returns copy of grid
	std::vector<std::vector<int>> dynamicboard::get_vector_board()
	{
		std::vector<std::vector<int>> grid_cpy(9, std::vector<int>(9));//create a 9x9 vector
		for (int y = 0; y < 9; y++)
		{
			for (int x = 0; x < 9; x++)
			{
				grid_cpy[x][y] = grid[x][y];
			}
		}
		return grid_cpy;
	}

	//calls allocation functions
	void dynamicboard::allocate_data_sets(int grid[9][9])
	{
		for (int i = 0; i < 9; i++)
			row[i].row_memory_handler(grid[i]);
	}

#pragma endregion

//PUBLIC
#pragma region PUBLIC

	//PUBLIC CONSTRUCTOR
	dynamicboard::dynamicboard(const int inp[9][9])
	{
		for (int b = 0; b < 9; b++)
		{
			for (int a = 0; a < 9; a++)
			{
				grid[a][b] = inp[a][b];
			}
		}
		allocate_data_sets(grid);
	}


	//PUBLIC FUNCTIONS

	//prints row of sudoku board
	void dynamicboard::print_row(int i)
	{
		row[i].print_r();
	}

	//print board to screen
	void dynamicboard::print_sudoku()
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

	//print vector board to screen
	void dynamicboard::print_vector_sudoku()
	{
		std::vector<std::vector<int>> gridcpy = get_vector_board();
		for (int y = 0; y < 9; y += 3)//iterate collums
		{
			for (int yy = 0; yy < 3; yy++)//iterate collums's sets of 3
			{
				for (int x = 0; x < 9; x += 3)//iterate rows
				{
					std::cout << gridcpy[x][y];//happens before sets of 3 (prints first character)
					for (int xx = 1; xx < 3; xx++)//iterate rows in sets of 3
					{
						std::cout << ", " << gridcpy[x + xx][y];//prints sencond two with commas and spacing
					}
					std::cout << "		";//happens after every 3 e.g. 1, 2, 3, *thing*
				}
				std::cout << '\n';//happens after every row
			}
			std::cout << '\n';//happens after every 3 rows
		}
	}

#pragma endregion