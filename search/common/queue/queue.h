#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct QueueNode
{
    struct QueueNode *next;
    int value;
} QueueNode;

typedef struct
{
    QueueNode *front;
    QueueNode *rear;
    int size;
} Queue;

Queue *queue_create(void);

bool queue_is_empty(const Queue *queue);

void queue_enqueue(Queue *queue, int value);

int queue_dequeue(Queue *queue);

int queue_peek(const Queue *queue);

void queue_destroy(Queue *queue);

#endif