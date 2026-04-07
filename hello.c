#include <stdio.h>

// #define IS_NON_WORD 1
// #define IS_WORD 0

main() {
  int c, i, j;
  int arraylength = 12;
  int index_white = arraylength - 2;
  int index_other = arraylength - 1;
  int ndigit[arraylength];

  for (i = 0; i < arraylength; ++i) {
    ndigit[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c >= '0' && c <= '9') {
      ++ndigit[c - '0'];
    } else if (c == ' ' || c == '\n' || c == '\t') {
      ++ndigit[index_white];
    } else {
      ++ndigit[index_other];
    }
  }

  for (i = 0; i < arraylength; ++i) {
    if (ndigit[i] == 0) {
      printf("No input for this character\n");
    } else {
      if (i == index_white) {
        printf("White space:\t");
      } else if (i == index_other) {
        printf("Other char:\t");
      } else {
        printf("%d:\t", i);
      }

      for (j = 0; j < ndigit[i]; ++j) {
        printf("|");
      }
      printf("\n");
    }
  }
}