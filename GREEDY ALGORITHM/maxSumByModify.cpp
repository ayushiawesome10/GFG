#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int maxSum(int arr[], int n, int k)
{
    int sum = 0;
    for(int j=1; j<=k; j++)
    {
        int minimum = INT_MAX, index = -1;
        for(int i=0; i<n; i++)
        {
            if(arr[i] < minimum)
            {
                minimum = arr[i];
                index = i;
            }
        }
        if(minimum == 0)
            break;
        arr[index] = arr[index]*-1;
    }

    for(int j=0; j<n; j++)
        sum += arr[j];

    return sum;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cout<<"\nEnter the values of n and k : ";
        cin>>n>>k;
        int arr[n];
        cout<<"\nEnter the values of the array : ";
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<"\nMax sum is : "<<maxSum(arr,n,k);
        cout<<endl;
    }
    return 0;
}

//{ -2, 0, 5, -1, 2 } n=5 k=4 output:10
//{9, 8, 8, 5} n=4 k=3 output:20