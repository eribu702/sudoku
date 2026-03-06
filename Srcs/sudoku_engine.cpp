#include "../Headers/sudoku.h"

void sudoku_engine(const int grid[9][9])
{
	Sudokuboard sudoku(grid);
	sudoku.print();
	
	for (int i = 0; i < 9; i++)
		sudoku.print_set('c', i);

}