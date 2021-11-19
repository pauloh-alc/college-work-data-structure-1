#include <stdio.h>
#include <stdint.h>
#include "insertion_sort.h"

/*
 * ARQUIVO - contém as funções necessárias para a utilização do InsertionSort
 * AUTOR - Paulo Henrique Diniz de Lima Alencar
 * CURSO - CC
 *
 * 3) Implementar o InsertionSort.
 *
 */

unsigned int* insertion_sort (unsigned int* array, uint64_t size) {
  
  unsigned int key;
  int64_t i;

  for (uint64_t j = 1; j < size; j++) {
    key = array[j];
    i = j - 1;
      
    while (i >= 0 && array[i] > key) {
      array[i+1] = array[i];
      i = i - 1;
    }
    array[i+1] = key;
  }

  return array;
}

void show_sorted_array (unsigned int* array, uint64_t size) {
  printf("Sorted Array: [");
  for (uint64_t i = 0; i < size; i++) {
    printf("%u",array[i]);
    if (i != size - 1) printf(", ");
  }
  printf("]\n");
}
