#include <iostream>
using namespace std;

struct node
{
	int data;
	node *left, *right;
};

node *newNode(int data)
{
	node *root = new node;
	root->data = data;
	root->left = root->right = NULL;
	return root;
}

// 1. Initialize current as root 
// 2. While current is not NULL
//    If the current does not have left child
//       a) Print current’s data
//       b) Go to the right, i.e., current = current->right
//    Else
//       a) Make current as the right child of the rightmost 
//          node in current's left subtree
//       b) Go to this left child, i.e., current = current->left

node *successor(node *root)
{
	node *temp;
	for(temp = root; temp->right!=NULL ;temp = temp->right);
		return temp;
}

void morris_trav(node *root)
{
	node *current = root;
	node *pre;
	
	while(current)
	{
		if(current->left==NULL)
		{
			cout<<current->data<<" ";
			current = current->right;
		}
		else
		{
			pre = successor(current->left);
			pre->right = current;

			if(pre->right==NULL)
			{
				
			}
		}
	}
}

int main()
{
	node *root;
	// //if the right subtree doesn't exist --> 1-5-10
	// root = newNode(10);
	// root->left = newNode(5);
	// root->left->left = newNode(1);


	root = newNode(20);
	root->left = newNode(10);
	root->right = newNode(30);
	root->left->left = newNode(5);
	root->left->right = newNode(15);
	root->right->left  = newNode(25);
	root->right->right = newNode(40);

	morris_trav(root);

	return 0;
}