#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "../linked_value/linked_value.h"
#include "../errors/error.h"

struct queue {
	linked_value* head;
	linked_value* tail;
};

queue *create_queue() {
	queue *q = malloc(sizeof(queue));
	if (!q) {
		throw_error("Memory Allocation Failed");
	}

	q->head = NULL;
	q->tail = NULL;
	return q;
}

void enqueue(queue *q, linked_value *v) {
	if (!v) {
		throw_error("Value Does Not Exist");
	}

	v->next = NULL;

	if (!q->head) {
		q->tail = v;
		q->head = q->tail;
	}else {
		q->tail->next = v;
		q->tail = q->tail->next;
	}
}

linked_value *dequeue(queue *q) {
	if (!q||!q->head) {
		throw_error("Queue Does Not Exist");
	}

	linked_value *removed = q->head;
	q->head = q->head->next;

	if (!q->head) {
		q->tail = NULL;
	}

	removed->next = NULL;
	return removed;
}

linked_value *peek(queue *q) {
	if (!q || !q->head) {
		throw_error("Queue Does Not Exist");
	}

	return q->head;
}

void print_queue(queue *q) {
	if (!q || !q->head) {
		throw_error("Queue Does Not Exist");
	}

	linked_value *curr = q->head;
	while (curr) {
		print_linked_value(curr);
		curr = curr->next;
	}
}

void free_queue(queue *q) {
	if (!q) return;

	linked_value *curr = q->head;
	while(curr) {
		linked_value *v = curr;
		curr = curr->next;
		free_linked_value(v);
	}
	free(q);
}

