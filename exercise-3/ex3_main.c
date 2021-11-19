#include <stdio.h>
#include <stdlib.h>
#define size(array) (sizeof(array) / sizeof(array[0]))

#include "insertion_sort.h"

int main (void) {
  
  unsigned int array [] = {10,9,3,9,2,6,3,1,4,1,1,5,4,4,1,1};
  insertion_sort(array, size(array));
    
  show_sorted_array(array, size(array));
  
  return 0;
}
