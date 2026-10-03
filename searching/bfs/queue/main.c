#include <stdio.h>

#include "queue.h"

int main(void)
{
    Queue *queue = queue_create();

    if (queue == NULL)
    {
        printf("Failed to create queue.\n");
        return 1;
    }

    printf("Queue created.\n");

    queue_enqueue(queue, 10);
    queue_enqueue(queue, 20);
    queue_enqueue(queue, 30);

    printf("Queue size: %d\n", queue->size);
    printf("Front value: %d\n", queue_peek(queue));

    printf("\nDequeuing:\n");

    while (!queue_is_empty(queue))
    {
        printf("%d\n", queue_dequeue(queue));
    }

    printf("\nQueue empty: %s\n",
           queue_is_empty(queue) ? "true" : "false");

    queue_destroy(queue);

    return 0;
}