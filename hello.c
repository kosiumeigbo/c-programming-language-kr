#include <stdio.h>

#define IS_NON_WORD 1
#define IS_WORD 0

main() {
  int c, i, j, k;
  int word_state = IS_NON_WORD;
  int wlengthcounter = 0;
  int allowed_words = 10;
  char words[allowed_words];

  for (i = 0; i < allowed_words; ++i) {
    words[i] = 0;
    printf("0");
  }
  printf("\n");

  while ((c = getchar()) != EOF && wlengthcounter < allowed_words) {
    if (c != ' ' && c != '\n' && c != '\t') {
      ++words[wlengthcounter];
      word_state = IS_WORD;
    } else if (word_state == IS_WORD) {
      ++wlengthcounter;
      word_state = IS_NON_WORD;
    }
  }

  for (j = 0; j < allowed_words; ++j) {
    if (words[j] == 0) {
      printf("No words\n");
    } else {
      for (k = 0; k < words[j]; ++k) {
        printf("|");
      }
      printf("\n");
    }
  }
}