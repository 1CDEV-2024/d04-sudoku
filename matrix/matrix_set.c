#include "matrix.h"

static void clear_cell(vector2d_t pos) {
  sudoku_t sdk = sudoku_get();
  ushort n = sdk->mtx[0][pos.y][pos.x];

  // Remove the current value of the cell from the game matrix
  sdk->mtx[0][pos.y][pos.x] = CELL_OK;

  // Since it's the slowest operation and we want to avoid repeating it, we'll
  // store its results for faster access, and also avoid calling the function 9
  // times per square.
  ushort skip_square[3][3] = {{0}};
  for (ushort y = 0; y < MATRIX_SIZE; y += 3)
    for (ushort x = 0; x < MATRIX_SIZE; x += 3)
      skip_square[y / 3][x / 3] = square_has(Vector2D(.x = x, .y = y), n);

  // Try every ro
  for (ushort y = 0; y < MATRIX_SIZE; y += 1)
    for (ushort x = 0; x < MATRIX_SIZE; x += 1) {
      if (skip_square[y / 3][x / 3] || row_has(y, n) || col_has(x, n))
        continue;
      sdk->mtx[n][y][x] = CELL_OK;
    }
}

static void lock_cell(vector2d_t pos, ushort n) {
  sudoku_t sdk = sudoku_get();

  // Lock the row
  for (ushort i = 0; i < MATRIX_SIZE; i += 1)
    sdk->mtx[n][pos.y][i] = CELL_KO;

  // Lock the column
  for (ushort i = 0; i < MATRIX_SIZE; i += 1)
    sdk->mtx[n][i][pos.x] = CELL_KO;

  // Lock the square
  vector2d_t square = {0};
  cell_get_square(pos, &square);
  for (ushort y = square.y; y < square.y + 3; y += 1)
    for (ushort x = square.x; x < square.x + 3; x += 1)
      sdk->mtx[n][y][x] = CELL_KO;

  // Set the cell value
  sdk->mtx[0][pos.y][pos.x] = n;
}

cell_status_t matrix_set(vector2d_t pos, ushort n) {
  if (validate_pos((vector_t)pos) == CELL_KO)
    return CELL_KO;

  sudoku_t sdk = sudoku_get();
  ushort save = sdk->mtx[0][pos.y][pos.x];
  if (save == n)
    return CELL_OK;

  if (save != CELL_OK)
    clear_cell(pos);
  if (n != CELL_OK)
    lock_cell(pos, n);

  return CELL_OK;
}
