#include <stdio.h>

#define IS_NON_WORD 1
#define IS_WORD 0

main() {
  int c;
  int wordState = IS_NON_WORD;

  while ((c = getchar()) != EOF) {
    if (c != ' ') {
      putchar(c);
      wordState = IS_WORD;
    } else if (wordState == IS_WORD) {
      wordState = IS_NON_WORD;
      putchar('\n');
    }
  }
}