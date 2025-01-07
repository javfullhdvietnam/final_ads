#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void printTree(Node* root, int space, int level) {
    if (root == NULL) {
        return;
    }


    space += 10;

    printTree(root->right, space, level + 1);


    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }


    if (level > 0) {
        printf("|---%d\n", root->data);
    } else {
        printf("%d\n", root->data); 
    }

    printTree(root->left, space, level + 1);
}


int main() {

    Node* root = createNode(10);
    root->left = createNode(4);
    root->right = createNode(81);
    root->left->left = createNode(3);
    root->left->right = createNode(13);
    root->right->left = createNode(70);
    root->right->right = createNode(310);

   
    
    printTree(root, 0, 0);

    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}