#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int data;
    struct node *lc;
    struct node *rc;
    
}Node, *BST;

void insert(BST* B, int value) {
    BST* trav = B;
    while (*trav != NULL && (*trav)->data != value) {
        trav = ((*trav)->data > value ? &(*trav)->lc : &(*trav)->rc);
    }
    
    if(*trav == NULL) {
        *trav = (BST)calloc(1, sizeof(Node));
        (*trav)->data = value;
    }
}

void inorder(BST B) {
    if (B != NULL){
    inorder(B->lc);
    printf("%d ", B->data);
    inorder(B->rc);
    }
}

BST deleteNode(BST root, int value) {
    if (root == NULL) return NULL;

    if (value < root->data) {
        root->lc = deleteNode(root->lc, value);
    }
    else if (value > root->data) {
        root->rc = deleteNode(root->rc, value);
    }
    else {
     
        if (root->lc == NULL && root->rc == NULL) {
            free(root);
            return NULL;
        }

      
        else if (root->lc == NULL) {
            BST temp = root->rc;
            free(root);
            return temp;
        }
        else if (root->rc == NULL) {
            BST temp = root->lc;
            free(root);
            return temp;
        }

        
        else {
            BST successor = root->rc;
            while (successor->lc != NULL)
                successor = successor->lc;

            root->data = successor->data; 
            root->rc = deleteNode(root->rc, successor->data);
        }
    }

    return root;
}

int main(){
    BST B = NULL;
    
    insert(&B, 1);
    insert(&B, 4);
    insert(&B, 8);
    insert(&B, 7);
    insert(&B, 6);
    
    printf("Inorder trav: ");
    inorder(B);
    printf("\n");
    
      B = deleteNode(B, 8);
    printf("Inorder after deleting 8: ");
    inorder(B);
    printf("\n");

    B = deleteNode(B, 1);
    printf("Inorder after deleting 1: ");
    inorder(B);
    printf("\n");

    B = deleteNode(B, 7);
    printf("Inorder after deleting 7: ");
    inorder(B);
    printf("\n");

    return 0;
}