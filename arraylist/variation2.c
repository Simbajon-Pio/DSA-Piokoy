#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct 
{
    int elem[MAX];
    int count;
} Etype, *EPtr;

void initialize (EPtr L){
    L->count = 0;
}

void insertPos(EPtr L, int data, int position){
    if (position > L->count){
        return;
    }

    if(position >= L->count){
        L->elem[position] = data;
        L->count += 1;
        
    }else if(position <= L->count){
        int i;
        for(i = L->count - 1; i >= position; i--){
            int temp = L->elem[i];
            L->elem[i+1] = temp; 
        }
        L->elem[position] = data;
        L->count += 1;
        return L;
    }
}

void deletePos(EPtr L, int position){
    if(position > L->count){
        return L;
    }
    int i;
    for(i = position; i < L->count; i++){
        if(L->elem[i] = L->elem[i+1]);
    }
    L->count -= 1;
    return L;
}

int locate(EPtr L, int data){
    int found = -1;
    int i;
    for(i = 0; i < L->count; i++){
        if(L->elem[i] == data){
            found = i;
        }
    }
    return found;
}

void insertSorted(EPtr L, int data){
    int i, pos = 0;
    for(i = 0; i < L->count; i++){
        if(L->elem[i] > data){
            pos = i;
            break;
        }
    }
    int j;
    for(j = L->count - 1; j >= pos; j--){
        L->elem[j] = L->elem[j-1];
    }
    L->elem[pos] = data;
    L->count += 1;
    return L;
}

void display(EPtr L){
    printf("List of elementos:\n");
    int i;
    for(i = 0; i < L->count; i++){
        printf("%d", L->elem[i]);
    }
}

int main(){
    Etype L;
    int found;

    initialize(&L);
    insertPos(&L,1,0);
    insertPos(&L,3,1);
    insertPos(&L,5,2);
    insertPos(&L,7,3);
    insertPos(&L,9,4);

    deletePos(&L,1);
    found = locate(&L, 3);
    printf("Location: %d\n", found);
    found = locate(&L, 9);
    printf("Location: %d\n", found);
    insertSorted(&L,6);
    insertSorted(&L, 8);
    display(&L);
}
