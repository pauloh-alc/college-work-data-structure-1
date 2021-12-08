#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#define SIZE_FILE 100000
#define NAME_FILE "cem_mil.txt"

#include "../exercise-3/insertion_sort.h"
#include "../exercise-2/heapSort.h"

enum options {
  HEAP_SORT_ = 1,
  INSERTION_SORT_ = 2,
  CLOSE_ = 3,
};

void menu () {
  puts("[1] Sort with the HeapSort");
  puts("[2] Sort with the Insertion-Sort");
  puts("[3] Exit");
}

void error (char* msg) {
 fprintf(stdout,"ERROR: %s!\n",msg);
}

uint64_t* load_elements_from_file(uint64_t amount_of_values) {
  FILE* file;
  uint64_t* array = (uint64_t *) malloc (sizeof(uint64_t) * amount_of_values); 
  uint64_t i = 0;

  if (!(file = fopen(NAME_FILE, "r"))) {
    error("error opening file");
    exit(1);
  }
  
  while (!(feof(file))) {
    fscanf(file, "%lu", &array[i]);
    i += 1;
  }
  fclose(file);

  return array;
}

void time_spent (clock_t start_time, clock_t final_time) {
  printf("Time taken to sort in milliseconds: %f ms\n", 1000*(double)(final_time - start_time) / (double) (CLOCKS_PER_SEC));
  printf("Time taken to sort in seconds: %f seconds\n\n", (double)(final_time - start_time) / (double) (CLOCKS_PER_SEC));
}

int main (void) {
  
  unsigned int option;

  while (true) {
    menu();
    printf("Enter the option: ");
    scanf("%u",&option);
    if (option == CLOSE_) break;
    
    clock_t start_time, final_time; 
    uint64_t* array = load_elements_from_file(SIZE_FILE);

    switch (option) {
      
      case HEAP_SORT_: { 
         start_time = clock();
         uint64_t* sorted_array = heapSort(array, SIZE_FILE);
         final_time = clock();
         //show_sorted_array_heap(sorted_array, SIZE_FILE);
         printf("\n\n---> %lu\n",sorted_array[0]);
         printf("-- Heap-Sort ---\n");
         time_spent(start_time, final_time);
      } break;

      case INSERTION_SORT_: {           
         start_time = clock();
         insertion_sort(array, SIZE_FILE);
         final_time = clock();
         //show_sorted_array_insertion (array, SIZE_FILE);
         printf("-- Insertion-Sort ---\n");
         time_spent(start_time, final_time);
      } break;

      default: error("option invalid");
    }
  }

  return EXIT_SUCCESS;
}
