#include "generator.h"

void generate_diagonal(void) {
  generate_square(Vector2D(.x = 0, .y = 0));
  generate_square(Vector2D(.x = 3, .y = 3));
  generate_square(Vector2D(.x = 6, .y = 6));
}
