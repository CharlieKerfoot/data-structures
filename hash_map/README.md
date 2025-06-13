## Overview

A Hash Map is a an array of strings or other data types with O(n) lookup by assigning strings to a unique index through the use of a pre-defined hash function.

The goal of a hash function is too assign each input string a unique index, however as the size of the array decreases, making a perfect hash function in nearly impossible. As a result, hash maps have to build in support for handling hash collisions (when two strings map to the same index). Usually this is done through Open Adressing, Separate Chaining, and sometimes Cuckoo Hashing.

This implementation uses Separate Chaining, which means that strings with the same index will be added to a linked list and allow for non-unique hashes. This slows down operations as the map fills up but the hash map will dynamically rehash (double its size) when things get too slow.

The hash functions used here is called djb2 and was created by Dan Bernstein. See References for more info.

## References

[Hash Tables](https://www.cs.cmu.edu/~mrmiller/15-121/Slides/25-HashTables.pdf)
[Djb2 Hash Function](http://www.cse.yorku.ca/~oz/hash.html)

## Functions

```C
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
```
