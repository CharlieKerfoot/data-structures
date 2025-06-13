## Overview

A sequential data structure that works based on the First-In-First-Out (FIFO) principle. It is very similar to a linked list except the tail is also kept track of. 

This implementation is a simple queue, but it lays the groundwork for implementing a circular queue or deque.

Queues are commonly used when implementing Breadth-First-Search (BFS), an algorithm used fro traversing trees.

## References

[Stacks and Queues](https://www.andrew.cmu.edu/course/15-121/lectures/Stacks%20and%20Queues/Stacks%20and%20Queues.html)

## Functions

```C
queue *create_queue();
void enqueue(queue *q, linked_value *v);
linked_value *dequeue(queue *q);
linked_value *peek(queue *q);
void free_queue(queue *q);
void print_queue(queue *q);
```
