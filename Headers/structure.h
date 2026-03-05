#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

#include <vector>


//STRUCTURE DECLARATIONS
/*------------------------------*/



/*----Structure gridsquare----*/
#pragma region Structure gridsquare
struct gridsquare
{
	//FRIENDS
	friend struct dynamicboard;
private:
#pragma region PRIVATE
	//CONTRUCTOR (private)

	//PRIVATE RESOURCES

	int* slot[9];
	int zeroes = 0;
	bool num_present[9] = { false };

	//PRIVATE FUNCTIONS

	//recieves and packages slot information
	void memory_handler(int grid[9][9], int inp);

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

	int* slot[9];
	int zeroes = 0;
	bool num_present[9] = { false };

	//PRIVATE FUNCTIONS

	//recieves and packages slot information
	void memory_handler(int column[9][9], int i);

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

	int* slot[9];
	int zeroes = 0;
	bool num_present[9] = { false };

	//PRIVATE FUNCTIONS
		
	//recieves and packages slot information
	void memory_handler(int grid[9][9], int i);

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
	gridsquare square[9];


	//PRIVATE FUNCTIONS

	//calls allocation functions
	void allocate_data_sets(int grid[9][9]);

	//checks a row, column or square
	int check(char structure, int index, int target);

	//checks all rows for numbers out of 0-9 range, will return true if none found
	bool range_check(int index);

	//sets a substructure's num_present[found_num] to true if the number exists
	void number_present(char structure, int structure_i, int found_num);

#pragma endregion

public:
#pragma region PUBLIC
	//PUBLIC CONSTRUCTOR
	dynamicboard(const int inp[9][9]);



	//PUBLIC FUNCTIONS

	//prints a row, column or square's contents
	void print_set(char structure, int i);

	//print board to screen
	void print();




	//CHECK FUNCTIONS

	//counts empties
	void count_zeroes();

	//ensures there is no repeats of numbers in rows, columns or squares and records number presence in structures
	bool check_correct();

	//checks every row, column and square for repeats of the same number
	bool initial_check();

#pragma endregion
};
#pragma endregion



#endif