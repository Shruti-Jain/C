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

struct node* preorder(struct node* root)
{
	if(root!=NULL){
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
	return root;
}

struct node* mirror(struct node* root)
{
	struct node*temp;
	if(root==NULL){
		return root;
	}
	if(root!=NULL){
		temp = root->left;
		root->left = root->right;
		root->right = temp;
		mirror(root->left);
		mirror(root->right);
	}
	return root;
}

int main()
{
	struct node*root = NULL;
	root=add(root, 10);
	add(root, 15);
	add(root, 2);
	add(root, 5);
	add(root, 90);
	add(root, 0);
	add(root, 1);
	add(root, 100);
	add(root, 50);
	add(root, 40);
	printf("Preorder Traversal: ");
	preorder(root);
	printf("\n");

	mirror(root);
	printf("Preorder of Mirror Traversal:");
	preorder(root);
	printf("\n");
	return 0;
}
