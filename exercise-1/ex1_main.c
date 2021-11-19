#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#define size(array) (sizeof(array) / sizeof(array[0]))

#include "heap.h"

void show_array (int* array, int size);

int main (void) {

  // 10 é a capacidade da minha heap
  Heap* heap = create_heap(10);
  insertion(1,heap);
  insertion(15,heap);
  insertion(0,heap);
  insertion(21,heap);
  insertion(2,heap);
  insertion(8,heap);
  insertion(34,heap);
  insertion(5,heap);
  insertion(3,heap);
  insertion(1,heap);
  
  /*
  Outro exemplo para inserção
  insertion(1,heap);
  insertion(2,heap);
  insertion(3,heap);
  insertion(4,heap);
  insertion(5,heap);
  insertion(5,heap);
  insertion(6,heap);
  insertion(7,heap);
  insertion(8,heap);
  insertion(8,heap);
  insertion(9,heap);
  insertion(10,heap);
  insertion(11,heap);
  insertion(13,heap);
  insertion(12,heap);
  */
  
  /*
  Outro exemplo para ser usado:
  insertion(4,heap);
  insertion(2,heap);
  insertion(5,heap);
  insertion(1,heap);
  insertion(3,heap);
  insertion(6,heap);
  */
  
  // Mostrando a heap
  show_heap (heap); 

  // Removendo da heap
  to_remove (heap);
  
  // Mostrando heap após a remoção
  printf("-- Heap after removal --\n");
  show_heap (heap);
  
  free_memory (heap); 

  
  //............................................
  
  // Array para construção da Heap
  int array[] = {1,2,3,4,5,5,6,7,8,8,9,10,11,12};
  printf("\n\n-- Building Heap -- \n");
  build_heap(array, size(array));
    
  // Ordenando vetor 'vet' com Heap Sort 
  int vet[] = {4,2,5,1,3,6,1,1,-3,-3};
  printf("\n\n-- Heap Sort --\n");
  show_array (vet, size(vet));
  int* sorted_array = heap_sort(vet, size(vet));
   
  // Mostrando array ordenando com Heap Sort
  show_sorted_array (sorted_array, size(vet));
  
  return EXIT_SUCCESS;
}


void show_array (int* array, int size) {
  printf("Array: [");
  for (int i = 0; i < size; i++) {
    printf("%d",array[i]);
    if (i != size - 1) printf(", ");
  }
  printf("]\n");
}
