#include <iostream>
#include <queue>
using namespace std;

struct node {
	int data;
	node *left;
	node *right;
};

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

node* search(node* root, int x)
{
	node *temp = root;
	node *del = NULL;
	while(temp->left!=NULL && temp->right!=NULL)
	{
		if(temp->left->data == x)
		{
			del = temp->left;
			break;
		}
		else if(temp->right->data == x)
		{
			del = temp->right;
			break;
		}
		else
			continue;
	}
	return del;
}

node *rightmost(node* root)
{
	node *rtmost;
	queue<node*> q;

	if(root->left!=NULL)
	{
		q.push(root->left);
	}
	if(root->right!=NULL)
	{
		q.push(root->right);
	}
	rtmost = q.back();
	return rtmost;
}

void remove(node* root, int x)
{
	node *del = search(root,x);
	node *rtmost = rightmost(root);
	node *t = del;
	del = rtmost;
	rtmost = t;

	//delete del;
}

int main()
{
	node *root;
	int x;
	
	root =  new node;
	root = newNode(1);
	root->left = newNode(2);
	root->right= newNode(3);
	root->left->left = newNode(4);

	cout<<"Preorder traversal before deletion : ";
	preorder(root);

	cout<<"\nEnter the key to be deleted: ";
	cin>>x;
	remove(root,x);

	cout<<"Preorder traversal after deletion : ";
	preorder(root);

	return 0;
}