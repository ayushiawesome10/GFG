#include <iostream>
using namespace std;

typedef struct node
{
	int data;
	node* left;
	node* right;

}node;

node *newNode(int data)
{
	node *val;
	val = new node;
	val->data = data;
	val->left = val->right = NULL;
	return val;
}

void preorder(node* root)
{
	if(root == NULL)
		return;
	else
	{	
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

int main()
{
	node* root;
	//root = new node;
	root = newNode(1);
	root->left = newNode(2);
	root->right= newNode(3);
	root->left->left = newNode(4);

	preorder(root);

	free(root);
	return 0;
}

			//  1
			// / \
		 //   2   3
		 //  /
		 // 4