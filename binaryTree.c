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

node* build_BST(int sequence[], int size){
    node* root = NULL;
    for(int i = 0; i < size; i++){
        insertNode_BST(&root, sequence[i]);
    }
    return root;
}

void insertNode_BST(node** root, int num){
	if(*root == NULL){
		*root = (init_node(num));	
		return;
	}	
	else if(num < (*root)->data){
		insertNode_BST(&(*root)->left, num); 
	}
	else if(num > (*root)->data){
		insertNode_BST(&(*root)->right, num);
	}
	else if(num == (*root)->data){
		return;
	}
}


//TODO: function incomplete. finish writing it before using it  
void deleteNode_BST(node** root, int key){
    if(key == (*root)->data){
        if((*root)->left == NULL && (*root)->right == NULL){
            node* temp = *root;
            *root = NULL;
            free(temp);
        } 
        else if((*root)->left == NULL && (*root)->right != NULL){
            node* temp = *root;
            *root = (*root)->right;
            free(temp);
        }

        else if((*root)->right == NULL && (*root)->left != NULL){
            node* temp = *root;
            *root = (*root)->left;
            free(temp);
        }
        else{
            node* temp = *root;
            node* lg = (*root)->right;
            while(lg->left != NULL){
                lg= lg->left;
            }
            lg->left = (*root)->left;
            *root = (*root)->right;
            free(temp);
        }
    }
    else if (key < (*root)->data){
        deleteNode_BST(&(*root)->left, key);
    }

    else if (key > (*root)->data){
        deleteNode_BST(&(*root)->right, key);
    }
}
