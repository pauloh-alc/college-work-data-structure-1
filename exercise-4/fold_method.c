#include <stdio.h>
#include <stdlib.h>
#include "fold_method.h"

#define NOT_BUSY -1

/*
 * Metodo da dobra
 *
 * Ex:
 *
 * [8][1][3][4][5][9]
 * 
 * Realizando a dobra de dois em dois
 *
 * primeira dobra --> [4][2][5][9]
 * segunda dobra ---> [7][3]
 * 
 * concatena 7 e 3 --> 73 é meu endereço 
 */


void error (char* msg) {
  fprintf(stdout, "ERROR: %s!\n",msg);
}


unsigned int sum (unsigned int a, unsigned int b) {

  if ((a + b) > 9) {
    return (a + b) % 10; 
  }

  return a + b;
}


unsigned int len (unsigned int number) {
  if (number == 0) return 1;
  
  unsigned int count = 0;
  
  while (number != 0) {
    number = number / 10;
    count += 1;
  }
  return count;
}


unsigned int* put_digits_in_array (unsigned int number) {
  
  unsigned int rest;
  unsigned int amount = len(number);
  
  unsigned int* key;
  if (amount % 2 == 0) key = (unsigned int*) malloc (sizeof(unsigned int) * amount);
  else                 key = (unsigned int*) malloc (sizeof(unsigned int) * (amount + 1));

  while (number != 0) {
    rest = number % 10;
    number = number / 10;
    key[amount-1] = rest;
    amount -= 1;
  }
  
  return key;
}


unsigned int concatenete_int (unsigned int a, unsigned int b) {
  return a * 10 + b;
}


unsigned int fold (unsigned int* key, unsigned int size, unsigned int size_fold) {
  if (size % 2 != 0) key[size] = 0;
  
  unsigned int i = 0, aux;

  for (unsigned int j = 2; j < size; j += size_fold) {
    i = 0;
    aux = key[i+1];
    key[i+1] = sum(key[i], key[j+1]);
    i += 1;
    key[i-1] = sum(aux, key[j]);
  }
  unsigned int a = key[0];
  unsigned int b = key[1];
  
  free(key);

  return concatenete_int (a, b);
}


unsigned int localization (unsigned int key) {
  return fold(put_digits_in_array(key), len(key), 2);
}


unsigned int* create_key_array (unsigned int n, char* name_file) {
  unsigned int *keys = (unsigned int*) malloc (sizeof(unsigned int) * n);
  unsigned int i = 0;
  FILE* file;
  
  if (!(file = fopen(name_file, "r"))) {
    error("error opening file");
    exit(1);
  }  
    
  while (!(feof(file))) {
    fscanf(file,"%u\n", &keys[i]);
    i += 1;
  } 
  
  fclose(file);
  
  return keys;
}


void copulate_hash_table (HashTable* hash_table, unsigned int local, unsigned int key, unsigned int* number_of_collisions) {
  
  if (hash_table -> table[local] == NOT_BUSY)
    hash_table -> table[local] = key;
  else if (local < hash_table -> m && hash_table -> table[local] != NOT_BUSY)
    *number_of_collisions += 1;
}


unsigned int create_hash_table (unsigned int* keys, unsigned int n, unsigned int m) {
  HashTable* hash_table = (HashTable *) malloc (sizeof(HashTable));
  hash_table -> m = m;
  hash_table -> table = (int*) malloc (sizeof(int) * (hash_table -> m));

  unsigned int number_of_collisions = 0;

  for (unsigned int i = 0; i < hash_table -> m; i++)
    hash_table -> table[i] = -1;
  
  for (unsigned int i = 0; i < n; i++) 
    copulate_hash_table (hash_table, localization(keys[i]), keys[i], &number_of_collisions);

  free(keys);
  
  /*   
  for (int i = 0; i < m; i++) {
    printf("[%d] -> %d\n",i, hash_table -> table[i]);
  }
  */
  return number_of_collisions;
}

