## Overview

A graph is a collection of nodes (or verticies) that are connected by edges. 

A graph can be implemented as an Adjacency Matrix, an Edge List, or an Adjacency List as done here. It is simply a dynamic array of nodes, where each node is also the head to a linked list that contains all the edges.

This is a directed graph, meaning each function takes in a source and destination node, but it can easily be generalized into an undirected or even weighted graph.

## References

[An Introduction to Graphs](https://www.cs.cmu.edu/~tcortina/15-121sp10/Unit09.pdf)

## Functions

```C
graph *create_graph(int size);
int has_edge(graph *g, int src, int dest);
void add_edge(graph *g, int src, int dest);
void remove_edge(graph *g, int src, int dest);
void print_graph(graph *g);
void free_graph(graph *g);
```
