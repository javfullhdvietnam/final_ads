#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum size of the queue

typedef struct {
    int data[MAX];
    int front;
    int rear;
    int size;
} Queue;

// Initialize the queue
void initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Check if the queue is full
int isFull(Queue* queue) {
    return queue->size == MAX;
}

// Enqueue an element into the queue
void enqueue(Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX;
    queue->data[queue->rear] = value;
    queue->size++;
    printf("%d enqueued to queue\n", value);
}

// Dequeue an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow\n");
        return -1;
    }
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX;
    queue->size--;
    return value;
}

// Peek the front element of the queue
int peek(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->data[queue->front];
}

int main() {
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element is %d\n", peek(&queue));

    printf("Dequeued element is %d\n", dequeue(&queue));
    printf("Dequeued element is %d\n", dequeue(&queue));

    if (isEmpty(&queue)) {
        printf("Queue is empty now\n");
    }

    return 0;
}
