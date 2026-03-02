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


//fill functions

//fills row with inp
void gridrow::fill_r(int inp)
{
	for (int i = 0; i < 9; i++)
		*row_slot[i] = inp;
}



//print functions

//prints row
void gridrow::print_r()
{
	std::cout << *row_slot[0];
	for (int i = 1; i < 9; i++)
		std::cout << ", " << *row_slot[i];
	std::cout << '\n';
}

#pragma endregion

//PUBLIC
#pragma region PUBLIC
	//PUBLIC FUNCTIONS


#pragma endregion