#include "../matrix/matrix.h"
#include "../sudoku.h"

void generate_square(vector2d_t origin) {
  if (validate_pos((vector_t)origin))
    return;

  char n = 0;
  char digits[] = "123456789";

  for (ushort y = origin.y; y < origin.y + 3; y += 1)
    for (ushort x = origin.x; x < origin.x + 3; x += 1) {
      n = pop_random_digit(digits);
      matrix_set(Vector2D(.x = x, .y = y), n);
    }
}
