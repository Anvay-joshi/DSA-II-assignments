#include <stdio.h>
#include <stdbool.h>
#include "queue.h"
#include "binaryTree.h"

int main(){

    int seq[100];
    int size = 0;
    printf("Enter the number of nodes in BST:\n");
    scanf("%d",&size);
    printf("Enter the sequence of numbers in BST:\n");
    for(int i = 0; i < size; i++){
        scanf("%d",&seq[i]);
    }

    int key = 0;
    printf("BST before deletion:\n");
    node* root = build_BST(seq, size);
    levelOrderTraversal(root);
    
    printf("\n");
    printf("Enter the node to be removed:\n");
    scanf("%d",&key);

    printf("BST after deletion:\n");
    deleteNode_BST(&root, key);
    levelOrderTraversal(root);
    
    printf("\n");

    return 0;
}
