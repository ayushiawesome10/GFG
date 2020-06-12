//Continuous tree is one in which the absolute difference between the adjacent nodes is 1.
#include <iostream>
#include <math.h>
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

bool treeContinuous(node* root){
	if(root==NULL)
		return true;
	if(root->left == NULL && root->right == NULL)
		return true;
	if(root->left != NULL && root->right == NULL)
		return (abs(root->data - root->left->data)==1 && treeContinuous(root->left));
	if(root->right != NULL && root->left == NULL)
		return (abs(root->data - root->right->data)==1 && treeContinuous(root->right));
	return (abs(root->left->data -  root->data)==1 && abs(root->right->data - root->data)==1
		&& treeContinuous(root->left) && treeContinuous(root->right));
}

int main() 
{ 
	//yes
    // node *root         = newNode(7); 
    // root->left         = newNode(5); 
    // root->right        = newNode(8); 
    // root->left->left   = newNode(6); 
    // root->left->right  = newNode(4); 
    // root->right->right = newNode(10); 

	//no
    node *root         = newNode(1); 
    root->left         = newNode(2); 
    root->right        = newNode(3); 
    root->left->left   = newNode(4); 
    root->left->right  = newNode(4); 
    root->right->left  = newNode(2); 

    //yes
    // node *root         = newNode(3); 
    // root->left         = newNode(2); 
    // root->right        = newNode(4); 
    // root->left->left   = newNode(1); 
    // root->left->right  = newNode(3); 
    // root->right->left  = newNode(5); 
    treeContinuous(root)?  cout << "Yes" : cout << "No"; 
    return 0; 
} 