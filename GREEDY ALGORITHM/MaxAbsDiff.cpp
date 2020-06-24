//Max. sum of absolute difference of any permutation
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MaxSumDifference(int arr[], int n)
{
	sort(arr, arr+n);
	vector<int> a;

	for(int i = 0; i <= n/2; i++)
	{
		a.push_back(arr[i]);
		a.push_back(arr[n-i-1]);
	}

	int sum = abs(a[0]-a[n-1]);
	for(int j=1; j<n; j++)
	{
		sum += abs(a[j] - a[j-1]);
	}
	return sum;
}

// Driver function 
int main() 
{ 
    int a[] = { 1, 4, 2, 8 }; 
    int n = sizeof(a) / sizeof(a[0]); 
  	cout << MaxSumDifference(a, n) << endl; 
} 