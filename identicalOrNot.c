#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*left;
	struct node*right;
};

struct node* createNode(int data)
{
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

struct node* add(struct node*root, int data)
{
	if(root==NULL){
		return createNode(data);
	}
	if(root->data>data){
		root->left = add(root->left, data);
	} else {
		root->right = add(root->right, data);
	}
	return root;
}

void preorder(struct node* root)
{
	if(root){
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

int areIdentical(struct node *root, struct node *root2)
{
	if(root==NULL && root2==NULL){
		return 1;
	}
	if(root!=NULL && root2!=NULL){
		return (root -> data == root2 -> data) && areIdentical(root->left, root2->left) && areIdentical(root->right, root2->right);
	}
	return 0;
}

int main()
{
	struct node*root = NULL;
	struct node*root2 = NULL;
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
	
	root2=add(root2, 10);
	add(root2, 15);
	add(root2, 2);
	add(root2, 5);
	add(root2, 90);
	add(root2, 0);
	add(root2, 1);
	add(root2, 100);
	add(root2, 50);
	add(root2, 41);
	printf("Preorder Traversal: ");
	preorder(root2);
	printf("\n");

	if(areIdentical(root, root2)==0){
		printf("Not Identical\n");
	} else {
		printf("Identical");
	}
	return 0;
}
