/*What are the basic rules of Sudoku?
Sudoku grid consists of 9x9 spaces.
You can use only numbers from 1 to 9.
Each 3×3 block can only contain numbers from 1 to 9.
Each vertical column can only contain numbers from 1 to 9.
Each horizontal row can only contain numbers from 1 to 9.
Each number in the 3×3 block, vertical column or horizontal row can be used only once.
The game is over when the whole Sudoku grid is correctly filled with numbers.*/

#include <iostream>
#include <vector>
#include "Header.h"

int main() {
	//initialise a 9x9 array
    int new_sudoku[9][9] = {
    {9, 2, 3, 4, 9, 6, 7, 8, 9},
    {7, 8, 9, 9, 2, 3, 4, 5, 6},
    {4, 5, 6, 7, 8, 9, 9, 2, 3},  
    {3, 1, 2, 8, 4, 5, 9, 6, 7},  
    {6, 9, 7, 3, 1, 2, 8, 4, 5},
    {8, 4, 5, 6, 9, 7, 3, 1, 2},
    {2, 3, 1, 5, 7, 4, 6, 9, 8},
    {9, 6, 8, 2, 3, 1, 5, 7, 4},
    {5, 7, 4, 9, 6, 8, 2, 3, 1}
    };
	Sudoku sudoku(new_sudoku);

    sudoku.check_sudoku();



}