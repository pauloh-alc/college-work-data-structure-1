#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "heapSort.h"

/* ARQUIVO HEADER - contem as funções necessária para a criação do HeapSort.
 * AUTOR - Paulo Henrique Diniz de Lima Alencar.
 * CURSO - CC
 *
 * 2) Implementar o HeapSort
 *
 */


/*
 * Função: responsável por criar uma estrutura do tipo Heap.
 * Entrada: tamanho máximo da heap.
 * Saída..: Heap.
 */
Heap* create_heap (uint64_t size) {
  Heap* heap = (Heap*) malloc(sizeof(Heap));
  heap -> table = (uint64_t*) malloc(sizeof(uint64_t) * (size + 1));
  heap -> size = size;
  heap -> length = 0;

  return heap;
}

/*
 * Função: responsável por retornar o filho esquerdo de determinado pai.
 * Entrada: indice do pai.
 * Saída..: indice do filho esquerdo.
 */
uint64_t left_son (uint64_t dad) {
  return 2 * dad;
}


/*
 * Função: responsável por retornar o filho direito de determinado pai.
 * Entrada: indice do pai.
 * Saída..: indice do filho direito.
 */
uint64_t right_son (uint64_t dad) {
  return 2 * dad + 1;
}

/* Procedimento: reponsável por exibir array que foi ordenado pelo heapSort
 * Entrada: array, tamanho do array
 * Saída..: exibe array
 */
void show_sorted_array_heap (uint64_t* array, uint64_t size) {
  printf("Sorted Array: \n");
  for (uint64_t i = 1; i <= size; i++) {
    printf("%lu\n",array[i]);
  }
}

void free_memory (Heap* heap) {
  free(heap -> table);
  free(heap);
}


/* Procedimento: responsável por fazer a troca de determinados elementos na Heap
 * Entrada: indice do elemento 1, indice do elemento 2, heap
 * Saída..: ---------------
 */
void swap (uint64_t i, uint64_t j, Heap* heap) {
  uint64_t aux = heap -> table[i];
  heap -> table[i] = heap -> table[j];
  heap -> table[j] = aux;
}


/* Procedimento: responsável por descer na árvore binária (Heap)
 * Entrada.....: elemento que vai descer, heap
 * Saída ......: ---------
 * Complexidade: O(log n)
 */
void down (uint64_t dad, Heap* heap) {
  uint64_t j = left_son(dad);

  if (j <= heap -> length) {
    if (j < heap -> length) {
      if (heap -> table[right_son(dad)] > heap -> table[left_son(dad)])
        j += 1;
    }

    if (heap -> table[dad] < heap -> table[j]) {
      swap(dad, j, heap);
      down (j, heap);
    }
  }
}


/*
 * Procedimento: responsável por construir uma heap dado um vetor de elementos
 * Entrada: vetor de elementos, tamanho do vetor
 * Saída..: heap
 * Complexidade: O(n)
 */
Heap* build_heap (uint64_t* array, uint64_t size) {
  Heap* heap = create_heap(size);
  heap -> length = size;
  
  (heap -> table)++;
  heap -> table = array;
  (heap -> table)--; 
  
  for (uint64_t i = (heap->length) / 2; i >= 1; i--)
    down(i, heap);

  return heap;
}


/* Função: responsável por ordenar um vetor
 * Entrada: vetor, tamanho do vetor
 * Saída..: vetor ordenado
 * Complexidade: O(n-1) * O(log n) = O(n * log n)
 */
uint64_t* heapSort (uint64_t* array, uint64_t size) {
  Heap* heap = build_heap(array, size); // O(n)

  for (uint64_t i = heap -> length; i >= 2; i--) { // O(n-1)
    swap (1, i, heap);
    heap -> length = heap -> length - 1;
    down (1, heap); // O(log n)
  }
  return heap -> table;
}
