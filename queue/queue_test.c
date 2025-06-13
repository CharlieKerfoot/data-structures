#include "queue.h"
#include "../linked_value/linked_value.h"
#include <stdio.h>
#include <assert.h>

int main(int argc, char** argv) {
	queue *q = create_queue();

	linked_value *v0 = create_linked_value("Charlie", 24);
	enqueue(q, v0);
	assert(peek(q) == v0);

	linked_value *v1 = create_linked_value("Frank", 5);
	enqueue(q, v1);
	assert(peek(q) == v0);

	assert(dequeue(q) == v0);
	assert(peek(q) == v1);

	free_queue(q);
	printf("All Tests Passed\n");
	return 0;
}
