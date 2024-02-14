#include <stddef.h>

#include "grid.h"

grid_t *grid_get_ptr(void) {
  // `static` variables' value is retained even when falling out of scope
  static grid_t grid = NULL;

  return &grid;
}

grid_t grid_get(void) { return *grid_get_ptr(); }
