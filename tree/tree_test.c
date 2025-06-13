#include "tree.h"
#include "../value/value.h"
#include <stdio.h>
#include <assert.h>

int main(int argc, char** argv) {
	tree *t = create_tree(NULL);
	value *v0 = create_value("Charlie", 24);
	value *v1 = create_value("Julian", 11);
	value *v2 = create_value("Tom", 12);
	value *v3 = create_value("Patrick", 23);
	value *v4 = create_value("Danny", 80);
	add_tree_value(&t, v0);
	assert(has_node(t, v0) == 1);
	add_tree_value(&t, v1);
	assert(has_node(t, v1) == 1);
	add_tree_value(&t, v2);
	assert(has_node(t, v2) == 1);
	add_tree_value(&t, v3);
	assert(has_node(t, v3) == 1);
	add_tree_value(&t, v4);
	assert(has_node(t, v4) == 1);
	free_tree(t);
	printf("All Tests Passed\n");
	return 0;
}
