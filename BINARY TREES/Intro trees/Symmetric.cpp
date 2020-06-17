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
//this is wrong because in case a->left = NULL and b->right exists then in next recusive call
//it becomes NULL->left which is segmentation fault(NULL means that the pointer is pointing no where)
//and then using NULL->left means we are trying to alloc memory to NULL , hence its wrong.
//So we need to include (a&&b) condition and if its false return false is executed. 

// bool Symmteric(node *a, node *b)
// {
// 	if(a->data!=b->data)
// 		return false;
// 	if(a==NULL && b==NULL)
// 		return true;
// 	return Symmteric(a->left,b->right) && Symmteric(a->right,b->left);
// }

bool Symmteric(node *a, node *b)
{
	if(a==NULL && b==NULL) //at the last node in both the subtrees(left and right)
		return true;
	if(a && b && a->data == b->data) //if the data is same and both the node exists
		return Symmteric(a->left,b->right) && Symmteric(a->right,b->left);
	return false;	//if any of the condition results false execute this statement
}


bool isSymmetric(node *root)
{
	if(root==NULL)
		return true;
	
	else
	{
		bool res = Symmteric(root->left,root->right);
		return res;
	}
}

int main()
{
	//Yes
	node *root;
	// root               = newNode(1);
	// root->left         = newNode(2); 
 //    root->right        = newNode(2); 
 //    root->left->left   = newNode(3); 
 //    root->left->right  = newNode(4); 
 //    root->right->left  = newNode(4); 
 //    root->right->right = newNode(3);

 //    delete(root);

    //No
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->right = newNode(3);
    root->right->right = newNode(3);

    bool res = isSymmetric(root);
    if(res == true)
    	cout<<"\nTree is Symmteric";
    else
    	cout<<"\nTree is not Symmteric";
	return 0;
}