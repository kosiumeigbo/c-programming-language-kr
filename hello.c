#include <limits.h>
#include <stdio.h>

long unsigned_max_value(char type, char qual);

int main() {
  printf("for unsigned char: 0 to %ld\n", (unsigned_max_value('c', 'U') - 1));
  printf("for unsigned short: 0 to %ld\n", (unsigned_max_value('s', 'U') - 1));
  printf("for unsigned int: 0 to %ld\n", (unsigned_max_value('i', 'U') - 1));
  printf("for unsigned long: 0 to %ld\n", (unsigned_max_value('l', 'U') - 1));
  printf("for signed char: -%ld to %ld\n", (unsigned_max_value('c', 'S')), (unsigned_max_value('c', 'S') - 1));
  printf("for signed short: -%ld to %ld\n", (unsigned_max_value('s', 'S')), (unsigned_max_value('s', 'S') - 1));
  printf("for signed int: -%ld to %ld\n", (unsigned_max_value('i', 'S')), (unsigned_max_value('i', 'S') - 1));
  printf("for signed long: -%ld to %ld\n", (unsigned_max_value('l', 'S')), (unsigned_max_value('l', 'S') - 1));
  return 0;
}

long unsigned_max_value(char type, char qual) {
  int pow;
  int i;
  long base = 2;
  long tmp = 1;

  if (qual == 'U') {
    if (type == 'c') { /* char */
      pow = 8;
    } else if (type == 's') { /* short */
      pow = 16;
    } else if (type == 'i') { /* int */
      pow = 32;
    } else if (type == 'l') { /* long */
      pow = 32;
    } else {
      pow = 0;
    }
  } else if (qual == 'S') {
    if (type == 'c') { /* char */
      pow = 7;
    } else if (type == 's') { /* short */
      pow = 15;
    } else if (type == 'i') { /* int */
      pow = 31;
    } else if (type == 'l') { /* long */
      pow = 31;
    } else {
      pow = 0;
    }
  } else {
    pow = 0;
  }

  for (i = pow; i > 0; --i) {
    tmp = tmp * base;
  }
  return tmp;
}