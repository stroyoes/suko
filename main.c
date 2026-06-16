#include "solver.h"
#include "board.h"

#include <stdio.h>

int main(void) {
    printf("Puzzle: \n");
    display_sudoku(sudoku);

    if (solve_sudoku(sudoku)) {
        printf("\n Solved: \n");
        display_sudoku(sudoku);
    } else {
        printf("\n No solutions exists! \n");
    }

    return 0;
}
