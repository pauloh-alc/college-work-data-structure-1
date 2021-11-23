#include <stdio.h>
#include <stdlib.h>
#define size(array) (sizeof(array) / sizeof(array[0]))

#include "insertion_sort.h"

int main (void) {
  
  //uint64_t array[] = {10,9,3,9,2,6,3,1,4,1,1,5,4,4,1,1};
  //uint64_t array[] = {1};
  //uint64_t array[] = {1,2,3,9,8,7};
  //uint64_t array[] = {5,6,1,9,4,4};
  //uint64_t array[] = {1,1,1,9,500,890};
  //uint64_t array[] = {1,4,2,9,3,3};

  insertion_sort(array, size(array));
    
  show_sorted_array_insertion(array, size(array));
  
  return 0;
}
