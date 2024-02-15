#include "matrix.h"

short row_has(ushort row, ushort n) {
  sudoku_t sdk = sudoku_get();

  for (ushort i = 0; i < MATRIX_SIZE; i += 1)
    if (sdk->mtx[0][row][i] == n)
      return 1;
  return 0;
}

short col_has(ushort col, ushort n) {
  sudoku_t sdk = sudoku_get();

  for (ushort i = 0; i < MATRIX_SIZE; i += 1)
    if (sdk->mtx[0][i][col] == n)
      return 1;
  return 0;
}

short square_has(vector2d_t pos, ushort n) {
  sudoku_t sdk = sudoku_get();
  vector2d_t square = {0};

  cell_get_square(pos, &square);
  for (ushort y = square.y; y < square.y + 3; y += 1)
    for (ushort x = square.x; x < square.x + 3; x += 1)
      if (sdk->mtx[0][y][x] == n)
        return 1;
  return 0;
}
