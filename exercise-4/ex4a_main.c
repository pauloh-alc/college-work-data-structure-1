#include <stdio.h>
#include "division_method.h"

#define N 1000000
#define M 100000
#define NAME_FILE "./files/1_milhao.txt"

int main (void) {
  
  unsigned int* keys = create_key_array (N, NAME_FILE);
  unsigned int number_of_collisions = create_hash_table (keys, N, M);
  printf("Number of collisions: %u \n", number_of_collisions);

  return 0;
}
