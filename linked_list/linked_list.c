#include <stdio.h>
#include <stdlib.h>
#include "../linked_value/linked_value.h"
#include "linked_list.h"
#include "../errors/error.h"

struct linked_list {
	linked_value* head;
	int length;
};

linked_list *create_linked_list() {
	linked_list *l = malloc(sizeof(linked_list));
	if (!l){
		throw_error("Memory Allocation Failed");
	}

	l->head = NULL;
	l->length = 0;

	return l;
}

linked_value* get_value(linked_list *list, int idx) {
	if (!list || !list->head) {
		throw_error("Linked List Does Not Exist");
	}

	if (idx < 0 || idx >= list->length) {
		//Index Out of Bounds
		return NULL;
	}
	
	linked_value *curr = list->head;
	for (int i=0; i<idx; i++) {
		curr = curr->next;	
	}

	return curr;
}

int get_length(linked_list *list) {
	if (!list) {
		throw_error("Linked List Does Not Exist");
	}
	return list->length;
}

void insert_front(linked_list *list, linked_value *lv) {
	if (!list) {
		throw_error("Linked List Does Not Exist");
	}

	if (!lv) {
		throw_error("Value Does Not Exist");
	}

	linked_value *new_head = malloc(sizeof(linked_value));
	if (!new_head) {
		throw_error("Memory Allocation Failed");
	}

	*new_head = *lv;
	new_head->next = list->head;
	list->head = new_head;
	list->length++;
}

void insert(linked_list *list, linked_value *lv, int idx) {
	if (!list) {
		throw_error("Linked List Does Not Exist");
	}

	if (!lv) {
		throw_error("Value Does Not Exist");
	}

	if (idx < 0 || idx >= list->length) {
		throw_error("Index Out Of Bounds");
	}

	linked_value *curr = list->head;
	for (int i=0; i < idx-1; i++) {
		curr = curr->next;	
	}

	linked_value *new = malloc(sizeof(linked_value));
	if (!new) {
		throw_error("Memory Allocation Failed");
	}
	
	*new = *lv;
	new->next = curr->next;
	curr->next = new;
	list->length++;
}

void delete_value(linked_list *list, int idx) {
	if (!list || !list->head) {
		throw_error("Linked List Does Not Exist");
	}

	if (idx < 0 || idx >= list->length) {
		throw_error("Index Out Of Bounds");
	}

	list->length--;

	if (idx==0) {
		linked_value *tmp = list->head;
		list->head = list->head->next;
		free(tmp);
		return;
	}

	linked_value *prev = list->head;
	linked_value *curr = list->head->next;
	for (int i=1; i < idx; i++) {
		prev = curr;
		curr = curr->next;
	}
	prev->next = curr->next;
	free(curr);
}

linked_value *pop(linked_list *list, int idx) {
	if (!list || !list->head) {
		throw_error("Linked List Does Not Exist");
	}
	
	if (idx < 0 || idx >= list->length) {
		throw_error("Index Out Of Bounds");
	}

	list->length--;

	if (idx == 0) {
		linked_value *tmp = list->head;
		list->head = list->head->next;
		return tmp; 
	}

	linked_value *prev = list->head;
	linked_value *curr = list->head->next;	
	for (int i=1; i<idx; i++) {
		prev = curr;
		curr = curr->next;
	}

	prev->next = curr->next;
	return curr; 
}

linked_value *pop_last(linked_list *list) {
	if (!list || !list->head) {
		throw_error("Linked List Does Not Exist");
	}

	linked_value* curr = list->head;
	list->length--;

	if (!curr->next) {
		list->head = NULL;
		return curr; 
	}

	while (curr->next->next) {
		curr = curr->next;
	}

	linked_value *last = curr->next;
	curr->next = NULL;
	return last;
}

void reverse_list(linked_list *list) {
	if (!list || !list->head) {
		throw_error("Linked List Does Not Exist");
	}

	linked_value *prev = NULL;
	linked_value *curr = list->head;
	linked_value *next = NULL;

	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}

	list->head = prev;
}

int is_sorted(linked_list *list) {
	if (!list || !list->head) {
		throw_error("Linked List Does Not Exist");
	}

	linked_value *curr = list->head;

	while (curr->next) {
		if (curr->val->data > curr->next->val->data) return 0;
		curr = curr->next;
	}

	return 1;
}

void bubble_sort_pp_list(linked_list *list) {
	// pointer-to-pointer bubble sort implementation
	if (!list || !list->head) {
		throw_error("Linked List Does Not Exist");
	}

	if (!list->head->next) return;

	int n = list->length;
	while (n > 1) {
		linked_value **curr = &list->head;
		int new_length = n;
		for (int i=0; i<n-1; i++) {
			if ((*curr)->val->data > (*curr)->next->val->data) {
				linked_value *tmp = (*curr)->next;
				(*curr)->next = tmp->next;
				tmp->next = *curr;
				*curr = tmp;
				new_length = i+1;
			}
			curr = &(*curr)->next;
		}
		n = new_length;
	}
}

linked_value* merge(linked_value *a, linked_value *b) {
	if (!a) return b;
	if (!b) return a;

	linked_value *head = NULL;
	linked_value **tail = &head;

	while (a && b) {
		if (a->val->data <= b->val->data) {
			*tail = a;
			a = a->next;
		} else {
			*tail = b;
			b = b->next;
		}
		tail = &((*tail)->next);
	}

	*tail = (a) ? a : b;
	return head;
}

void split(linked_value *head, linked_value **front, linked_value **back) {
	if (!head || !head->next) {
		*front = head;
		*back = NULL;
		return;
	}

	linked_value *slow = head;
	linked_value *fast = head->next;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}

	*front = head;
	*back = slow->next;
	slow->next = NULL;
}

linked_value* merge_sort_node(linked_value *list) {
	if (!list || !list->next) return list;

	linked_value *a, *b;
	split(list, &a, &b);

	a = merge_sort_node(a);
	b = merge_sort_node(b);

	return merge(a,b);
}

void merge_sort_list(linked_list *list) {
	if (!list || !list->head) {
		throw_error("Linked List Does Not Exist");
	}

	if (!list->head->next) return;
	list->head = merge_sort_node(list->head);
}

void insertion_sort_list(linked_list *list) {
	if (!list || !list->head) {
		throw_error("Linked List Does Not Exist");
	}

	if (!list->head->next) return;

	linked_value *sorted = NULL;
	linked_value *curr = list->head;
	while (curr) {
		linked_value *next = curr->next;
		if (!sorted || curr->val->data < sorted->val->data) {
			curr->next = sorted;
			sorted = curr;
		} else {
			linked_value *tmp = sorted;
			while (tmp->next && tmp->next->val->data < curr->val->data) {
				tmp = tmp->next;
			}
			curr->next = tmp->next;
			tmp->next = curr;
		}
		curr = next; 
	}
	list->head = sorted;
}

void print_list(linked_list *list) {
	if (!list || !list->head) {
		throw_error("Linked List Does Not Exist");
	}

	linked_value *curr = list->head;
	while (curr) {
		print_linked_value(curr);
		curr = curr->next;
	}
}

void free_list(linked_list *list) {
	if (!list || !list->head) return;

	linked_value *curr = list->head;
	while (curr) {
		linked_value *tmp = curr;
		curr = curr->next;
		free_linked_value(tmp);
	}
	
	free(list);
}
