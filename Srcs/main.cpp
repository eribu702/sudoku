#include "../Headers/structure.h"
#include <iostream>


int main(void)
{
	const int grid_input[9][9] = 
	{
		9, 0, 0,	1, 0, 0,	0, 0, 0,//0
		0, 0, 7,	2, 0, 0,	0, 0, 0,//1
		0, 0, 0,	3, 0, 0,	0, 0, 0,//2


		1, 2, 3,	4, 1, 0,	4, 5, 6,//3
		0, 0, 0,	5, 0, 0,	0, 0, 0,//4
		0, 0, 0,	6, 0, 9,	0, 0, 0,//5


		1, 2, 5,	7, 0, 0,	0, 0, 0,//6
		0, 1, 7,	8, 0, 0,	0, 2, 0,//7
		7, 4, 0,	9, 0, 0,	0, 0, 0,//8
	};//0  1  2     3  4  5     6  7  8

	dynamicboard sudoku(grid_input);
	
	sudoku.print_sudoku();
	sudoku.print_column(1);
	sudoku.print_column(3);
	sudoku.print_row(3);

	std::cout << "\n\n";

	sudoku.fill_column(3, 9);
	sudoku.fill_row(3, 9);
	sudoku.fill_sqaure(4, 5);

	std::cout << "\n\n";
	
	sudoku.print_column(3);
	sudoku.print_row(3);
	sudoku.print_sqaure(4);

	sudoku.print_sudoku();
}