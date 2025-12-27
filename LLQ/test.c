#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

typedef struct {
    int items[MAX];
    int front;
    int rear;
    int count;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = 0;
}


bool isFull(Queue* q) {
    return (q->rear == MAX);
}

bool isEmpty(Queue* q) {
    return (q->front == q->rear - 1);
}
void enqueue(Queue* q, int val) {
    if(isFull(q)){
        printf("Queue is Full!");
        return;
    }
    q->items[q->rear] = val;
    q->rear++;
}

void dequeue(Queue* q) {
    if(isEmpty(q)){
        printf("Queue is Empty!");
        return -1;
    }
    int value = q->items[q->front];

    if(q->count == 1){
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
    q->count--;
    return value;
}