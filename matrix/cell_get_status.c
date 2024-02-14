#include "matrix.h"

cell_status_t cell_get_status(ushort n, vector2d_t pos) {
  if (validate_pos((vector_t)pos))
    return CELL_KO;

  if (n > MATRIX_SIZE)
    return CELL_KO;
  if (n == 0)
    return CELL_OK;

  return sudoku_get()->mtx[n][pos.y][pos.x];
}
