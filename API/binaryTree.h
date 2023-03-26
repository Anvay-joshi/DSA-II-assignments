#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_
typedef struct node{
	int data;
	struct node* right;
	struct node* left;
}node;

node* init_node(int);
int find_index(int inorder[], int);
node* inorder_preorder(int inorder[], int preorder[], int pre_st, int pre_en, int in_st, int in_en);
void levelOrderTraversal(node* root);
node* build_BST(int sequence[], int size);
void insertNode_BST(node** root, int num);
void deleteNode_BST(node** root, int key);

#endif
