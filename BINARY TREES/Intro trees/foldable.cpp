#include <iostream>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;

};

node *newNode(int data)
{
	node *val;
	val = new node;
	val->data = data;
	val->left = val->right = NULL;
	return val;
}

bool foldable(node *a, node* b)
{
	if(a->left==NULL && b->right==NULL)
		return true;
	if(a->right==NULL && b->left==NULL)
		return true;
	if(a->left!=NULL && b->right==NULL)
		return false;
	if(a->right!=NULL  && b->left==NULL)
		return false;

	return (foldable(a->left,b->right) && foldable(a->right,b->left));
}

int main() 
{ 
	// //e.g. : 1 )yes
	// node* root = newNode(10);
	// root->left = newNode(7);
	// root->right = newNode(15);
	// root->left->right = newNode(9);
	// root->right->left = newNode(11);

	// //e.g. : 2) yes
	// node* root = newNode(10);
	// root->left = newNode(7);
	// root->right = newNode(15);
	// root->left->left = newNode(9);
	// root->right->right = newNode(11);

	// //e.g. : 3) no
	// node* root = newNode(10);
	// root->left = newNode(7);
	// root->right = newNode(15);
	// root->left->left = newNode(5);
	// root->right->left = newNode(11);

	//e.g. : 4) no
	// node* root = newNode(10);
	// root->left = newNode(7);
	// root->right = newNode(15);
	// root->left->left = newNode(9);
	// root->left->right = newNode(10);
	// root->right->right = newNode(11);

	node *root = new node;


	bool res = foldable(root->left,root->right);
	if(res == true || root==NULL)
	{
		cout<<"\nTree is foldable";
	} 
	else
	{
		cout<<"\nTree is not foldable";
	}
    return 0;
}