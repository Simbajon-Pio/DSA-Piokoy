#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct {
    Node* front; 
    Node* rear;  
} Queue;

Queue* initialize() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

bool isEmpty(Queue* q) {
    return (q->rear == NULL); 
}


void enqueue(Queue* q, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = q->rear; 
    
    q->rear = newNode; 
    

    if (q->front == NULL) {
        q->front = newNode;
    }
}


int dequeue(Queue* q) {
    if (isEmpty(q)) return -1;
    
    int data;
    

    if (q->rear == q->front) {
        data = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    } 
  
    else {
      
        Node *trav = q->rear;
        while (trav->next != q->front) {
            trav = trav->next;
        }
        
        data = q->front->data;
        free(q->front);
        
        q->front = trav;
        q->front->next = NULL;
    }
    
    return data;
}

void display(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Empty\n");
        return;
    }
    
   
    printf("Queue (Rear/Head to Front/Tail): ");
    Node *trav = q->rear;
    while (trav != NULL) {
        printf("%d -> ", trav->data);
        trav = trav->next;
    }
    printf("NULL\n");
}

int main() {
    Queue *Q = initialize();
    
    printf("Enqueue 10, 20, 30...\n");
    enqueue(Q, 10); 
    enqueue(Q, 20); 
    enqueue(Q, 30); 
    
    
    display(Q);
    
    printf("Dequeued: %d\n", dequeue(Q)); 
    display(Q);
    
    printf("Dequeued: %d\n", dequeue(Q)); 
    display(Q);
    
    return 0;
}