#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "heap.h"

/* ARQUIVO HEADER - possui as principais funções e procedimentos para implementação do Heap Máximo
 * AUTOR - Paulo Henrique Diniz de Lima Alencar
 * CURSO - CC
 *
 * 1) Considere Heap Maximo. Implementar as funcoes a seguir: subir, descer, inserir, remover e construir.
 *
 */


/*
 * Procedimento resposn'avel por exibir raiz removida do heap max
 */
void act(int element) {
  printf("\nElement removed: %d\n\n",element);
}


/*/
 * Procedimento: responsável por exibir mensagens de erro
 */
void error (char* msg) {
  fprintf(stdout, "Error: %s!\n",msg);
}


/*
 * Procedimento: responsável por mostrar cada elemento presente em minha Heap.
 * Entrada: Heap
 * Complexidade: O(n)
 */
void show_heap (Heap* heap) {
  printf("My Heap: [");
  for (int i = 1; i <= heap -> length; i++) {
    printf("%d",heap -> table[i]);
    if (i != heap->length) printf(", ");
  }
  printf("]\n");
}


/* Procedimento: responsavel por exibir array ordenado pelo heapSort
 * Entrada: array, tamanho do array
 * Saida..: ----------------------
 */
void show_sorted_array (int* array, size_t size) {
  printf("Sorted array: [");
  for (int i = 1; i <= size; i++) {
    printf("%d",array[i]);
    if (i != size) printf(", ");
  }
  printf("]\n");
}


/* Procedimento: responsável por desalocar memória da Heap.
 * Entrada: heap
 * Saída..: --------------
 */
void free_memory (Heap* heap) {
  free(heap -> table);
  free(heap);
}

/*
 * Função: responsável por criar uma estrutura do tipo Heap.
 * Entrada: tamanho máximo da heap.
 * Saída..: Heap composta por (tabela, capacidade e comprimento) 
 */
Heap* create_heap (unsigned int size) {
  Heap* heap = (Heap*) malloc(sizeof(Heap));
  heap -> table = (int*) malloc(sizeof(int) * (size + 1));
  heap -> size = size;
  heap -> length = 0;
  
  return heap;
}


/*
 * Função: responsável por retornar o pai de determinado filho
 * Entrada: filho
 * Saída..: pai
 */
int father(int son) {
  return son / 2;
}


/* Função: resposável por retornar o filho esquerdo de determinado pai
 * Entrada: pai
 * Saída..: filho esquerdo
 */
int left_son (int dad) {
  return 2 * dad;
}


/* Função: responsável por retornar o filho direito de determinado pai
 * Entrada: pai
 * Saída..: fillho direito
 */
int right_son (int dad) {
  return left_son(dad) + 1;
}


/* Procedimento: responsável por fazer a troca de determinados elementos na Heap
 * Entrada: filho, pai, heap
 * Saída..: ---------------
 */
void swap (int son, int dad, Heap* heap) {
  int aux = heap -> table[dad];
  heap -> table[dad] = heap -> table[son];
  heap -> table[son] = aux;
}


/* Procedimento: responsável por descer na árvore binária (Heap)
 * Entrada.....: elemento que vai descer, heap
 * Saída ......: ---------
 * Complexidade: O(log n)
 */
void down (int dad, Heap* heap) {
  int j = left_son(dad);
  
  if (j <= heap -> length) {
    if (j < heap -> length) {
      if (heap->table[right_son(dad)] > heap->table[left_son(dad)]) {
        j += 1; 
      }
    }

    if (heap->table[dad] < heap->table[j]) {
      swap(dad, j, heap);
      down (j, heap);
    }
  }
}


/* Procedimento: responsável por subir na árvore binária (Heap)
 * Entrada: elemento que vai subir, heap
 * Saída..: ---------------------------
 * Complexidade: O(log n)
 */ 
void up (int son, Heap* heap) {

  int dad = father(son);
     
  if (dad > 0) { 
    if (heap->table[son] > heap->table[dad]) {
      swap(son, dad, heap);    
      up(dad, heap); 
    }
  }
}


/* Função: responsável por inserir um elemento na heap.
 * Entrada: elemento a ser inserido, heap
 * Saída..: booleano indicando se o elemento foi ou não inserido com sucesso.
 * Complexidade: O(log n)
 */
bool insertion (int element, Heap* heap) {
  if (heap -> length < heap -> size) {
    heap -> length += 1;
    heap -> table[heap->length] = element; 
    up(heap -> length, heap); // O(log n)
  } 
  else {
    error("Overflow");
    return false;
  }
  return true;
}


/*
 * Função: responsável por remover o elemento de maior rpioridade da minha heap (raiz, isto elemento na posicao 1).
 * Entrada: Heap
 * Saída..: booleano indicando se o elemento foi ou não removido
 * Complexidade: O(log n)
 */
bool to_remove (Heap* heap) {
  if (heap -> length != 0) {
    act(heap -> table[1]);
    heap -> table[1] = heap -> table[heap->length];
    heap -> length -= 1;
    down (1, heap); // O(log n)
  }
  else {
    error("Underflow");
    return false;
  }
  return true;
}


/*
 * Procedimento: responsável por construir uma heap dado um vetor de elementos
 * Entrada: vetor de elementos, tamanho do vetor
 * Saída..: heap
 * Complexidade: O(n)
 */
Heap* build_heap (int* array, int size_array) {
  Heap* heap = create_heap(size_array);
  heap -> length = size_array;
  
  int j = 0;
  for (int i = 1; i <= size_array; i++) {
    heap -> table[i] = array[j];
    j++;
  }
  
  for (int i = (heap->length) / 2; i >= 1; i--) {
    down(i, heap); // O(log n)
  }
  
  show_heap(heap);

  return heap;
}
/* Procedimento: responsavel por realizar uma copia, de um vetor para outro
 * Entrada: array 1 e array 2
 * Saida..: -----------------
 */
void copy (int* array_1, int* array_2, int size) {
  for (int i = 1; i <= size; i++)
    array_1[i] = array_2[i];
}


/* Função: responsável por ordenar um vetor
 * Entrada: vetor, tamanho do vetor
 * Saída..: vetor ordenado
 * Complexidade: O(n-1) * O(log n) = O(n * log n)
 */
int* heap_sort (int* array, int size_array) {
  Heap* heap = build_heap (array, size_array); // O(n) 
  
  for (int i = heap -> length; i >= 2; i--) { // O(n-1) continua sendo O(n)
    swap (1, i, heap);
    heap -> length = heap -> length - 1;
    down (1, heap); // O(log n)
  }
  
  int* sorted_array = (int*) malloc (sizeof(int) * (size_array + 1));
  copy (sorted_array, heap -> table, size_array);
  
  free_memory (heap);

  return sorted_array;
}
