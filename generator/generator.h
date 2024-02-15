#ifndef GENERATOR_H
#define GENERATOR_H

#include "../matrix/matrix.h"

/**
 * Generate a full solvable board with `rm` cells empty
 */
void generate(ushort rm);

/**
 * Randomly fill a square with digits from 1 to 9
 */
void generate_square(vector2d_t origin);

/**
 * Generate an initial diagonal of three randomly filled squares
 */
void generate_diagonal(void);

#endif // GENERATOR_H
