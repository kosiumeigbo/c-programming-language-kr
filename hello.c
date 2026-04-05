#include <stdio.h>

main() {
  int nb = 0;
  int nt = 0;
  int nl = 0;
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++nb;
    }
    if (c == '\t') {
      ++nt;
    }
    if (c == '\n') {
      ++nl;
    }
  }
  printf("Number of blanks is: %d\n", nb);
  printf("Number of tabs is: %d\n", nt);
  printf("Number of lines is: %d\n", nl);
}