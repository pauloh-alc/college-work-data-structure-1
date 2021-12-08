#ifndef HASH_TABLE
#define HASH_TABLE

typedef struct hashTable {
  int* table;
  unsigned int m;
} HashTable;

void error (char* msg);
unsigned int number_of_digits (unsigned int key);
unsigned int get_central_digit (unsigned int x);
unsigned int localization (unsigned int key);
unsigned int* create_key_array (unsigned int n, char* name_file);
void copulate_hash_table (HashTable* hash_table, unsigned local, unsigned int key, unsigned int* number_of_collisions);
unsigned int create_hash_table (unsigned int* keys, unsigned int n, unsigned int m);

#endif
