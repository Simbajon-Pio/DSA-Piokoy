#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10 

typedef struct {
    int items[MAX];
    int top;
} Stack;

Stack* initialize() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

bool isFull(Stack* s) {
    if(s->top == MAX - 1)
        return true;
    return false;
}

bool isEmpty(Stack* s) {
    if(s->top == -1)
        return true;
    return false;
}

void push(Stack* s, int value) {
    if(isFull(s)){
        printf("Stack is Full!");
        return;
    }
    s->top++;
    s->items[s->top] = value;
}

int pop(Stack* s) {
    if(isEmpty(s)) {
        printf("Stack is Empty!");
        return 0;
    }
    int value = s->items[s->top];
    s->top--;
    return value;
}

int peek(Stack* s) {
    if(isEmpty(s)) {
        printf("Stack is Empty!");
        return -1;
    }
    return s->items[s->top];
}

void display(Stack* s) {
    if(isEmpty(s)) {
        return;
    }
    printf("Stack (top -> bot): ");
    for(int i = s->top; i >= 0; i--) {
        printf("%d\n", s->items[i]);
    }
}

int main() {
    int value = 0;
    
    Stack* s = initialize();
    push(s, 5);
    push(s, 6);
    push(s, 8);
    push(s, 4);
    push(s, 7);
    
    value = pop(s);
    printf("Pop: %d\n", value);
    value = pop(s);
    printf("Pop: %d\n", value);
    
    value = peek(s);
    printf("Current Value: %d\n", value);
    
    printf("Stack: ");
    display(s);
}