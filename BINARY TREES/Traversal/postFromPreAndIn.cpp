#include <iostream>
using namespace std;

const int initial = 0; 

int search(int in[], int start, int end, int key)
{
	for(int i=start; i < end; i++)
	{
		if(in[i] == key)
			return i;
	}
	return -1;
}

void printPostOrder(int in[], int pre[], int start, int end)
{
	if(start > end)
		return;
	int k = search(in, start, end, pre[initial++]);

	//if the left subtree exists
	printPostOrder(in, pre, start, k-1);
	//if the right subtree exists
	printPostOrder(in, pre, k+1, end);
} 

// Driver program to test above functions 
int main() 
{ 
    int in[] = { 4, 2, 5, 1, 3, 6 }; 
    int pre[] = { 1, 2, 4, 5, 3, 6 }; 
    int n = sizeof(in) / sizeof(in[0]); 
    cout << "Postorder traversal " << endl; 
    printPostOrder(in, pre,0, n-1); 
    return 0; 
} 