#ifndef TREE_H
#define TREE_H

#include "../value/value.h"

typedef struct tree tree;

tree *create_tree(value* v);
void add_tree_value(tree **t, value *v);
int has_node(tree *t, value *v);
void print_tree(tree *t);
void free_tree(tree *t);

#endif
