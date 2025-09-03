#include <stdio.h>
#include <stdlib.h>
#define MAX 10


typedef struct {
    int elem[MAX];
    int count;
} List;


List initialize(List L){
    L.count = 0;
    return L;
}

List insertPos(List L, int data, int position){
    if(position < L.count){
        return L;
    }
    int i;
    for(i = L.count; i > position; i--){
        L.elem[i] = L.elem[i-1];
    }
    L.elem[position] = data;
    L.count++;
    return L;
}

List deletePos(List L, int position){
    if(position > L.count){
        return L;
    }
    int i;
    for(i = position; i < L.count - 1; i++){
        L.elem[i] = L.elem[i+1];
    }
    L.count --;
    return L;
}
int locate(List L, int data){
    int found = -1;
    int i;
    for(i = 0; i < L.count; i++){
        if(L.elem[i] == data){
        found = i;
        }
    }
    return found;
}
List insertSorted(List L, int data){
    int i, pos = 0;
    for(i = 0; i < L.count; i++){
        if(L.elem[i] > data){
            break;
        }
        pos++;
    }
    for(i = L.count; i > pos; i--){
        L.elem[i] = L.elem[i - 1];
    }
    L.elem[pos] = data;
    L.count ++;
    return L;
}
void display(List L){
    printf("List of elementos:\n");
    int i;
    for(i = 0; i < L.count; i++){
        printf("%d", L.elem);
    }
}


int main(){
    List L;
    int found;

    L = initialize(L);
    L = insertPos(L,1,0);
    L = insertPos(L,3,1);
    L = insertPos(L,5,2);
    L = insertPos(L,7,3);
    L = insertPos(L,9,4);

    L = deletePos(L,1);
    L = insertSorted(L,3);

    display(L);
}