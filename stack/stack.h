#ifndef STACK_H
#define STACK_H

#include "../value/value.h"

typedef struct stack stack;

stack *create_stack();
void push(stack **s, value *v);
value* pop(stack **s);
value* peek(stack *s);
void print_stack(stack *s);
void free_stack(stack *s);

#endif
