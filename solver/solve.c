#include <stdlib.h>

#include "../matrix/matrix.h"
#include "../sudoku.h"
#include "solver.h"

static ushort try_next_candidate(stack_t *stack) {
  if (stack->top == NULL)
    return 0;

  snode_t node = stack->top;
  // If the cell corresponding to this node has no possible candidate left,
  // return true so that the calling function can know to backtrack.
  if (*(node->candidates) == '\0')
    return 1;

  node->n = pop_random_digit(node->candidates);
  matrix_set(node->pos, node->n);

  return 0;
}

static void backtrack(stack_t *stack, vector2d_t *pos) {
  snode_t node = stack_pop(stack);
  if (node == NULL)
    return;

  matrix_set(node->pos, CELL_OK);
  free(node);
}

static ushort find_next_free_cell(vector2d_t *pos) {
  sudoku_t sdk = sudoku_get();

  for (pos->y = 0; pos->y < MATRIX_SIZE; pos->y += 1)
    for (pos->x = 0; pos->x < MATRIX_SIZE; pos->x += 1)
      if (sdk->mtx[0][pos->y][pos->x] == CELL_OK)
        return 0;

  // If the loop doesn't `break` and we arrive at the last cell, we need to
  // check that it is free.
  // If it's not, it means there is no free cell remaining: we have solved the
  // puzzle.
  // Return non-ero to let the calling function know to finish running
  return (sdk->mtx[0][pos->y][pos->x] != CELL_OK);
}

solver_status_t solve(void) {
  vector2d_t pos = {0};
  stack_t stack = {0};
  snode_t node = NULL;

  do {
    if (find_next_free_cell(&pos))
      break;
    node = node_create(&pos);
    stack_push(&stack, node);
    while (try_next_candidate(&stack))
      backtrack(&stack, &pos);
  } while (stack.top != NULL);
  stack_destroy(&stack);

  // If we exited the loop and the cell at current position is empty, the pule
  // has not been solved and is not solvable.
  return (sudoku_get()->mtx[0][pos.y][pos.x] == CELL_OK);
}
