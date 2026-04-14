#include <limits.h>
#include <stdio.h>

long max_value(char type, char qual);

int main() {

  printf("Based on function:\n");
  printf("for unsigned char: 0 to %lu\n", (max_value('c', 'U') - 1));
  printf("for unsigned short: 0 to %lu\n", (max_value('s', 'U') - 1));
  printf("for unsigned int: 0 to %lu\n", (max_value('i', 'U') - 1));
  printf("for unsigned long: 0 to %lu\n", (max_value('l', 'U') - 1));
  printf("for signed char: -%lu to %ld\n", (max_value('c', 'S')), (max_value('c', 'S') - 1));
  printf("for signed short: -%lu to %ld\n", (max_value('s', 'S')), (max_value('s', 'S') - 1));
  printf("for signed int: -%lu to %ld\n", (max_value('i', 'S')), (max_value('i', 'S') - 1));
  printf("for signed long: -%lu to %ld\n", (max_value('l', 'S')), (max_value('l', 'S') - 1));
  printf("\n");
  printf("Based on limits.h\n");
  printf("for unsigned char: 0 to %u\n", UCHAR_MAX);
  printf("for unsigned short: 0 to %u\n", USHRT_MAX);
  printf("for unsigned int: 0 to %u\n", UINT_MAX);
  printf("for unsigned long: 0 to %lu\n", ULONG_MAX);
  printf("for signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
  printf("for signed short: %d to %d\n", SHRT_MIN, SHRT_MAX);
  printf("for signed int: %d to %d\n", INT_MIN, INT_MAX);
  printf("for signed long: %ld to %ld\n", LONG_MIN, LONG_MAX);
  return 0;
}

long max_value(char type, char qual) {
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
      pow = 64;
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
      pow = 63;
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