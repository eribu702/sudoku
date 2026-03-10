#include "../Headers/structure.h"
#include <iostream>


/*----Structure Sudokuboard----*/


//Sudokuboard CHECKING FUNCTIONS


//PRIVATE


//catch out of range or repeats, returns false if empty number (0)
void Sudoku::check_info(const int y, const int x)
{
	// checks numbers are in range
	if (grid[y][x].I < 0 || grid[y][x].I > 9) {
		std::cout << "Row " << y + 1 << " has the number: " << grid[y][x].I << '\n';
		std::cout << "Make sure all numbers are between 0 & 9!";
		std::exit(0);
	}

	//checks not zero
	if (grid[y][x].I == 0) {
		empty.push_back(&grid[y][x]);//pushes back with vector(struct gridnumber*) pointing towards address of empty slots
		empty[empty.size() - 1]->coordinate = y * 9 + x;
		return;
	}
	
	const int num = grid[y][x].I - 1;//to avoid indexing like this: filled[grid[y][x] - 1]
	bool fail = false;
	
	//ensures number doesn't already exist in structures
	if (grid[y][x].row->filled[num] == true) {
		std::cout << "Row ";
		fail = true;
	} else if (grid[y][x].column->filled[num] == true) {
		std::cout << "Column ";
		fail = true;
	} else if (grid[y][x].square->filled[num] == true) {
		std::cout << "Square ";
		fail = true;
	} if (fail) {
		std::cout << y + 1 << " has more than one " << grid[y][x].I << "'s!\n";
		std::exit(0);
	}

	//number not zero, out of range or already existing, assign infomation
	grid[y][x].row->filled[num] = true;
	grid[y][x].column->filled[num] = true;
	grid[y][x].square->filled[num] = true;
}