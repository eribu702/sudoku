#include "../../Headers/structure.h"
#include <iostream>



/*----Structure gridsqaure----*/

//PRIVATE
#pragma region PRIVATE

//PRIVATE FUNCTIONS

//assigns pointers to gridspaces
void gridsqaure::memory_handler(int grid[9][9], int inp)
{
	int row = (inp / 3) * 3;
	int col = (inp % 3) * 3;

	for (int rowR = 0, i = 0; rowR < 3; rowR++)
	{
		for (int colC = 0; colC < 3; colC++)
		{
			slot[i++] = &grid[rowR + row][colC + col];
		}
	}
}

#pragma endregion

//PUBLIC
#pragma region PUBLIC
	//PUBLIC FUNCTIONS


#pragma endregion