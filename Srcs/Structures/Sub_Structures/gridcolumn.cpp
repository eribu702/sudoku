#include "../../../Headers/structure.h"
#include <iostream>


/*----Structure gridcolumn----*/

//PRIVATE FUNCTIONS

void gridcolumn::memory_handler(int grid[9][9], int i)
{
	for (int a = 0; a < 9; a++)
	{
		slot[a] = &grid[a][i];
	}
}



//PUBLIC FUNCTIONS