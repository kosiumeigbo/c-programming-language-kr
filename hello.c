#include <stdio.h>

long int unsigned_max_value(char num_type[]);

int main() { return 0; }

long int unsigned_max_value(char num_type[]) {
  int base = 2;
  int pow;
  if (num_type == "char") {
    pow = 8;
  } else if (num_type == "short") {
    pow = 16;
  } else if(num_type == "int"){
    pow = 32;
  } else if(num_type == "long"){
    
  }
}