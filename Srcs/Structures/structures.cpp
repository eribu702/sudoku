#include "../../Headers/sudoku.h"
#include <vector>
#include <iostream>

//STRUCTURES
/*------------------------------*/
#pragma region STRUCTURES

//Declarations
#pragma region Declarations
/*----GridRow----*/
//private
void row_memory_handler(int row[9]);
void print_r();
//public

/*----Sudoku Dynamic Board----*/
//private
std::vector<std::vector<int>> get_vector_board();
void allocate_data_sets(int grid[9][9]);
//public
void print_row(int i);
void print_sudoku();
void print_vector_sudoku();
#pragma endregion



/*----Sudoku Row----*/
#pragma region Sudoku Row
struct gridrow
{
	//FRIENDS
	friend struct dynamicboard;
private:
	//CONTRUCTOR (private)

	//PRIVATE RESOURCES

	int* row_slot[9];

	//PRIVATE FUNCTIONS
	void row_memory_handler(int row[9])
	{
		for (int i = 0; i < 9; i++)
		{
			row_slot[i] = &row[i];
		}
	}

	void print_r()
	{
		std::cout << *row_slot[0];
		for (int i = 1; i < 9; i++)
			std::cout << ", " << *row_slot[i];
		std::cout << '\n';
	}

public:
	//PUBLIC FUNCTIONS
};
#pragma endregion

/*----Sudoku Dynamic Board----*/
#pragma region Sudoku Dynamic Board
struct dynamicboard
{
	//FRIENDS
	friend struct gridrow;
public:
	//CONSTRUCTOR
	dynamicboard(const int inp[9][9])
	{
		for (int b = 0; b < 9; b++)
		{
			for (int a = 0; a < 9; a++)
			{
				grid[a][b] = inp[a][b];
			}

			allocate_data_sets(grid);
		}
	}

private:
	//PRIVATE RESOURCES

	int grid[9][9];
	gridrow row[9];


	//PRIVATE FUNCTIONS

	//returns copy of grid
	std::vector<std::vector<int>> get_vector_board()
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
	void allocate_data_sets(int grid[9][9])
	{
		for (int i = 0; i < 9; i++)
			row[i].row_memory_handler(grid[i]);
	}

public:
	//PUBLIC RESOURCES


	//PUBLIC FUNCTIONS

	void print_row(int i)
	{
		row[i].print_r();
	}

	//print board to screen
	void print_sudoku()
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
	void print_vector_sudoku()
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

};
#pragma endregion



#pragma endregion