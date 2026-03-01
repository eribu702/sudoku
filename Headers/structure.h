#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

#include <vector>


//STRUCTURE DECLARATIONS
/*------------------------------*/




/*----Structure gridrow----*/
#pragma region Structure gridrow
struct gridrow
{
	//FRIENDS
	friend struct dynamicboard;
private:
#pragma region PRIVATE
	//CONTRUCTOR (private)
	
	//PRIVATE RESOURCES

	int* row_slot[9];

	//PRIVATE FUNCTIONS
		
	//recieves and packages slot information
	void row_memory_handler(int row[9]);

	//prints gridrow's contents
	void print_r();

#pragma endregion

public:
#pragma region PUBLIC
	//PUBLIC FUNCTIONS

#pragma endregion
};
#pragma endregion



/*----Structure dynamicboard----*/
#pragma region Structure dynamicboard
struct dynamicboard
{
	//FRIENDS
	friend struct gridrow;
private:
#pragma region PRIVATE
	//PRIVATE RESOURCES
	int grid[9][9];
	gridrow row[9];

	//PRIVATE FUNCTIONS

	//returns copy of grid
	std::vector<std::vector<int>> get_vector_board();

	//calls allocation functions
	void allocate_data_sets(int grid[9][9]);
#pragma endregion

public:
#pragma region PUBLIC
	//PUBLIC CONSTRUCTOR
	dynamicboard(const int inp[9][9]);

	//PUBLIC RESOURCES

	//PUBLIC FUNCTIONS

	//prints row of sudoku board
	void print_row(int i);

	//print board to screen
	void print_sudoku();

	//print vector board to screen
	void print_vector_sudoku();
#pragma endregion
};
#pragma endregion



#endif