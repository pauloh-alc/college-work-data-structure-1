#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "division_method.h"

#define NOT_BUSY -1

/*
 * Metodo da divisao:
 *
 * m - tamanho da tabela
 *   * m's ruins: m par, m potencia de 2
 *   * m's bons.: m impar, m primo, nao proximo de uma potencia de 2, m nao possui divisores primos menores que 20
 *
 *  A principio pensei que fosse para gerar uma tabela com o 'm' ideial, mas depois entendi que o senhor pediu tabela com tamanho fixo em 100 mil
 *  por isso acabei fazendo algumas funções para gerar esse 'm' 
 */


void error (char* msg) {
  fprintf(stdout, "ERROR: %s!\n",msg);
}

unsigned char even_or_odd (unsigned int number) {
  if (number % 2 == 0) return 0;
  return 1;
}

unsigned char prime (unsigned int number) {
  for (unsigned int i = 2; i <= sqrt(number); i++) {
    if (number % i == 0) return 0;
  }
  return 1;
}

unsigned char prime_divisors_less_than_20 (unsigned number) {
  unsigned int primes[] = {2,3,5,7,11,13,17,19};

  for (unsigned int i = 0; i < 8; i++) 
    if (number % primes[i] == 0) return 0;

  return 1;
}

unsigned int generate_m (unsigned int n) {
  unsigned int m = n;
  
  while (true) {
    if (prime(m) && even_or_odd(m) && prime_divisors_less_than_20(m)) {
      return m;
    }
    m = m + 1;
  }
}


unsigned int localization (unsigned int key, unsigned int m) {
  return key % m;
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


unsigned int copulate_hash_table (HashTable* hash_table, unsigned local, unsigned int key, unsigned int* number_of_collisions) {
  
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
    copulate_hash_table (hash_table, localization(keys[i], hash_table->m), keys[i], &number_of_collisions);

  free(keys);
  
  return number_of_collisions;
}

