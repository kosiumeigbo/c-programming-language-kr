#include <stdio.h>

#define BLANK_CHAR 1
#define NON_BLANK_CHAR 0

main() {
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      putchar('\\');
      putchar('t');
    }
    if (c == '\b') {
      putchar('\\');
      putchar('b');
    }
    if (c == '\\') {
      putchar('\\');
      putchar('\\');
    } else {
      putchar(c);
    }
  }
}