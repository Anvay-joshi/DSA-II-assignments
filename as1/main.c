#include <stdio.h>
#include <stdbool.h>
#include "queue.h"
#include "binaryTree.h"

int main(){

    int in_string[100];
    int pre_string[100];
    int size = 0;
    printf("Enter the number of nodes in tree:\n");
    scanf("%d",&size);
    printf("Enter the inorder sequence:\n");
    for(int i = 0; i < size; i++){
        scanf("%d",&in_string[i]);
    }


    printf("Enter the preorder sequence:\n");
    for(int i = 0; i < size; i++){
        scanf("%d",&pre_string[i]);
    }
    node* root1 = inorder_preorder(in_string, pre_string, 0,size-1,0,size-1);
    printf("\n\nthe level order of tree is:\n");
    levelOrderTraversal(root1);

   
    printf("\n");

    return 0;
}
