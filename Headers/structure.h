#ifndef STRUCTURE_H_
#define _STRUCTURE_H_

#include <vector>


//STRUCTURE DECLARATIONS
/*------------------------------*/


/*----Structure gridset----*/
#pragma region Structure gridset
class gridset
{
	friend struct Sudoku;
	friend struct gridnumber;


	int* position[9] = {nullptr};
	bool filled[9] = { false };
};
#pragma endregion


/*----Structure gridboard----*/
#pragma region Structure gridboard
class gridboard
{
	friend struct Sudoku;


	int I = 0;
	gridset* row = nullptr; gridset* column = nullptr; gridset* square = nullptr;
	int coordinate = -1;

};
#pragma endregion





/*----Structure Sudokuboard----*/
#pragma region Structure Sudoku
struct Sudoku
{
private:
	//PRIVATE RESOURCES
	gridboard grid[9][9];
	std::vector<gridboard*> empty;

	gridset row[9];
	gridset column[9];
	gridset square[9];
	

public:
	//PUBLIC CONSTRUCTOR
	Sudoku(const int inp[9][9]);


	
	//prints a row, column or square's contents
	void print_set(char structure, int i);

	//print board to screen
	void print();

	//prints all stored zero counts from structures
	void print_zeroes();

	//prints all empty numbers using empty vector
	void print_empties();


	

	//catch out of range or repeats, returns false if empty number (0)
	void check_info(int y, int x);


};
#pragma endregion



#endif