#ifndef GRID_H
#define GRID_H

#include "../matrix/matrix.h"

#define GRID_ROWS 19
#define GRID_COLS 38
typedef char **grid_t;

extern const char *EMPTY_GRID;

grid_t grid_create(void);

grid_t grid_destroy(void);

grid_t grid_get(void);

grid_t *grid_get_ptr(void);

grid_t grid_update(matrix_t mtx);

void grid_print(ushort n);

#endif // GRID_H
