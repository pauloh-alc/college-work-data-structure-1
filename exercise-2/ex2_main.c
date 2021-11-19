#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define size(array) (sizeof(array) / sizeof(array[0]))

#include "heapSort.h"

int main (void) {
  
  uint64_t array [] = {10,9,300000,9,2,6,3,1,4,1,1,4,2,1000};
  int64_t * sorted_array = heapSort(array, size(array));

  show_sorted_array(sorted_array, size(array));

  return 0;
}
