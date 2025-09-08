#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *head;
    int count;
} List;

List* initialize(){
    List *list = (List*)malloc(sizeof(List));
    if(list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->count = 0;
    return list;
}

void empty(List *list){
    // if(list->next == NULL){
    //     return;
    // }
    Node *current = list->head;
    while (current != NULL){
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    list->count =0;
    // free(list->next);
    list->head = NULL;
}

void insertFirst(List *list, int data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->count++;
}

void insertLast(List *list, int data){
    Node *newNode = malloc(sizeof(Node));
    newNode->data = data;
    if(list->head == NULL){
        list->head = newNode;
    }else{
        Node *temp = list->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->count++;
}

void insertPos(List *list, int data, int index){
    Node *newNode = malloc(sizeof(Node));
    if(index >= list->count){
        return;
    }
    if(index == 0){
        insertFirst(list, data);
    }else if(index == list->count){
        insertLast(list, data);
    }else{
        Node *newNode = malloc(sizeof(Node));
        newNode->data = data;
        Node *current = list->head;
        for(int i = 0; i < index - 1; i++){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
    list->count++;
    
}

void deleteStart(List *list){

}

void deleteLast(List *list){

}

void deletePos(List *list, int index){

}

int retrieve(List *list, int index){

}

int locate(List *list, int data){

}

void display(List *list){

}