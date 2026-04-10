#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
int clean_line(int start_length, char start_line[], char end_line[]);

/* print only non-empty lines */
int main(void) {
  int len;                  /* current line length */
  int clean_line_length;    /* length of line after cleaning */
  char line_input[MAXLINE]; /* current input line */
  char line_clean[MAXLINE]; /* current cleaned line saved here */

  while ((len = get_line(line_input, MAXLINE)) > 0) {
    printf("Length of line input: %d\n", len);
    clean_line_length = clean_line(len, line_input, line_clean);
    printf("Length of clean line: %d\n", clean_line_length);
    if (clean_line_length == 0) {
      printf("This is not a valid line to print because the clean version is empty\n");
    } else if (clean_line_length == 1 && line_clean[clean_line_length - 1] == '\n') {
      printf("This is not a valid line to print because the clean version contains only 1 \\n\n");
    } else if (clean_line_length == 1 && line_clean[clean_line_length - 1] != '\n') {
      printf("This is a valid line to print because the cleaned version is not empty\n");
      printf("%s\n", line_clean);
    } else {
      printf("This is a valid line to print because the cleaned version is not empty\n");
      printf("%s\n", line_clean);
    }
  }

  return 0;
}

/* get_line: read a line into s, return length (excluding null terminator) */
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
    return i;
  } else {
    line[maxline - 1] = '\0';
    return (maxline - 1);
  }
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
  int i;
  i = 0;

  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}

/* clean_line: remove trailing tabs and spaces from line input. 'start_length' excludes null terminator */
int clean_line(int start_line_length, char start_line[], char end_line[]) {
  int i;

  if (start_line[start_line_length - 1] == '\n') {
    i = start_line_length - 2;
    while (i >= 0 && ((start_line[i] == ' ') || (start_line[i] == '\t'))) {
      --i;
    }

    if (i == -1) {
      end_line[0] = '\n';
      end_line[1] = '\0';
      return i + 2;
    } else {
      int j;
      for (j = 0; j < i + 2; ++j) {
        end_line[j] = start_line[j];
      }
      end_line[j] = '\0';
      return j;
    }
  } else {
    i = start_line_length - 1;
    while (i >= 0 && ((start_line[i] == ' ') || (start_line[i] == '\t'))) {
      --i;
    }

    if (i == -1) {
      end_line[0] = '\0';
      return i + 1;
    } else {
      int j;
      for (j = 0; j < i + 1; ++j) {
        end_line[j] = start_line[j];
      }
      end_line[j] = '\0';
      return j;
    }
  }
}
