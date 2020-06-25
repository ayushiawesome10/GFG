//Minimum operations required to make all the elements equal to or multiple of k

#include <iostream>
using namespace std;

int MinOperation(int arr[], int n, int k)
{
	int count = 0;
	for(int i=0; i<n; i++)
	{
		int floor = arr[i]/k;
		int ceil = floor+1;

		int d1 = abs(arr[i] - k*floor);
		int d2 = abs(arr[i] - k*ceil);

		count += min(d1, d2);

	}
	return count;
}

// Driver code 
int main() 
{ 
    int n, k;
     cout<<"\nEnter the value of n: ";
    cin>>n;
    cout<<"\nEnter the value of k: ";
    cin>>k;
    int arr[n];
    cout<<"\nEnter the values of the array: \n";
    for(int i=0; i<n; i++)
    	cin>>arr[i]; 
    cout << "\nThe min. no. of operations required are : " << MinOperation(arr, n, k) << endl; 
    return 0; 
} 