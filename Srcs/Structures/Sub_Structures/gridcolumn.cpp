#include "../../../Headers/structure.h"
#include <iostream>


/*----Structure gridcolumn----*/

//PRIVATE
#pragma region PRIVATE

	//PRIVATE FUNCTIONS

void gridcolumn::memory_handler(int grid[9][9], int i)
{
	for (int a = 0; a < 9; a++)
	{
		slot[a] = &grid[a][i];
	}
}

#pragma endregion

//PUBLIC
#pragma region PUBLIC
	//PUBLIC FUNCTIONS


#pragma endregion