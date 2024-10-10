#include <vector>
#include <iostream>
#include "Header.h"
#include <set>

Sudoku::Sudoku(int new_sudoku[9][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			sudoku[i][j] = new_sudoku[i][j];
		}
	}
};

std::vector<int> Sudoku::get_boxij(int i, int j) { //input the box coordinates 
	if (i < 1 || i > 3 || j < 1 || j > 3) {
		std::cout << "box coordinates must be between 1 and 3";
		return { 0 };
	}
	std::vector<int> box_vec;
	for (int p = 3*(i - 1); p < 3*i; p++) {
		for (int q = 3*(j - 1); q < 3*j; q++) {
			//std::cout << sudoku[p][q] << "\n";
			box_vec.push_back(sudoku[p][q]); //iterate over the inner box and add items to box_vec column-wise
		}
	}
	return box_vec;
}

std::vector<std::vector<int>> Sudoku::get_sub_sudoku() {

	bool found_box_duplicates = false;

	std::vector<std::vector<int>> sub_sudoku;

	for (int i = 1; i < 4; i++) {
		for (int j = 1; j < 4; j++) {
			sub_sudoku.push_back(get_boxij(i, j));
		}
	}
	std::cout << "The sub sudoku arranges boxes into rows:\n";
	for (int i = 0; i < sub_sudoku.size(); i++) { //number of rows of 2d vector
		for (int j = 0; j < sub_sudoku[i].size(); j++) { //number of elements per row
			std::cout << sub_sudoku[i][j] << "  ";
		}
		std::cout << "\n"; //new line for each row
	}

	//check for repitition within boxes
	for (int i = 0; i < sub_sudoku.size(); i++) {
		//create new line to print only if duplicates are found
		bool found_duplicates_in_row = false;
		std::set<int> box_elements; 
		//introduce set since duplicates can be found without checking one item at a time  
		//time complexity reduced from O(n^2) to O(n)!

		for (int j = 0; j < sub_sudoku[i].size(); j++) {
			if (box_elements.find(sub_sudoku[i][j]) != box_elements.end()) {

				if (!found_box_duplicates) {
					std::cout << "Sub boxes contain duplicate numbers at coordinates \n";
					found_box_duplicates = true;
				}

				if (!found_duplicates_in_row) {
					found_duplicates_in_row = true;
				}
				std::cout << "(" << i << ", " << j << "), ";

			}
			else { box_elements.insert(sub_sudoku[i][j]); }
		}
		if (found_duplicates_in_row) {
			std::cout << "\n";

		}
	}
	if (!found_box_duplicates) {
		std::cout << "sub boxes are duplicate free!\n";
		return sub_sudoku;
	}
	
}

void Sudoku::check_row_col() {
	//boolean flag
	bool found_col_duplicates = false;
	bool found_row_duplicates = false;

	//first check all columns
	for (int i = 0; i < 9; i++) {
		std::set<int> check_col;

		//create new row if duplicates found
		bool found_duplicate_in_row = false;

		for (int j = 0; j < 9; j++) {
			if (check_col.find(sudoku[i][j]) != check_col.end()) {
				if (!found_col_duplicates) {
					std::cout << "Columns contain duplicate numbers at coordinates\n";
					found_col_duplicates = true;
				}
				std::cout << "(" << i << ", " << j << "), ";

				if (!found_duplicate_in_row) {
					found_duplicate_in_row = true;
				}

			}
			else { check_col.insert(sudoku[i][j]); }
		}
		if (found_duplicate_in_row) {
			std::cout << "\n";
		}
	}
	//now check rows
	for (int i = 0; i < 9; i++) {
		std::set<int> check_row;
		//new line condition
		bool found_duplicates_in_row = false;

		for (int j = 0; j < 9; j++) {
			if (check_row.find(sudoku[j][i]) != check_row.end()) {
				if (!found_row_duplicates) {
					std::cout << "Rows contain duplicates at coordinates\n";
					found_row_duplicates = true;
				}
				std::cout << "(" << j << ", " << i << "), ";

				if (!found_duplicates_in_row) {
					found_duplicates_in_row = true;
				}
			}
			else { check_row.insert(sudoku[j][i]); }
		}
		if (found_duplicates_in_row) {
			std::cout << "\n";
		}
	}
	if (!found_col_duplicates && !found_row_duplicates) {
		std::cout << "No duplicates found in rows or columns!";
	}
}


void Sudoku::check_sudoku() {
	get_sub_sudoku();
	check_row_col();
}
