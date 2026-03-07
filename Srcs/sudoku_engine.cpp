#include "../Headers/sudoku.h"

void sudoku_engine(const int grid[9][9])
{
	Sudokuboard sudoku(grid);
	sudoku.print();
	sudoku.print_zeroes();
}