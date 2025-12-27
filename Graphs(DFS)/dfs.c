#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 9


typedef struct Node {
    int data;
    struct Node* link;
} *ptr, Node;

typedef ptr Graph[MAX];

void dfs (Graph G, int vertex, int mark[]) {
    mark[vertex] = 1;
    printf("%d ", vertex);
    
    ptr trav = G[vertex];
    
    while(trav != NULL) {
        if(mark[trav->data] == 0) {
            dfs(G, trav->data, mark);
        }
        trav = trav->link;
    }
}

void addEdge(Graph G, int u, int v){
    ptr newNode = (ptr)malloc(sizeof(Node));
    newNode->data = v;
    newNode->link = G[u];
    G[u] = newNode;
}

int main() {
    Graph G;
    int mark[MAX] = {0};
    
    for(int i = 0; i < MAX; i++){
        G[i] = NULL;
    }
    
    addEdge(G, 0, 1);
    addEdge(G, 0, 2);
    addEdge(G, 0, 3);
    addEdge(G, 0, 4);
    addEdge(G, 0, 5);
    addEdge(G, 0, 6);
    addEdge(G, 0, 7);
    addEdge(G, 0, 8);
    
    printf("dfs trav starts at vertex 0:\n");
    dfs(G, 0, mark);
    
    return 0;
}