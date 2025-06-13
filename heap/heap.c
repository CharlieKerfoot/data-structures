#include "../value/value.h"
#include "heap.h"
#include <stdlib.h>
#include <stdio.h>
#include "../errors/error.h"

struct heap {
	//min-heap
	value** vals;
	int size;
	int count; //how many addresses in the fixed-size array are being used
};

heap *create_heap(int size) {
	if (size <= 0) {
		throw_error("Heap Size Cannot Be Less Than 1");
	}

	heap *h = malloc(sizeof(heap));
	h->vals = malloc(sizeof(value*) * (size + 1));
	h->size = size;
	h->count = 0;

	if (!h || !h->vals) {
		throw_error("Memory Allocation Failed");
	}

	return h;
}

void resize_heap(heap *h) {
	if (!h || !h->vals) {
		throw_error("Heap Does Not Exist");
	}

	value** tmp_arr = h->vals;
	int old_count = h->count;
	h->size *= 2;
	h->vals = malloc(sizeof(value*) * (h->size+1));
	h->count = 0;

	if (!h->vals) {
		throw_error("Memory Allocation Failed");
	}

	for (int i=1; i<=old_count; i++) {
		insert_heap(h, tmp_arr[i]);
	}

	free(tmp_arr);
}

void insert_heap(heap *h, value *v) {
	if (!h || !h->vals) {
		throw_error("Heap Does Not Exist");
	}

	if (h->count == h->size - 1) resize_heap(h);

	h->count++;
	int curr_idx = h->count;
	h->vals[curr_idx] = v;

	//bubble up
	while (curr_idx != 1) {
		int parent_idx = curr_idx/2;
		if (h->vals[curr_idx]->data >= h->vals[parent_idx]->data) break;

		value *tmp = h->vals[curr_idx];
		h->vals[curr_idx] = h->vals[parent_idx];
		h->vals[parent_idx] = tmp;

		curr_idx = parent_idx;
	}
}

value *peek_heap(heap *h) {
	if (!h || !h->vals) {
		throw_error("Heap Does Not Exist");
	}

	return h->vals[1];
}

value *pop_heap(heap *h) {
	if (!h || !h->vals || h->count == 0) {
		throw_error("Heap Does Not Exist");
	}
	
	value *min_val = h->vals[1];
	h->vals[1] = h->vals[h->count];
	h->vals[h->count] = NULL;
	h->count--;

	int curr_idx = 1;
	//bubble down
	while (1) {
		int left = curr_idx * 2;
		int right = curr_idx * 2 + 1;
		int smallest = curr_idx;

		if (left <= h->count && h->vals[left]->data < h->vals[smallest]->data) smallest = left;
		if (right <= h->count && h->vals[right]->data < h->vals[smallest]->data) smallest = right;

		if (smallest == curr_idx) break;

		value *tmp = h->vals[curr_idx];
		h->vals[curr_idx] = h->vals[smallest];
		h->vals[smallest] = tmp;

		curr_idx = smallest;
	}

	return min_val;
}

int get_size(heap *h) {
	return h->size;
}

void print_heap(heap *h) {
	if (!h || !h->vals) {
		throw_error("Heap Does Not Exist");
	}

	for (int i=1; i<=h->count; i++) {
		printf("%d, ", i);
		print_value(h->vals[i]);
	}
}

void free_heap(heap *h) {
	if (!h || !h->vals) return;

	for (int i=1; i<=h->count; i++) {
		free_value(h->vals[i]);
	}
	free(h->vals);
	free(h);
}
