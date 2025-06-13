#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../linked_value/linked_value.h"

typedef struct linked_list linked_list;
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

#endif
