#include "../Headers/structure.h"
#include <iostream>


int main(void)
{
	const int grid_input[9][9] =
	{
		1, 2, 3,	4, 5, 6,	7, 8, 9,//0
		2, 3, 4,	5, 6, 7,	8, 9, 1,//1
		3, 4, 5,	6, 7, 8,	9, 1, 2,//2


		4, 5, 6,	7, 8, 9,	1, 2, 3,//3
		5, 6, 7,	8, 9, 1,	2, 3, 4,//4
		6, 7, 8,	9, 1, 2,	3, 4, 5,//5


		7, 8, 9,	1, 2, 3,	4, 5, 6,//6
		8, 9, 1,	2, 3, 4,	5, 6, 7,//7
		9, 1, 2,	3, 4, 5,	6, 7, 8,//8
	};//0  1  2     3  4  5     6  7  8


	dynamicboard grid(grid_input);

	grid.print_sudoku();

	std::cout << "\n\n\n";

	grid.print_row(5);

	return ;
}