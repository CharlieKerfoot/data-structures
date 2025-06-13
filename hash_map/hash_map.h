#ifndef HASHMAP_H
#define HASHMAP_H

#include "../linked_value/linked_value.h"

typedef struct hashmap hashmap;

unsigned int hash(char *str, int table_size);
hashmap *create_map(int size);
void add_value(hashmap *map, linked_value *v);
int get_data(hashmap *map, char *name);
void delete_value(hashmap *map, char *name);
float get_load_factor(hashmap *map);
int get_size(hashmap *map);
void rehash(hashmap *map);
void print_map(hashmap *map);
void free_map(hashmap *map);

#endif
