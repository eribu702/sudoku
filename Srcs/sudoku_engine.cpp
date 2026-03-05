#include "../Headers/sudoku.h"

void sudoku_engine(const int grid[9][9])
{
	dynamicboard sudoku(grid);

	sudoku.check_correctness();

	sudoku.count_zeroes();
}