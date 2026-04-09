#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */
main() {
  int len;               /* current line length */
  int max;               /* maximum length seen so far */
  char line[MAXLINE];    /* current input line */
  char longest[MAXLINE]; /* longest line saved here */
  int i;

  max = 0;
  while ((len = get_line(line, MAXLINE)) > 0) {
    char s;
    printf("Length of line input: %d\n", len);
    if (len >= MAXLINE) {
      printf("The line input is longer than the line array:\n");
      printf("The line input is obviously also greater than 80 characters:\n");
      for (i = 0; i < (MAXLINE - 1); ++i) {
        s = line[i];
        printf("%c", s);
      }
      printf("\n");
    } else if (len > 80) {
      printf("The line input is the same as or shorter than the linearray and also greater than 80 characters:\n");
      for (i = 0; i < len; ++i) {
        s = line[i];
        printf("%c", s);
      }
    }
  }

  return 0;
}

/* get_line: read a line into s, return length */
int get_line(char line[], int maxline) {
  int i;
  char c;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
    if (i < maxline - 1) {
      line[i] = c;
    }
  }

  if (c == '\n') {
    if (i < maxline - 1) {
      line[i] = c;
      ++i;
    }
  }

  if (i < maxline) {
    line[i] = '\0';
  } else {
    line[maxline - 1] = '\0';
  }

  return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
  int i;
  i = 0;

  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}