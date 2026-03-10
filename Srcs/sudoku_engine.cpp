#include "../Headers/sudoku.h"

void sudoku_engine(const int grid[9][9])
{
	Sudoku sudoku(grid);
	sudoku.print();
	sudoku.print_empties(); 
}