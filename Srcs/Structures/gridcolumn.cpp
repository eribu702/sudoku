#include "../../Headers/structure.h"
#include <iostream>


/*----Structure gridcolumn----*/

//PRIVATE
#pragma region PRIVATE

	//PRIVATE FUNCTIONS

void gridcolumn::memory_handler(int grid[9][9], int i)
{
	for (int a = 0; a < 9; a++)
	{
		column_slot[a] = &grid[a][i];
	}
}



//fill functions

//fills column with inp
void gridcolumn::fill_c(int inp)
{
	for (int i = 0; i < 9; i++)
		*column_slot[i] = inp;
}


//print functions
void gridcolumn::print_c()
{
	std::cout << *column_slot[0];
	for (int i = 1; i < 9; i++)
		std::cout << ", " << *column_slot[i];
	std::cout << '\n';
}
#pragma endregion

//PUBLIC
#pragma region PUBLIC
	//PUBLIC FUNCTIONS


#pragma endregion