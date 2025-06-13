#include "linked_value.h"
#include "../value/value.h"
#include <stdlib.h>
#include <stdio.h>
#include "../errors/error.h"

linked_value *create_linked_value(char *name, int data) {
	linked_value *lv = malloc(sizeof(linked_value));
	if (!lv) {
		throw_error("Memory Allocation Failed");
	}

	lv->val = create_value(name, data);
	lv->next = NULL;

	return lv;
}

void print_linked_value(linked_value *lv) {
	if (!lv) {
		throw_error("Linked Value Does Not Exist");
	}

	print_value(lv->val);
}

void free_linked_value(linked_value *lv){
	if (!lv) return;

	free_value(lv->val);
	free(lv);
}
