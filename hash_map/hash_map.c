#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../linked_value/linked_value.h"
#include "hash_map.h"
#include "../errors/error.h"

struct hashmap {
	int count; // number of elements currently filled
	int size;
	linked_value** buckets; 
};

unsigned int hash(char *str, int table_size) {
	if (!str) {
		throw_error("String Does Not Exist");
	}

	// djb2 hash function
	unsigned int hash_code = 5381;
	
	int c;
	while((c = *str++)) {
		hash_code = ((hash_code << 5) + hash_code) + c; // 33 * hash_code + c
	}

	return hash_code % table_size;
}

hashmap *create_map(int size) {
	hashmap *map = malloc(sizeof(hashmap));
	map->buckets = calloc(size, sizeof(linked_value*));
	map->count = 0;
	map->size = size;

	if (!map || !map->buckets) {
		throw_error("Memory Allocation Failed");
	}
	
	return map;
}


void add_value(hashmap *map, linked_value *lv) {
	if (!map || !map->buckets) {
		throw_error("Map Does Not Exist");
	}

	if (!lv || !lv->val) {
		throw_error("Value Does Not Exist");
	}

	if (get_load_factor(map) >= 1) rehash(map);

	int key = hash(lv->val->name, map->size);
	linked_value *bucket = map->buckets[key];

	if (!bucket) {
		map->buckets[key] = lv;
	}else {
		while (bucket->next) {
			bucket = bucket->next;
		}
		bucket->next = lv;
	}
	lv->next = NULL;
	map->count++;
}

int get_data(hashmap *map, char *name) {
	if (!map || !map->buckets) {
		throw_error("Map Does Not Exist");
	}

	if (!name) {
		throw_error("String Does Not Exist");
	}

	int key = hash(name, map->size);
	linked_value *bucket = map->buckets[key];
	while (bucket) {
		if (strcmp(bucket->val->name, name) == 0) return bucket->val->data;
		bucket = bucket->next;
	}

	return -1; 
}

void delete_value(hashmap *map, char *name) {
	if (!map || !map->buckets) {
		throw_error("Map Does Not Exist");
	}

	if (!name) {
		throw_error("String Does Not Exist");
	}

	int key = hash(name, map->size);
	linked_value *bucket = map->buckets[key];
	linked_value *prev = NULL;

	while (bucket) {
		if (strcmp(bucket->val->name, name) == 0) {
			if (prev == NULL) {
				map->buckets[key] = bucket->next;
			}else {
				prev->next = bucket->next;
			}
			map->count--;
			return;
		}
		prev = bucket;
		bucket = bucket->next;
	}
}

float get_load_factor(hashmap *map) {
	if (!map || !map->buckets) {
		throw_error("Map Does Not Exist");
	}

	return ((float) map->count / map->size);
}

int get_size(hashmap *map) {
	if (!map || !map->buckets) {
		throw_error("Map Does Not Exist");
	}

	return map->size;
}

void rehash(hashmap *map) {
	if (!map || !map->buckets) {
		throw_error("Map Does Not Exist");
	}

	int old_size = map->size;
	linked_value** tmp_arr = map->buckets;
	map->size *= 2;
	map->count = 0;

	map->buckets = calloc(map->size, sizeof(linked_value*));
	if (!map->buckets) {
		throw_error("Memory Allocation Failed");
	}

	for (int i=0; i<old_size;i++) {
		linked_value *bucket = tmp_arr[i];
			while (bucket) {
				linked_value *next = bucket->next;
				bucket->next = NULL;
				add_value(map, bucket);
				bucket = next;
			}
	}
}

void print_map(hashmap *map) {
	if (!map || !map->buckets) {
		throw_error("Map Does Not Exist");
	}

	for (int i=0; i<map->size; i++) {
		linked_value* bucket = map->buckets[i];
		while (bucket) {
			printf("%d, ", i);
			print_linked_value(bucket);
			bucket = bucket->next;
		}
	}
}

void free_map(hashmap *map) {
	if (!map) return;

	for (int i=0; i<map->size; i++) {
		linked_value* bucket = map->buckets[i];
		while (bucket) {
			linked_value* tmp = bucket;
			bucket = bucket->next;
			free_linked_value(tmp);
		}
	}

	free(map->buckets);
	free(map);
}
