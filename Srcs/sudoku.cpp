#include "../Headers/sudoku.h"
#include <vector>
#include <iostream>

//STRUCTURES
/*---------------------------------*/

/*----SUDOKU DYNAMIC BOARD----*/
dynamicboard::dynamicboard(const int inp[9][9]) {
	for (int b = 0; b < 9; b++)
	{
		for (int a = 0; a < 9; a++)
		{
			grid[a][b] = inp[a][b];
		}
	}
}

//returns copy of grid
std::vector<std::vector<int>> dynamicboard::vector_board()
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

//print board to screen
void dynamicboard::print_sudoku()
{
	for (int y = 0; y < 9; y += 3)//iterate collums
	{
		for (int yy = 0; yy < 3; yy++)//iterate collums's sets of 3
		{
			for (int x = 0; x < 9; x += 3)//iterate rows
			{
				std::cout << grid[x][y];//happens before sets of 3 (prints first character)
				for (int xx = 1; xx < 3; xx++)//iterate rows in sets of 3
				{
					std::cout << ", " << grid[x + xx][y];//prints sencond two with commas and spacing
				}
				std::cout << "		";//happens after every 3 e.g. 1, 2, 3, *thing*
			}
			std::cout << '\n';//happens after every row
		}
		std::cout << '\n';//happens after every 3 rows
	}
}

//print vector board to screen
void dynamicboard::print_vector_board(std::vector<std::vector<int>> gridcpy)
{
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

///*----SUDOKU ROW----*/
//struct gridrow
//{
////FRIENDS
//friend class dynamicboard;
//private:
////Contructor (private)
//	gridrow(int* inp[9])
//	{
//		for (int i = 0; i < 9; i++)
//			row[i] = inp[i];
//	}
//
//	int* row[9];
//
//public:
//	
//
//};











//FUNCTIONS
/*---------------------------------*/
