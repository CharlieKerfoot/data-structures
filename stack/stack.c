#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "../value/value.h"
#include "../errors/error.h"

struct stack{
	value *top;
	struct stack *rest; //everything else
};

stack *create_stack() {
	stack *s = malloc(sizeof(stack));
	if (!s) {
		throw_error("Memory Allocation Failed");
	}
	s->top = NULL;

	return s;
}

void push(stack **s, value *v) {
	stack *tmp = malloc(sizeof(stack));
	if (!tmp) {
		throw_error("Memory Allocation Failed");
	}

	tmp->top = v;
	tmp->rest = *s;
	*s = tmp;
}

value* pop(stack **s) {
	if (*s == NULL) {
		throw_error("Stack Underflow");
	}

	stack *top_node = *s;
	value *v = top_node->top;
	*s = top_node->rest;
	free(top_node);

	return v;
}

value* peek(stack *s) {
	return s->top;
}

void print_stack(stack *s) {
	if (!s) return;
	print_value(s->top);

	print_stack(s->rest);
}

void free_stack(stack *s) {
	if (!s) return;

	if (s->top) free(s->top);

	free_stack(s->rest);
}
