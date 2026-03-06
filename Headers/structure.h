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
	friend struct Sudokuboard;
	friend struct gridnumber;
private:
#pragma region PRIVATE
	//CONTRUCTOR (private)

	//PRIVATE RESOURCES

	int* slot[9];
	int zeroes = 0;

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
	friend struct Sudokuboard;
	friend struct gridnumber;
private:
#pragma region PRIVATE
	//CONTRUCTOR (private)

	//PRIVATE RESOURCES

	int* slot[9];
	int zeroes = 0;

	//PRIVATE FUNCTIONS

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
	friend struct Sudokuboard;
	friend struct gridnumber;
private:
#pragma region PRIVATE
	//CONTRUCTOR (private)
	
	//PRIVATE RESOURCES

	int* slot[9];
	int zeroes = 0;

	//PRIVATE FUNCTIONS


#pragma endregion

public:
#pragma region PUBLIC
	//PUBLIC FUNCTIONS

#pragma endregion
};
#pragma endregion




/*----Structure gridnumber----*/
#pragma region Structure gridnumber
struct gridnumber
{
	//FRIENDS
	friend struct Sudokuboard;
private:
#pragma region PRIVATE
	//CONTRUCTOR (private)

	//PRIVATE RESOURCES
	bool filled = false;
	int* slot;
	gridrow* row;
	gridcolumn* column;
	gridsquare* square;

	//PRIVATE FUNCTIONS

#pragma endregion

public:
#pragma region PUBLIC
	//PUBLIC FUNCTIONS

#pragma endregion
};
#pragma endregion



/*----Structure Sudokuboard----*/
#pragma region Structure Sudokuboard
struct Sudokuboard
{
private:
#pragma region PRIVATE
	//PRIVATE RESOURCES
	int grid[9][9];
	gridrow row[9];
	gridcolumn column[9];
	gridsquare square[9];
	gridnumber number[9][9];


	//PRIVATE FUNCTIONS

	//checks a row, column or square
	int check_set(char structure, int index, int target);

	//checks all rows for numbers out of 0-9 range, will return true if none found
	bool range_check(int index);

	//gives rows, columns, squares and numbers thier appropraiate data
	void assign_memory();


#pragma endregion

public:
#pragma region PUBLIC
	//PUBLIC CONSTRUCTOR
	Sudokuboard(const int inp[9][9]);



	//PUBLIC FUNCTIONS

	//prints a row, column or square's contents
	void print_set(char structure, int i);

	//print board to screen
	void print();

	//prints number structures to screen
	void print_numbers();



	//CHECK FUNCTIONS

	//ensures there is no repeats of numbers in rows
	bool check_correct();

#pragma endregion
};
#pragma endregion



#endif