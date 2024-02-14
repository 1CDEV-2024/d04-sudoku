#include "matrix.h"

static void update_boolean_matrix(vector2d_t *pos, ushort n) {
  matrix_t *mtx = &(sudoku_get()->mtx[n]);

  for (ushort i = 0; i < MATRIX_SIZE; i += 1)
    (*mtx)[pos->y][i] = !!n;
  for (ushort i = 0; i < MATRIX_SIZE; i += 1)
    (*mtx)[i][pos->x] = !!n;

  cell_get_square(*pos, pos);
  for (ushort y = pos->y; y < pos->y + 3; y += 1)
    for (ushort x = pos->x; x < pos->x + 3; x += 1)
      (*mtx)[y][x] = !!n;
}

cell_status_t matrix_set(vector2d_t pos, ushort n) {
  if (cell_get_status(n, pos) == CELL_KO)
    return CELL_KO;

  sudoku_get()->mtx[0][pos.y][pos.x] = n;
  update_boolean_matrix(&pos, n);
  return CELL_OK;
}
