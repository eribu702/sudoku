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

	int* slot[9];

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
	gridsqaure sqaure[9];


	//PRIVATE FUNCTIONS

	//calls allocation functions
	void allocate_data_sets(int grid[9][9]);

	//checks a row, column or sqaure
	int check(char structure, int index, int target);

#pragma endregion

public:
#pragma region PUBLIC
	//PUBLIC CONSTRUCTOR
	dynamicboard(const int inp[9][9]);

	//PUBLIC RESOURCES

	//PUBLIC FUNCTIONS
	

	//fills structure[i] with inp
	void fill(char structure, int i, int inp);

	//prints a row, column or sqaure's contents
	void print_set(char structure, int i);

	//print board to screen
	void print();




	//check functions

	//checks every row, column and sqaure for repeats of the same number
	bool check_correctness();


#pragma endregion
};
#pragma endregion



#endif