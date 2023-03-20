#include <stdio.h>
#include <stdbool.h>
#include "queue.h"
#include "binaryTree.h"

int main(){

    int in_string[100];
    int pre_string[100];
    printf("Enter the inorder sequence:\n");
    int i = 0;
    char ch = 0;
    while(ch != '\n'){
        ch = getchar();
        if(ch != ' ' && ch != '\n'){
           in_string[i] = ch - 48;
           i++;
        }
    }
    printf("Enter the preorder sequence:\n");
    ch = 0;
    i = 0;
    while(ch != '\n'){
        ch = getchar();
        if(ch != ' ' && ch != '\n'){
           pre_string[i] = ch - 48;
           i++;
        
        }
    }

//    int inorder[] = {4,2,8,5,1,6,3,7,9};
//    int preorder[] = {1,2,4,5,8,3,6,7,9};
//    node* root2 = inorder_preorder(inorder, preorder, 0,8,0,8);
    node* root2 = inorder_preorder(in_string, pre_string, 0,i-1,0,i-1);
    levelOrderTraversal(root2);

   
    printf("\n");

    return 0;
}
