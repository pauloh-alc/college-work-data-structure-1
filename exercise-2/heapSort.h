#ifndef HEAP_SORT
#define HEAP_SORT

typedef struct heap {
  int* table;
  unsigned int size;
  unsigned int length;
} Heap;


int left_son (int dad);
int right_son (int dad);
Heap* create_heap (unsigned int size);
void swap (int i, int j, Heap* heap);
void down (int dad, Heap* heap);
Heap* build_heap (int* array, int size);
int* heapSort (int* array, int size);
void free_memory (Heap* heap);
void show_sorted_array (int* array, int size);

#endif
