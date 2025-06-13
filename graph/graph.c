#include <stdlib.h>
#include <stdio.h>
#include "graph.h"
#include "../errors/error.h"

struct node {
	int idx;
	struct node *next;
};

struct graph {
	// Adjacency List for Directed Graph
	node **adjs;
	int size;
};

graph *create_graph(int size) {
	if (size <= 0) {
		throw_error("Graph Size Cannot Be Smaller Than One");
	}
	graph *g = malloc(sizeof(graph));
	g->size = size;
	g->adjs = malloc(sizeof(node*) * size);

	if (!g || !g->adjs) {
		throw_error("Memory Allocation Failed");
	}

	return g;
}

int has_edge(graph *g, int src, int dest) {
	if (!g || !g->adjs) {
		throw_error("Graph Does Not Exist");
	}

	node *curr_node = g->adjs[src];
	while (curr_node) {
		if (curr_node->idx == dest) return 1;
		curr_node = curr_node->next;
	}
	return 0;
}

void add_edge(graph *g, int src, int dest) {
	if (!g || !g->adjs) {
		throw_error("Graph Does Not Exist");
	}

	if (src >= g->size || dest >= g->size || src < 0 || dest < 0) {
		throw_error("Node Indices Are Out Of Bounds");
	}
	
	if (has_edge(g, src, dest)) return;

	node **curr_node = &g->adjs[src];
	while (*curr_node) {
		curr_node = &((*curr_node)->next);
	}

	*curr_node = malloc(sizeof(node));
	if (!*curr_node) {
		throw_error("Memory Allocation Failed");
	}

	(*curr_node)->idx = dest;
	(*curr_node)->next = NULL;
}

void remove_edge(graph *g, int src, int dest) {
	if (!g || !g->adjs) {
		throw_error("Graph Does Not Exist");
	}

	if (src >= g->size || dest >= g->size || src < 0 || dest < 0) {
		throw_error("Node Indices Are Out Of Bounds");
	}

	if (!has_edge(g, src, dest)) {
		throw_error("Edge Does Not Exist");
	}
	
	node **curr_node = &g->adjs[src];
	while (*curr_node) {
		if ((*curr_node)->idx == dest) {
			node *tmp = *curr_node;
			*curr_node = (*curr_node)->next;
			free(tmp);
		} else {
			curr_node = &((*curr_node)->next);
		}
	}
}

void print_graph(graph *g) {
	if (!g || !g->adjs) {
		throw_error("Graph Does Not Exist");
	}

	for (int i=0; i<g->size; i++) {
		printf("%d -> ", i);
		node *curr_node = g->adjs[i];
		while (curr_node) {
			printf("%d, ", curr_node->idx);
			curr_node = curr_node->next;
		}
		printf("\n");
	}

}

void free_graph(graph *g) {
	if (!g || !g->adjs) return;

	for (int i=0; i<g->size; i++) {
		node *curr_node = g->adjs[i];
		while (curr_node) {
			node *tmp = curr_node;
			curr_node = curr_node->next;
			free(tmp);
		}
	}

	free(g->adjs);
	free(g);
}
