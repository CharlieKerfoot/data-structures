## Overview

A Heap is a data structure built on top of a tree, but with a very specific ordering. Heaps are either min-heaps or max-heaps, which refer to which ordering system will be used. In a min-heap (which is used in this implementation), the root node is always the smallest value and the child of a node is always smaller than its parent.

Heaps can be very useful as priority queues or in implementing the O(n logn) sorting algorithm HeapSort.

## References

[Binary Heaps](https://www.andrew.cmu.edu/course/15-121/lectures/Binary%20Heaps/heaps.html)

## Functions

```C
heap *create_heap(int size);
void resize_heap(heap *h);
void insert_heap(heap *h, value *v);
value *peek_heap(heap *h);
value *pop_heap(heap *h);
int get_size(heap *h);
void print_heap(heap *h);
void free_heap(heap *h);
```
