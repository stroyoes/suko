#include "solver.h"

#include <stdbool.h>
#include <stdio.h>

// Get the empty cell from the board 
bool find_empty_cell(int board[9][9], int *row, int *col) {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (board[r][c] == 0) { *row = r; *col = c; return true; }
        }
    }
    return false; // no empty cells left in the board 
}

bool is_valid_state(int board[9][9], int row, int col, int num) {
    for (int i = 1; i <= 9; i++) {
        if (board[row][i] == num) { return false; } // check for a full row and  
        if (board[i][col] == num) { return false; } // for a full col 
    }

    // now check for a 3X3 box
    int box_row = (row / 3) * 3; int box_col = (col / 3) * 3;

    for (int r = box_row; r < box_row + 3; r++) {
        for (int c = box_col; c < box_col + 3; c++) {
            if (board[r][c] == num) { return false; }
        }
    }

    return true;
}

bool solve_sudoku(int board[9][9]) {
    int row, col;

    if (!find_empty_cell(board, &row, &col)) { return true; }

    for (int n = 1; n <= 9; n++) {
        if (is_valid_state(board, row, col, n)) { board[row][col] = n; }

        if (solve_sudoku(board)) { return true; } // recursion

        board[row][col] = 0; // backtracking 
    }

    return false; // let it backtrack 
}

void display_sudoku(int board[9][9]) {
    printf(" ------+-------+------ \n");

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            if (c == 0) { printf("|"); }
            printf("%d", board[r][c]);
            if (c == 2 || c == 5) { printf("| "); }
        }

        printf("\n");
        if (r == 2 || r == 5) { printf(" ------+-------+------ \n"); }

    }
}


