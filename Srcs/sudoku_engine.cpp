#include "../Headers/sudoku.h"

void sudoku_engine(const int grid[9][9])
{
	dynamicboard sudoku(grid);
	if (!sudoku.check_correctness())
	{
		std::cout << "This sudoku puzzle is unsolvable!\n";
		return;
	}
}