#include <iostream>
#include <stack>
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

void inorder(node *root)
{
	stack<node*> s;
	node *current = root;

	while(current!=NULL || !s.empty())
	{
		while(current!=NULL)
		{
			s.push(current);
			current = current->left;
		}
		current = s.top();
		s.pop();
		cout<<current->data<<" ";
		current = current->right;

	}
}

int main()
{
	node *root = new node;
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	inorder(root);

	return 0;
}