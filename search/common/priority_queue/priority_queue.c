#include <stdlib.h>

#include "priority_queue.h"

static void swap(PriorityQueueNode *a, PriorityQueueNode *b)
{
    PriorityQueueNode temp = *a;

    *a = *b;
    *b = temp;
}

PriorityQueue *priority_queue_create(int capacity)
{
    if (capacity <= 0)
    {
        return NULL;
    }

    PriorityQueue *queue = malloc(sizeof(PriorityQueue));
    if (queue == NULL)
    {
        return NULL;
    }

    queue->nodes = malloc(capacity * sizeof(PriorityQueueNode));
    if (queue->nodes == NULL)
    {
        free(queue);

        return NULL;
    }

    queue->size = 0;
    queue->capacity = capacity;

    return queue;
}

void priority_queue_destroy(PriorityQueue *queue)
{
    if (queue == NULL)
    {
        return;
    }

    free(queue->nodes);
    free(queue);
}

bool priority_queue_is_empty(const PriorityQueue *queue)
{
    return queue == NULL || queue->size == 0;
}

bool priority_queue_push(PriorityQueue *queue, int vertex, double priority)
{
    if (queue == NULL || queue->size >= queue->capacity)
    {
        return false;
    }

    int index = queue->size++;

    queue->nodes[index].vertex = vertex;
    queue->nodes[index].priority = priority;

    while (index > 0)
    {
        int parent = (index - 1) / 2;

        if (queue->nodes[parent].priority <= queue->nodes[index].priority)
        {
            break;
        }

        swap(&queue->nodes[parent], &queue->nodes[index]);

        index = parent;
    }

    return true;
}

bool priority_queue_pop(PriorityQueue *queue, int *vertex, double *priority)
{
    if (queue == NULL || queue->size == 0 || vertex == NULL || priority == NULL)
    {
        return false;
    }

    *vertex = queue->nodes[0].vertex;
    *priority = queue->nodes[0].priority;

    queue->size--;
    if (queue->size == 0)
    {
        return true;
    }

    queue->nodes[0] = queue->nodes[queue->size];

    int index = 0;

    while (true)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if (left < queue->size && queue->nodes[left].priority < queue->nodes[smallest].priority)
        {
            smallest = left;
        }

        if (right < queue->size && queue->nodes[right].priority < queue->nodes[smallest].priority)
        {
            smallest = right;
        }

        if (smallest == index)
        {
            break;
        }

        swap(&queue->nodes[index], &queue->nodes[smallest]);

        index = smallest;
    }

    return true;
}