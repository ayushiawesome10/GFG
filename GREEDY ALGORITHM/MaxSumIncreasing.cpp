//Maximum sum of increasing order elements from n arrays
#include <bits/stdc++.h> 
#define M 4 
using namespace std; 

int maximumSum(int arr[][M], int n);

int maximumSum(int arr[][M], int n)
{
	int sum = *max_element(&arr[n-1][0], &arr[n-1][M-1]);	//Max. element from last row
	int prev_max = sum;	//stores the max element found so far from prev row
	for(int i=n-2; i>=0; i--)	//start from second last row
	{
		int max = INT_MIN;
		for(int j=0; j<M; j++)	//iterate to all the cols.
		{	
			if(arr[i][j] < prev_max && arr[i][j] > max)
			//if given new val is greater than the prev element then add 
			{
				max = arr[i][j];
			}
		}
		if(max == INT_MIN)
			return 0;
		sum += max;
		prev_max = max;
	}
	return sum;
}

int main() { 
  int arr[][M] = {{1, 7, 3, 4},  
                  {4, 2, 5, 1},  	//=>18
                  {9, 5, 1, 8}}; 
  int n = sizeof(arr) / sizeof(arr[0]);	//3x4
  cout<<maximumSum(arr,n)<<endl;
  return 0; 
} 

/*int maximumSum(int a[][M], int n)
{
	for(int i=0; i<n; i++)
		sort(a[i], a[i]+M);

	int sum = a[n-1][M-1];
	int prev = sum;
	int i, j;

	for(i=n-2; i>=0; i--)
	{
		for(j=M-1; j>=0; j--)
		{
			if(a[i][j] < prev)
			{
				prev = a[i][j];
				sum += prev;
				break;
			}
		}
		if(j==-1)
			return 0;
	}
	return sum;
}*/