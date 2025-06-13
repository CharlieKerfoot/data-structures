## Overview

A linked list is an incredibly common and standard sequential data structure, which simply stores each data value one after another. The operations aren't particuarly fast but the data is very well organized and the linked list's sequential nature makes it very simple to implement.

This implementation of a linked list is a singly linked list, meaning only the pointer for the next node is kept track of, but it could easily be adapted to doubly linked list if need be.

It also includes three different sorting algorithms (bubblesort, mergesort, and insertionsort).

## References

[Linked List](https://www.andrew.cmu.edu/course/15-121/lectures/Linked%20Lists/linked%20lists.html)

## Functions 

```C
linked_list *create_linked_list();
linked_value* get_value(linked_list *list, int idx);
int get_length(linked_list *list);
void insert_front(linked_list *list, linked_value *lv);
void insert(linked_list *list, linked_value *lv, int idx);
void delete_value(linked_list *list, int idx);
linked_value *pop(linked_list *list, int idx);
linked_value *pop_last(linked_list *list);
void reverse_list(linked_list *list);
int is_sorted(linked_list *list);
void bubble_sort_pp_list(linked_list *list);
linked_value* merge(linked_value *a, linked_value *b);
void split(linked_value *head, linked_value **front, linked_value **back);
linked_value* merge_sort_node(linked_value *list);
void merge_sort_list(linked_list *list);
void insertion_sort_list(linked_list *list);
void print_list(linked_list *list);
void free_list(linked_list *list);
```
