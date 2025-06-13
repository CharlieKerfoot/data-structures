#include "stack.h"
#include "../value/value.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

int main(int argc, char** argv) {
	stack *s = create_stack();
	value *v0 = create_value("Charlie", 24);
	value *v1 = create_value("CC", 55);
	push(&s, v0);
	assert(peek(s) == v0);
	push(&s, v1);
	assert(peek(s) == v1);
	assert(pop(&s) == v1);
	free_stack(s);
	printf("All Tests Passed\n");
	return 0;
}
