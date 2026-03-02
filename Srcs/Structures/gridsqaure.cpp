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
			sqaure_slot[i++] = &grid[rowR + row][colC + col];
		}
	}
}


//fill functions

//fills sqaure with inp
void gridsqaure::fill_s(int inp)
{
	for (int i = 0; i < 9; i++)
		*sqaure_slot[i] = inp;
}



//print functions

//prints sqaure
void gridsqaure::print_s()
{
	std::cout << *sqaure_slot[0];
	for (int i = 1; i < 9; i++)
		std::cout << ", " << *sqaure_slot[i];
	std::cout << '\n';
}

#pragma endregion

//PUBLIC
#pragma region PUBLIC
	//PUBLIC FUNCTIONS


#pragma endregion