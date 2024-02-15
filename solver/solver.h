#ifndef SOLVER_H
#define SOLVER_H

#include <sys/types.h>

#include "../matrix/matrix.h"
#include "../sudoku.h"

// Honestly haven't tested what happens with an unsolvable grid tbh.
typedef enum {
  SOLVED = 0,
  FAILED = 1,
} solver_status_t;

typedef struct stack_node_s *snode_t;
struct stack_node_s {
  vector2d_t pos;
  ushort n;
  char candidates[10];

  snode_t next;
};

typedef struct {
  snode_t top;
} stack_t;

solver_status_t solve(void);
snode_t node_create(vector2d_t *cell);
snode_t stack_push(stack_t *stack, snode_t node);
snode_t stack_pop(stack_t *stack);
void stack_destroy(stack_t *stack);

#endif /* ifndef SOLVER_H */
