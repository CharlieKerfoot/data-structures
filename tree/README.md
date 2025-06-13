## Overview

A tree is a recursive data structure where each node contains branches to lower subtrees. Trees are highly useful for mirroring hieracherial data like file systems or relationships.

This implementation of a tree is binary search tree (bst), which is a very common for storing and ddisplaying data in a tree-like manner.

The versatility of trees can also be extended to strings through the use of a trie, where each node represents a character and a collection of branches represents a word or prefix.

## References

[Tree Data Structure](https://www.cs.cmu.edu/~clo/www/CMU/DataStructures/Lessons/lesson4_1.htm)

## Functions

```C
tree *create_tree(value* v);
void add_tree_value(tree **t, value *v);
int has_node(tree *t, value *v);
void print_tree(tree *t);
void free_tree(tree *t);
```
