# `suko`

A command-line Sudoku puzzle solver written in C, using backtracking.

## How it works 

The solver scans the board for the first empty cell, tries placing digits
1–9 in it, and checks if that digit is valid for the current row, column,
and 3x3 box. If a digit fits, it recurses into the next empty cell. If no
digit works, it backtracks — undoes the last placement and tries the next
possibility — until the board is solved or proven unsolvable.

## Editing the puzzle

Open `board.c` and edit the `sudoku[9][9]` array. Use `0` for empty cells.

```c
int sudoku[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    ...
};
```

> This is an early, intentionally minimal version. `board.c` hardcodes the
puzzle and will be replaced with file/CLI input in a later version.

## Plans for later versions

- Read puzzle from a file instead of hardcoding in `board.c`
- Some CLI flags for input/output
- OCR image input — scan a photo of a sudoku grid
- Hint mode — reveal one cell at a time instead of the full solution
- History of previously solved puzzles
- Bitmask-based constraint tracking, replacing the row/col/box scan in `is_valid_state` with bitwise checks for faster solving on harder puzzles








