#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <stdbool.h>

typedef struct
{
    int vertex;
    double priority;
} PriorityQueueNode;

typedef struct
{
    PriorityQueueNode *nodes;
    int size;
    int capacity;
} PriorityQueue;

PriorityQueue *priority_queue_create(int capacity);

void priority_queue_destroy(PriorityQueue *queue);

bool priority_queue_is_empty(const PriorityQueue *queue);

bool priority_queue_push(PriorityQueue *queue, int vertex, double priority);

bool priority_queue_pop(PriorityQueue *queue, int *vertex, double *priority);

#endif