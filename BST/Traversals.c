#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* createNode(int data)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	return temp;
}

struct node* add(struct node* root, int data)
{
	if(root == NULL) {
		return createNode(data);
	} else {
		if(data>(root->data)){
			root->right = add(root->right, data);
		} else {
			root->left = add(root->left, data);
		}
	}
	return root;
}

struct node* inorderTraversal(struct node* root)
{
	if(root!=NULL){
		inorderTraversal(root->left);
		printf("%d ",root->data);
		inorderTraversal(root->right);
	}
	return root;
}

struct node* preorder(struct node* root)
{
	if(root!=NULL){
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
	return root;
}

struct node* postorder(struct node* root)
{
	if(root!=NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
	return root;
}

int main()
{
	struct node* root = NULL;
	root = add(root, 10);
	add(root, 5);
	add(root, 11);
	add(root, 2);
	add(root, 7);
	add(root, 100);
	add(root, 50);

	preorder(root);
	printf("\n");

	inorderTraversal(root);
	printf("\n");

	postorder(root);	
	printf("\n");
	return 0;
}
