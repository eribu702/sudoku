#ifndef _SUDOKU_H_
#define _SUDOKU_H_

#include <vector>
#include <iostream>

//FUNCTION DECLARATIONS
/*---------------------------------*/

//STRUCTURE FUNCTIONS

//LIBRARY FUNCTIONS

















//STRUCTURES
/*---------------------------------*/

/*----SUDOKU DYNAMIC BOARD----*/
struct dynamicboard
{
//FRIENDS
friend class gridrow;
public:

	dynamicboard(const int inp[9][9]);

private:

	int grid[9][9];


	//Private Functions

	//returns copy of grid
	std::vector<std::vector<int>> vector_board();

public:
	//Public Functions
	
	//print board to screen
	void print_sudoku();

	//print vector board to screen
	void print_vector_board(std::vector<std::vector<int>> gridcpy);

};




///*----SUDOKU ROW----*/
//struct gridrow
//{
////FRIENDS
//friend class dynamicboard;
//private:
////Contructor (private)
//	gridrow(int* inp[9])
//	{
//		for (int i = 0; i < 9; i++)
//			row[i] = inp[i];
//	}
//
//	int* row[9];
//
//public:
//	
//
//};











//FUNCTIONS
/*---------------------------------*/




#endif
