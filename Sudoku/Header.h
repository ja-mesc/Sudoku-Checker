#include <vector>

//create a sudoku class
class Sudoku {
	int imax = 8;
	int jmax = 8; //number of rows and columns

	int sudoku[9][9]; //9x9 array
	int sudoku_box[9][9]; //sudoku reorganised to have boxes in columns

	std::vector<int> veci; //9 column vectors
	std::vector<int> vecj; //9 row vectors
	std::vector<int> boxij; //9 'box' vectors

public:
	void check_row_col(); //checks all rows and columns for repititon
	std::vector<int> get_boxij(int i, int j); //returns 2d vector of sub grids and checks for repition within boxes
	std::vector<std::vector<int>> get_sub_sudoku(); //rearranges sudoku into vector of sub grids
	void check_sudoku();

	Sudoku(int new_sudoku[9][9]); //constructor
	//~Sudoku(); //destructor

	//
};
