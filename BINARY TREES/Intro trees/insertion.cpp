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

void insert(node* root,int x)
{
	queue<node*> q;
	q.push(root);

	while(!q.empty())
	{
		root = q.front();
		q.pop();
		if(root->left == NULL)
		{
			root->left = newNode(x);
			break;
		}
		else
		{
			q.push(root->left);	
		}

		if(root->right == NULL)
		{
			root->right = newNode(x);
			break;
		}
		else
		{
			q.push(root->right);
		}
	}
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

	cout<<"Preorder traversal before insertion : ";
	preorder(root);

	cout<<"\nEnter the value to be inserted : ";
	cin>>x;
	insert(root,x);

	cout<<"Preorder traversal after insertion : ";
	preorder(root);

	return 0;
}