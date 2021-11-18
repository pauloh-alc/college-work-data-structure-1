#ifndef HEAP
#define HEAP

#include <stdbool.h>
#include <stdint.h>

typedef struct heap {
  int* table;
  unsigned int size;
  unsigned length;
} Heap;

void act();
void error (char* msg);
int father (int i);
void show_heap (Heap* heap);
void show_sorted_array (int* array, size_t size);
void swap (int son, int dad, Heap* heap);
void down (int dad, Heap* heap);
void up (int son, Heap* heap);
bool insertion (int element, Heap* heap);
bool to_remove (Heap* heap);
Heap* build_heap (int* array, int size_array);
int* heap_sort (int* array, int size_array);
void free_memory (Heap* heap);
Heap* create_heap (unsigned int size);
void copy (int* array_1, int* array_2, int size);

#endif
