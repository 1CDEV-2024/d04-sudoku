#include <stddef.h>

#include "matrix.h"

sudoku_t sudoku_get(void) {
  static struct sudoku_s sdk = {0};
  return &sdk;
}
