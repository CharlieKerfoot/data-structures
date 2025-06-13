#ifndef QUEUE_H
#define QUEUE_H

#include "../linked_value/linked_value.h"

typedef struct queue queue;

queue *create_queue();
void enqueue(queue *q, linked_value *v);
linked_value *dequeue(queue *q);
linked_value *peek(queue *q);
void free_queue(queue *q);
void print_queue(queue *q);

#endif
