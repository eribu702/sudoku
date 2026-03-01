#include "../../Headers/structure.h"
#include <iostream>


/*----Structure gridrow----*/

//PRIVATE
#pragma region PRIVATE

	//PRIVATE FUNCTIONS

void gridrow::row_memory_handler(int row[9])
{
	for (int i = 0; i < 9; i++)
	{
		row_slot[i] = &row[i];
	}
}

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