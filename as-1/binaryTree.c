#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"
#include "queue.h"

node* init_node(int num){
	node* root = (node*) malloc(sizeof(node));
	root->data = num;
	root->left = NULL;
	root->right = NULL;
	return root;
}

int find_index(int inorder[], int data){
     int idx = 0;
     while(inorder[idx] != data){
         idx++;
     }
     return idx;
 }

node* inorder_preorder(int inorder[], int preorder[], int pre_st, int pre_en, int in_st, int in_en){

    if(in_st == in_en){
        return (init_node(inorder[in_st]));
    }

    node* root = init_node(preorder[pre_st]);
    int value_root = preorder[pre_st];
    int idx_root = find_index(inorder, value_root); 
    
    int left_length = idx_root - in_st;
    if(left_length > 0){
        root->left = inorder_preorder(inorder, preorder, pre_st + 1, pre_st + left_length, in_st, idx_root - 1 );        
    }
    
    int right_length = in_en - idx_root;
    if(right_length > 0){
        root->right = inorder_preorder(inorder, preorder, pre_st + left_length + 1, pre_st + left_length + right_length, idx_root + 1, in_en);
    }
    return root;
}

void levelOrderTraversal(node* root){
    queue q = init_Q(root);
    enqueue(&q, NULL);

    while(! isempty_queue(q)){
        node* temp = front_queue(q);
        dequeue(&q);
        if(temp == NULL){
            printf("\n");
            if(! isempty_queue(q)){
                enqueue(&q, NULL);
            }
        }
        else{
            printf("%d ",temp->data);
            if(temp->left){
                enqueue(&q, temp->left);
            }

            if(temp->right){
                enqueue(&q, temp->right);
            }
        }
    }
}

