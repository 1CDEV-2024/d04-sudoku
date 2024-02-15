#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SEED time(NULL)

/**
 * When testing, I like the results to be predictable. That's why I sometimes
 * set my own seeds.
 */
// #define SEED 23

/**
 * This function ensures *uniformity*.
 *
 * When doing `rand() % max`, if `max < RAND_MAX`, then there will be higher
 * results more often, whereas with `max > RAN_MAX` you will get lower results
 * more often.
 *
 * Using the divisor and rand loop trick, this is no longer a problem, as we
 * will wait to find an initial result within a multiple of `max`.
 *
 * See
 * https://stackoverflow.com/questions/2999075/generate-a-random-number-within-range/2999130#2999130
 */
ushort generate_number(ushort limit) {
  static short seed_is_set = 0;
  if (seed_is_set == 0) {
    srand(SEED);
    seed_is_set = 1;
  }

  ushort result = 0;
  // Note: we want the limit to be exclusive so no `+1` here
  unsigned divisor = RAND_MAX / limit;

  do {
    result = rand() / divisor;
  } while (result > limit);

  return result;
}

char *jump_to_ranom_char(char *s) {
  size_t limit = strlen(s);
  size_t n = generate_number(limit);
  return s + n;
}

ushort pop_random_digit(char *digits) {
  ushort n = 0;

  digits = jump_to_ranom_char(digits);
  n = *digits - '0';
  do {
    digits[0] = digits[1];
  } while (*digits++);

  return n;
}
