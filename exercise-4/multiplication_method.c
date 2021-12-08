#include <stdio.h>
#include <stdlib.h>
#include "multiplication_method.h"

#define NOT_BUSY -1

/*
 * Metodo da multiplicacao
 *
 * h(x) = x^2 (pegar o digito central gerado da potencia de 2)
 *
 * Ex: H(12) = 12^2 --> 144 --> 4 é o digito central.
 *
 */


void error (char* msg) {
  fprintf(stdout, "ERROR: %s!\n",msg);
}


unsigned int number_of_digits (unsigned int key) {
  
  unsigned int count = 0;

  if (key == 0) return 1;

  while (key != 0) {
    key = key / 10;
    count += 1;
  }

  return count;
}


unsigned int get_central_digit (unsigned int x) {
  
  unsigned int index_central_digit = number_of_digits(x) / 2;
  
  unsigned int rest, i = 0;
  while (i <= index_central_digit) {
    rest = x % 10;
    x = x / 10;
    i += 1;
  }
  
  return rest;
}


unsigned int localization (unsigned int key) {
  return get_central_digit(key * key);
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
  else 
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
  
  return number_of_collisions;
}

