#ifndef HEAP_H
#define HEAP_H

#include "../value/value.h"

typedef struct heap heap;

heap *create_heap(int size);
void resize_heap(heap *h);
void insert_heap(heap *h, value *v);
value *peek_heap(heap *h);
value *pop_heap(heap *h);
void bubble_down(heap *h, int idx);
int get_size(heap *h);
void print_heap(heap *h);
void free_heap(heap *h);

#endif
