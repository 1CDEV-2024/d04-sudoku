#ifndef SUDOKU_H
#define SUDOKU_H

#include <sys/types.h>

#ifdef _WIN32

#include <conio.h>

#else

#include <stdio.h>
#define clrscr() printf("\e[1;1H\e[2J")

#endif // _WIN32

ushort generate_number(ushort limit);

/**
 * Return the pointer to a random character inside the string
 */
char *jump_to_ranom_char(char *s);

/**
 * For a given string of digits, pick one at random and remove it from the
 * string.
 *
 * Behaviour is undefined if the string contains anything else than digits.
 */
ushort pop_random_digit(char *digits);

#endif // SUDOKU_H
