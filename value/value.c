#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "value.h"
#include "../errors/error.h"

value *create_value(char *name, int data) { 
	value *v = malloc(sizeof(value));
	if (!v) {
		throw_error("Memory Allocation Failed");
	}

	v->name = strdup(name);
	if (!v->name) {
		throw_error("Memory Allocation Failed");
	}

	v->data = data;
	return v;
}

void print_value(value *v) {
	if (!v) {
		throw_error("Value Does Not Exist");
	}

	printf("%s, %d\n", v->name, v->data);
}

void free_value(value *v) {
	if (!v) return;

	free(v->name);
	free(v);
}

