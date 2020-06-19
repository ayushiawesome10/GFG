#include <bits/stdc++.h>
using namespace std;

struct Huffman{
    char data;
    int freq;
    Huffman *left, *right;
};

Huffman *init(char value, int freq)
{
    Huffman *node;
    node = new Huffman;
    node->data = value;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n = s.length();
        Huffman h[n];
        
        for(int i=0; i<n; i++)
        {
            h[i].data = s[i];
        }
        for(int i=0; i<n; i++)
        {
            cin>>h[i].freq;
        }
    

    }
	return 0;
}