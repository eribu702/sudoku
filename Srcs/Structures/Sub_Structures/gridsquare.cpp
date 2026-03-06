#include "../../../Headers/structure.h"
#include <iostream>



/*----Structure gridsquare----*/

//PRIVATE FUNCTIONS

//assigns pointers to gridspaces
void gridsquare::memory_handler(int grid[9][9], int inp)
{
	
	int y = (inp / 3) * 3;
	int x = (inp % 3) * 3;

	for (int yy = 0, nine = 0; yy < 3; yy++)//iterate rows
	{
		for (int xx = 0; xx < 3; xx++)//iterate columns
		{
			slot[nine++] = &grid[yy + y][xx + x];
		}
	}
}


//PUBLIC FUNCTIONS