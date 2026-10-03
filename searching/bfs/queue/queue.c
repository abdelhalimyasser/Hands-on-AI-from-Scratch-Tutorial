#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

Queue *queue_create(void)
{
    Queue *queue = malloc(sizeof(Queue));

    if (queue == NULL)
    {
        return NULL;
    }

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;

    return queue;
}

bool queue_is_empty(const Queue *queue)
{
    return queue == NULL || queue->front == NULL;
}

void queue_enqueue(Queue *queue, int value)
{
    if (queue == NULL)
    {
        return;
    }

    QueueNode *new_node = malloc(sizeof(QueueNode));

    if (new_node == NULL)
    {
        return;
    }

    new_node->value = value;
    new_node->next = NULL;

    if (queue->rear == NULL)
    {
        queue->front = new_node;
        queue->rear = new_node;
    }
    else
    {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }

    queue->size++;
}

int queue_dequeue(Queue *queue)
{
    if (queue_is_empty(queue))
    {
        return -1;
    }

    QueueNode *temp = queue->front;

    int value = temp->value;

    queue->front = queue->front->next;

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    free(temp);

    queue->size--;

    return value;
}

int queue_peek(const Queue *queue)
{
    if (queue_is_empty(queue))
    {
        return -1;
    }

    return queue->front->value;
}

void queue_destroy(Queue *queue)
{
    if (queue == NULL)
    {
        return;
    }

    while (!queue_is_empty(queue))
    {
        queue_dequeue(queue);
    }

    free(queue);
}