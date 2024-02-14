#include "matrix.h"

ushort point_origin(ushort n) { return n / 3 * 3; }

cell_status_t cell_get_square(vector2d_t cell, vector2d_t *origin) {
  if (validate_pos((vector_t)cell) == CELL_KO)
    return CELL_KO;

  origin->x = point_origin(cell.x);
  origin->y = point_origin(cell.y);
  return CELL_OK;
}
