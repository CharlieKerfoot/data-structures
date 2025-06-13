## Overview

A sequential data structure that works based on the Lirst-In-First-Out (FIFO) principle. It is very similar to a linked list except elements can only be popped off the top. 

Stacks are very useful for language processing, compiling, or tree traversal with the Depth-First-Search (DFS) algorithm.

## References

[Stacks and Queues](https://www.andrew.cmu.edu/course/15-121/lectures/Stacks%20and%20Queues/Stacks%20and%20Queues.html)

## Functions

```C
stack *create_stack();
void push(stack **s, value *v);
value* pop(stack **s);
value* peek(stack *s);
void print_stack(stack *s);
void free_stack(stack *s);
```
