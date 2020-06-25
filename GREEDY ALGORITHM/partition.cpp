//Partition into two subarrays of lengths k and (N-k) such that
//the difference of sums is maximum

#include <iostream>
#include <algorithm>
using namespace std;

int maxDifference(int arr[], int n, int k)
{
	sort(arr, arr+n);
	int min_sum = 0;
	for(int i=0; i<k; i++)
		min_sum += arr[i];
	int max_sum = 0;
	for(int j=k; j<n; j++)
		max_sum += arr[j];

	int res = max_sum-min_sum;
	return res;
} 

// Driver function 
int main() 
{ 
    // int arr[] = { 8, 4, 5, 2, 10 }; 	//17
    // int N = sizeof(arr) / sizeof(arr[0]); 
    // int k = 2; 
    int arr[] = {1, 1, 1, 1, 1, 1, 1, 1}; //2
    int N = sizeof(arr) / sizeof(arr[0]); 
    int k = 3;
    cout << maxDifference(arr, N, k) << endl; 
    return 0; 
} 