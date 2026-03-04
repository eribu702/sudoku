#include "../../Headers/structure.h"
#include <iostream>


/*----Structure gridrow----*/

//PRIVATE
#pragma region PRIVATE

	//PRIVATE FUNCTIONS

void gridrow::memory_handler(int grid[9][9], int i)
{
	for (int a = 0; a < 9; a++)
	{
		row_slot[a] = &grid[i][a];
	}
}

#pragma endregion

//PUBLIC
#pragma region PUBLIC
	//PUBLIC FUNCTIONS


#pragma endregion