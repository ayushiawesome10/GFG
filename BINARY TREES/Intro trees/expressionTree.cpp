#include <bits/stdc++.h> 
using namespace std;

struct node
{
	char data;
	node *left, *right;
};

node *newNode(char data)
{
	node *r;
	r = new node;
	r->data = data;
	r->left = r->right = NULL;
	return r;
}

void inorder(node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

bool isOperator(char op){
	if(op=='+' || op=='-' || op=='*' || op=='/' || op=='^')
		return true;
	else
		return false;
}

bool isOperand(char c)
{
	if((c>='a' && c<='z') || (c>='A' && c<='Z'))
		return true;
	else
		return false;
}

node *constructTree(char postfix[])
{
	stack<node*> s;
	node *t, *t1, *t2;
	for(int i=0; postfix[i]!='\0'; i++)
	{
		char ch = postfix[i];
		
		if(isOperand(ch))
		{
			t = newNode(ch);
			s.push(t);
		}
		if(isOperator(ch))
		{
			t = newNode(ch);
			t2 = s.top();
			s.pop();
			t1 = s.top();
			s.pop();
			
			t->left = t1;
			t->right = t2;
			s.push(t);
		}
	}
	t = s.top();
	s.pop();
	return t;
}

int main() 
{ 
    char postfix[] = "ab+ef*g*-"; 
    node* r = constructTree(postfix); 
    printf("infix expression is \n"); 
    inorder(r); 
    return 0; 
} 