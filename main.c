#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "generator/generator.h"
#include "grid/grid.h"
#include "sudoku.h"

typedef struct {
  char *name;
  size_t len;
  ushort cells_to_remove;
} difficulty_t;

#define _(n, r)                                                                \
  { .name = (n), .len = strlen((n) ?: ""), .cells_to_remove = (r) }

static const difficulty_t DIFFICULTY[] = {
    _("Easy", 44),
    _("Medium", 48),
    _("Hard", 52),
    _("Harder", 56),
    _("I regret my life choices", 60),
    _("Please stop", 64),
    _("WTF", 80),
    _(NULL, 0),
};

static const difficulty_t *pick_difficulty(void) {
  ushort max = 0;
  while (DIFFICULTY[max].name != NULL)
    max += 1;
  assert(max); // Must have at least one difficulty available

  ushort pick = 0;
  char *line = NULL;
  size_t linesz = 0;

  do {
    clrscr();
    printf("Please pick a difficulty:\n");
    for (short i = 0; i < max; i += 1)
      printf("  > % 2hi -> %s\n", i + 1, DIFFICULTY[i].name);
    if (getline(&line, &linesz, stdin) == EOF)
      break;
    pick = strtoul(line, NULL, 10);
  } while (pick > max || pick == 0);

  free(line);
  return &(DIFFICULTY[pick - 1]);
}

static void print_difficulty(const difficulty_t *diff) {
  char buffer[diff->len + 1];

  memset(buffer, '-', diff->len);
  buffer[diff->len] = '\0';

  printf("+-------------%s-+\n"
         "| Difficulty: %s |\n"
         "+-------------%s-+\n",
         buffer, diff->name, buffer);
}

int main(void) {
  const difficulty_t *diff = pick_difficulty();

  generate(diff->cells_to_remove);

  clrscr();
  print_difficulty(diff);
  grid_print(0);
  return 0;
}
