#include "../value/value.h"
#include "heap.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
	heap *h = create_heap(3);
	value *v0 = create_value("Charlie", 15);
	value *v1 = create_value("Sammy", 10);
	value *v2 = create_value("Drake", 9);
	value *v3 = create_value("Phil", 17);
	insert_heap(h, v0);
	assert(peek_heap(h)->data == 15);
	insert_heap(h, v1);
	assert(peek_heap(h)->data == 10);
	insert_heap(h, v2);
	assert(peek_heap(h)->data == 9);
	insert_heap(h, v3);
	assert(peek_heap(h)->data == 9);
	assert(get_size(h) == 6);
	value *v4 = create_value("Greg", 6);
	insert_heap(h, v4);
	assert(peek_heap(h)->data == 6);
	assert(pop_heap(h)->data == 6);
	value *v5 = create_value("Tom", 12);
	insert_heap(h, v5);
	assert(peek_heap(h)->data == 9);
	free_heap(h);
	printf("All Tests Passed\n");
}
