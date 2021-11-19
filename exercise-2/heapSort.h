#ifndef HEAP_SORT
#define HEAP_SORT

#include <stdint.h>

typedef struct heap {
  uint64_t* table;
  uint64_t size;
  uint64_t length;
} Heap;


uint64_t left_son (uint64_t dad);
uint64_t right_son (uint64_t dad);
Heap* create_heap (uint64_t size);
void swap (uint64_t i, uint64_t j, Heap* heap);
void down (uint64_t dad, Heap* heap);
Heap* build_heap (uint64_t* array, uint64_t size);
uint64_t* heapSort (uint64_t* array, uint64_t size);
void free_memory (Heap* heap);
void show_sorted_array (uint64_t* array, uint64_t size);

#endif
