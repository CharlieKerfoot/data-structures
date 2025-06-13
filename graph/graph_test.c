#include "graph.h"
#include <stdio.h>
#include <assert.h>

int main(void) {
	graph *g = create_graph(6);
	add_edge(g, 2, 4);
	assert(has_edge(g, 2, 4) == 1);
	add_edge(g, 3, 4);
	assert(has_edge(g, 3, 4) == 1);
	add_edge(g, 2, 1);
	assert(has_edge(g, 2, 1) == 1);
	add_edge(g, 4, 0);
	assert(has_edge(g, 4, 0) == 1);
	add_edge(g, 0, 5);
	assert(has_edge(g, 0, 5) == 1);
	add_edge(g, 5, 1);
	assert(has_edge(g, 5, 1) == 1);
	add_edge(g, 1, 3);
	assert(has_edge(g, 1, 3) == 1);
	remove_edge(g, 2,4);
	assert(has_edge(g,2,4) == 0);
	free_graph(g);
	printf("All Tests Passed\n");
	return 0;
}
