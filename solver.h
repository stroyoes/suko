#ifndef SOLVER_H
#define SOLVER_H

#include <stdbool.h>

bool solve_sudoku(int board[9][9]);
bool is_valid_state(int board[9][9], int row, int col, int num);
bool find_empty_cell(int board[9][9], int *row, int *col);
void display_sudoku(int board[9][9]);

#endif 
