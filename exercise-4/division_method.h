#ifndef HASH_TABLE
#define HASH_TABLE

typedef struct hashTable {
  int* table;
  unsigned int m;
} HashTable;

void error (char* msg);
unsigned int generate_m (unsigned int n);
unsigned int localization (unsigned int key, unsigned int m);
unsigned int* create_key_array (unsigned int n, char* name_file);
unsigned int copulate_hash_table (HashTable* hash_table, unsigned local, unsigned int key, unsigned int* number_of_collisions);
unsigned int create_hash_table (unsigned int* keys, unsigned int n, unsigned int m);

#endif
