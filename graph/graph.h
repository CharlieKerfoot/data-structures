#ifndef GRAPH_H
#define GRAPH_H

typedef struct node node; 

typedef struct graph graph;

graph *create_graph(int size);
int has_edge(graph *g, int src, int dest);
void add_edge(graph *g, int src, int dest);
void remove_edge(graph *g, int src, int dest);
void print_graph(graph *g);
void free_graph(graph *g);

#endif
