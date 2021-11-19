#include <stdio.h>
#include <stdlib.h>
#define size(array) (sizeof(array) / sizeof(array[0]))

#include "heapSort.h"

int main (void) {
  
  int array [] = {10,9,3,-9,2,6,3,1,4,1,1};
  int* sorted_array = heapSort(array, size(array));

  show_sorted_array(sorted_array, size(array));

  return 0;
}
