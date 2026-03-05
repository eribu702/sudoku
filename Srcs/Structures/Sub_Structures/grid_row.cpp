#include "../../../Headers/structure.h"
#include <iostream>


/*----Structure gridrow----*/

//PRIVATE FUNCTIONS

void gridrow::memory_handler(int grid[9][9], int i)
{
	for (int a = 0; a < 9; a++)
	{
		slot[a] = &grid[i][a];
	}
}



//PUBLIC FUNCTIONS