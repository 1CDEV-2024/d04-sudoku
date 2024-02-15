#include <assert.h>
#include <stdlib.h>

#include "solver.h"

snode_t node_create(vector2d_t *cell) {
  snode_t node = malloc(sizeof(*node));
  assert(node != NULL);

  sudoku_t sdk = sudoku_get();
  node->pos.x = cell->x;
  node->pos.y = cell->y;
  node->n = sdk->mtx[0][cell->y][cell->x];

  char *cursor = node->candidates;
  for (ushort i = 1; i < 10; i += 1) {
    if (sdk->mtx[i][cell->y][cell->x] == CELL_KO)
      continue;
    *(cursor++) = '0' + i;
  }
  *cursor = '\0';

  return node;
}

void stack_destroy(stack_t *stack) {
  while (stack->top != NULL)
    free(stack_pop(stack));
}

snode_t stack_push(stack_t *stack, snode_t node) {
  node->next = stack->top;
  stack->top = node;
  return node;
}

snode_t stack_pop(stack_t *stack) {
  if (stack->top == NULL)
    return NULL;

  snode_t node = stack->top;

  stack->top = node->next;
  node->next = NULL;
  return node;
}
