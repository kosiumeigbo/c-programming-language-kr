#include <stdio.h>

#define BLANK_CHAR 1
#define NON_BLANK_CHAR 0

main() {
  int c;
  int state = NON_BLANK_CHAR;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (state == NON_BLANK_CHAR) {
        state = BLANK_CHAR;
        putchar(c);
      }
    } else {
      state = NON_BLANK_CHAR;
      putchar(c);
    }
  }
}