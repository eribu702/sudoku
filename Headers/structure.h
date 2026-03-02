#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

#include <vector>


//STRUCTURE DECLARATIONS
/*------------------------------*/



/*----Structure gridsqaure----*/
#pragma region Structure gridsqaure
struct gridsqaure
{
	//FRIENDS
	friend struct dynamicboard;
private:
#pragma region PRIVATE
	//CONTRUCTOR (private)

	//PRIVATE RESOURCES

	int* sqaure_slot[9];

	//PRIVATE FUNCTIONS

	//recieves and packages slot information
	void memory_handler(int grid[9][9], int inp);

	//prints gridsqaure's contents
	void print_s();

	//fill a sqaure with an input
	void fill_s(int inp);

#pragma endregion

public:
#pragma region PUBLIC
	//PUBLIC FUNCTIONS

#pragma endregion
};
#pragma endregion


/*----Structure gridcolumn----*/
#pragma region Structure gridcolumn
struct gridcolumn
{
	//FRIENDS
	friend struct dynamicboard;
private:
#pragma region PRIVATE
	//CONTRUCTOR (private)

	//PRIVATE RESOURCES

	int* column_slot[9];

	//PRIVATE FUNCTIONS

	//fill functions
	
	//fills column with inp
	void fill_c( int inp);

	//print functions

	//recieves and packages slot information
	void memory_handler(int column[9][9], int i);

	//prints gridcolumn's contents
	void print_c();

#pragma endregion

public:
#pragma region PUBLIC
	//PUBLIC FUNCTIONS

#pragma endregion
};
#pragma endregion


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
	void memory_handler(int grid[9][9], int i);

	//prints gridrow's contents
	void print_r();

	//fill a row with an input
	void fill_r(int inp);

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
private:
#pragma region PRIVATE
	//PRIVATE RESOURCES
	int grid[9][9];
	gridrow row[9];
	gridcolumn column[9];
	gridsqaure sqaure[9];

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
	
	//fill functions
	
	//fills row[i] with inp
	void fill_row(int i, int inp);

	//fills column[i] with inp
	void fill_column(int i, int inp);

	//fills sqaure[i] with inp
	void fill_sqaure(int i, int inp);


	//print functions
	
	//prints column of sudoku board
	void print_column(int i);

	//prints row of sudoku board
	void print_row(int i);

	//prints sqaure of sudoku board
	void print_sqaure(int i);

	//print board to screen
	void print_sudoku();

	//print vector board to screen
	void print_vector_sudoku();
#pragma endregion
};
#pragma endregion



#endif