#ifndef MATRIX_H
#define MATRIX_H

#include <sys/types.h>

#define MATRIX_DEPTH 10
#define MATRIX_SIZE 9

typedef enum {
  CELL_OK = 0,
  CELL_KO = 1,
} cell_status_t;

typedef ushort row_t[MATRIX_SIZE];
typedef row_t matrix_t[MATRIX_SIZE];

typedef struct sudoku_s {
  matrix_t mtx[MATRIX_DEPTH];
} *sudoku_t;

typedef struct {
  ushort x;
  ushort y;
} vector2d_t;

#define Vector2D(...) ((vector2d_t){__VA_ARGS__})
#define Vector3D(...) ((vector3d_t){__VA_ARGS__})

typedef struct {
  ushort x;
  ushort y;
  ushort z;
} vector3d_t;

typedef union {
  vector2d_t v2d;
  vector3d_t v3d;
} vector_t;

/**
 * Check that a position is within the range of `0 ... MATRIX_SIZE` for its x/y
 * coordinates.
 *
 * If there is a z, also check that it is withing `0 ...
 * MATRIX_DEPTH`.
 */
cell_status_t validate_pos(vector_t pos);

/**
 * Get the container that hold the game's matrixes.
 *
 * The "current game matrix" represents the game in its current state, while
 * boolean matrixes represent a mapping of which cells a number is allowed or
 * not.
 *
 * - `sudoku_get()->mtx[0]` → game matrix
 * - `sudoku_get()->mtx[1...9]` → boolean matrix
 */
sudoku_t sudoku_get();

/**
 * Set a cell in a game to the given `n` value.
 * This function will automatically reflect the changes in the boolean
 * matrixes.
 */
cell_status_t matrix_set(vector2d_t pos, ushort value);

/**
 * Check that `n` is a possible candidate for cell at `pos`.
 *
 * Note: When checking for `n == 0`, this function will ALWAYS return `CELL_OK`,
 * as setting a cell to `0` is like erasing its content and is not limited by
 * the rules of the game.
 *
 * Returns
 *  - `CELL_OK` → Cell at `pos` can be set to `n`
 *  - `CELL_KO` → Cell at `pos` cannot be set to `n`
 */
cell_status_t cell_get_status(ushort n, vector2d_t pos);

/**
 * Get the origin point (top left corner) of the square containing the cell at
 * given `pos`, and store it into `origin`.
 *
 * Returns
 *  - `CELL_OK` → Success
 *  - `CELL_KO` → Something went wrong
 */
cell_status_t cell_get_square(vector2d_t cell, vector2d_t *origin);

/**
 * Check that a row contains `n`
 */
short row_has(ushort row, ushort n);

/**
 * Check that a column contains `n`
 */
short col_has(ushort col, ushort n);

/**
 * Check that the square `pos` is part of contains `n`
 */
short square_has(vector2d_t pos, ushort n);

#endif // MATRIX_H
