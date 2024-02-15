#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include "grid.h"

const char *EMPTY_GRID = "+-----------+-----------+-----------+\0"
                         "|   |   |   |   |   |   |   |   |   |\0"
                         "|---+---+---|---+---+---|---+---+---|\0"
                         "|   |   |   |   |   |   |   |   |   |\0"
                         "|---+---+---|---+---+---|---+---+---+\0"
                         "|   |   |   |   |   |   |   |   |   |\0"
                         "+-----------+-----------+-----------+\0"
                         "|   |   |   |   |   |   |   |   |   |\0"
                         "|---+---+---|---+---+---|---+---+---|\0"
                         "|   |   |   |   |   |   |   |   |   |\0"
                         "|---+---+---|---+---+---|---+---+---|\0"
                         "|   |   |   |   |   |   |   |   |   |\0"
                         "+-----------+-----------+-----------+\0"
                         "|   |   |   |   |   |   |   |   |   |\0"
                         "|---+---+---|---+---+---|---+---+---|\0"
                         "|   |   |   |   |   |   |   |   |   |\0"
                         "|---+---+---|---+---+---|---+---+---|\0"
                         "|   |   |   |   |   |   |   |   |   |\0"
                         "+-----------+-----------+-----------+\0";

static char GRID[GRID_ROWS][GRID_COLS] = {{0}};

static void reset_grid(void) { memcpy(GRID, EMPTY_GRID, sizeof(GRID)); }

static void fill_row(char *linebuffer, row_t row) {
  ushort n = 0;

  linebuffer += 2;
  for (ushort i = 0; i < MATRIX_SIZE; i += 1) {
    n = row[i];
    linebuffer[i * 4] = (n > 0) ? '0' + n : ' ';
  }
}

static void fill_grid(matrix_t matrix) {
  for (ushort i = 0; i < MATRIX_SIZE; i += 1)
    fill_row(GRID[i * 2 + 1], matrix[i]);
}

void grid_print(ushort n) {
  if (n > MATRIX_SIZE)
    return;
  reset_grid();
  fill_grid(sudoku_get()->mtx[n]);
  for (ushort i = 0; i < GRID_ROWS; i += 1)
    printf("%s\n", GRID[i]);
}
