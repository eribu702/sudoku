#ifndef _SUDOKU_H_
#define _SUDOKU_H_

#include <vector>


//STRUCTURE DECLARATIONS
/*------------------------------*/
#pragma region STRUCTURE DECLARATIONS


/*----Sudoku Dynamic Board----*/
# pragma region Sudoku Dynamic Board
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

/*----Sudoku Row----*/
#pragma region Sudoku Row
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
		void row_memory_handler(int row[9])
		{
			for (int i = 0; i < 9; i++)
			{
				row_slot[i] = &row[i];
			}
		}

		void print_r()
		{
			std::cout << *row_slot[0];
			for (int i = 1; i < 9; i++)
				std::cout << ", " << *row_slot[i];
			std::cout << '\n';
		}
	#pragma endregion

	public:
	#pragma region PUBLIC
		//PUBLIC FUNCTIONS

	#pragma endregion
	};
#pragma endregion






//end of structure declarations
#pragma endregion





















//FUNCTION DECLARATIONS
/*------------------------------*/
#pragma region STRUCTURE DECLARATIONS


/*----Sudoku Dynamic Board----*/
# pragma region Sudoku Dynamic Board

#pragma endregion

/*----Sudoku Row----*/
#pragma region Sudoku Row

#pragma endregion

#pragma endregion

#pragma endregion



#endif