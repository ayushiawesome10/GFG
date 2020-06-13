#include <bits/stdc++.h> 
using namespace std;

class node
{
public:
    char c;
    node *left = NULL, *right = NULL;
    node(char ch)
    {
        c = ch;
    }
};

bool isOperator(char op){
    if(op=='+' || op=='-' || op=='*' || op=='/' || op=='^')
        return true;
    else
        return false;
}

int chartoInt(char ch)
{
    return ch - 48;
}

int eval(node *root)
{
    if(root==NULL)
    {
        cout<<"Empty tree";
        return 0;
    }
    if(root->left==NULL && root->right==NULL)
        return chartoInt(root->data);

}

int main()  
{  
    // create a syntax tree  
    node *root = new node('+');  
    root->left = new node('*');  
    root->left->left = new node('5');  
    root->left->right = new node('-4');  
    root->right = new node('-');  
    root->right->left = new node('1');  
    root->right->right = new node('2');  
    cout << eval(root) << endl;  
  
    delete(root);  
  
    // root = new node('+');  
    // root->left = new node('*');  
    // root->left->left = new node('5');  
    // root->left->right = new node('4');  
    // root->right = new node('-');  
    // root->right->left = new node('100');  
    // root->right->right = new node('/');  
    // root->right->right->left = new node('20');  
    // root->right->right->right = new node('2');  
  
    // cout << eval(root) << endl;  
    return 0;  
}  