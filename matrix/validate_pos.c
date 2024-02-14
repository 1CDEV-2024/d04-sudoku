#include "matrix.h"

cell_status_t validate_pos(vector_t pos) {
  vector3d_t v3d = pos.v3d;

  return v3d.z >= MATRIX_DEPTH || v3d.x >= MATRIX_SIZE || v3d.y >= MATRIX_SIZE;
}
