#ifndef LINKED_VALUE_H
#define LINKED_VALUE_H

#include "../value/value.h"


typedef struct linked_value {
	value* val;
	struct linked_value* next;
} linked_value;

linked_value *create_linked_value(char *name, int data);
void print_linked_value(linked_value *lv);
void free_linked_value(linked_value *lv);

#endif
