Sudokuboard:
super structure

contains functions:
- Sudokuboard() (constuctor)
- print() (public)
---
- check_info() (public)


//temp functions
- print_set (public)
- print_numbers (public)
- print_zeroes() (public)
- print_empties() (public)

accessed by declarer

holds an int[9][9] called grid
holds three gridset[9] arrays, called row, column and square
holds a gridnumber[9][9]









gridnumber: (used in one [9]x[9] array called "number")

no functions

accessed by Sudokuboard

holds ONE int* named slot with a pointer to the 












gridset: (used in arrays of [9])

no functions

accessed by Sudokuboard and gridnumber

holds [9] int* to grid spaces called "slot"

holds [9] boolean values called "filled" to track what numbers are present