#ifndef VALUE_H
#define VALUE_H

typedef struct {
	char* name;
	int data;
} value;

value* create_value(char *name, int data);
void print_value(value *v);
void free_value(value *v);

#endif 
