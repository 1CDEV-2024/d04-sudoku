#include <sys/types.h>

#include "../solver/solver.h"
#include "../sudoku.h"
#include "generator.h"

static void remove_random_cells(ushort rm) {
  sudoku_t sdk = sudoku_get();
  vector2d_t v2d = {0};

  for (ushort i = 0; i < rm; i += 1) {
    do {
      v2d = Vector2D(.x = generate_number(MATRIX_SIZE),
                     .y = generate_number(MATRIX_SIZE));
    } while (sdk->mtx[0][v2d.y][v2d.x] == CELL_OK);
    matrix_set(v2d, 0);
  }
}

void generate(ushort rm) {
  generate_diagonal();
  solve();
  remove_random_cells(rm);
}
