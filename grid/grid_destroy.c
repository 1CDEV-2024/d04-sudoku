#include <stdlib.h>

#include "grid.h"

grid_t grid_destroy(void) {
  grid_t *gridptr = grid_get_ptr();
  grid_t grid = *gridptr;

  for (ushort i = 0; i < GRID_COLS; i += 1)
    free(grid[i]);
  free(grid);
  *gridptr = NULL;
  return NULL;
}
