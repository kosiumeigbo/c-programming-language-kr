#include <stdio.h>

#define MAXLINE 1000 /* maximum input line length */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);
int clean_line(int start_length, char start_line[], char end_line[]);
int reverse(char input[], char output[]);

/* reverse all input lines */
int main(void) {
  int len;                          /* current line length */
  int len_reversed;                 /* reversed line length */
  char line_input[MAXLINE];         /* current input line */
  char line_input_reverse[MAXLINE]; /* reversed input line */

  while ((len = get_line(line_input, MAXLINE)) > 0) {
    printf("Length of line input: %d\n", len);
    len_reversed = reverse(line_input, line_input_reverse);
    printf("Line input reversed:%s\n", line_input_reverse);
    printf("Length of Line input reversed: %d\n", len_reversed);
  }

  return 0;
}

/* get_line: read a line into 'line', return length (excluding null terminator) */
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

/* reverse: reverse the line input and return the length (excluding null terminator) */
int reverse(char input[], char output[]) {
  int i = 0;

  while (input[i] != '\0') {
    ++i;
  }

  if (i == 0) {
    output[0] = '\0';
    return 0;
  } else {
    output[i] = '\0';
    int j;
    for (j = 0; j < i; ++j) {
      output[j] = input[(i - 1) - j];
    }
    return i;
  }
}
