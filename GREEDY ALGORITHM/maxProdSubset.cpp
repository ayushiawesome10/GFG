#include <iostream>
using namespace std;

int maxProd(int arr[], int n)
{
	if(n==1)
		return arr[0];

	int max_neg = INT_MIN, zeroCount=0, posCount=0, negCount=0, prod;   

	for(int i=0; i<n; i++)
	{
		if(arr[i]>0)
		{
			posCount++;
		}
		else if(arr[i]==0)
		{
			zeroCount++;
		}
		else
		{
			negCount++;
			max_neg = max(max_neg, arr[i]);
		}

		prod *= arr[i];
	}
	if(zeroCount==n)
		return 0;

	if (negCount & 1) { 
  
        // Exceptional case: There is only 
        // negative and all other are zeros 
        if (negCount == 1 && zeroCount > 0 &&  zeroCount + negCount == n) 
            return 0; 
  
        // Otherwise result is product of  
        // all non-zeros divided by maximum 
        // valued negative. 
        prod = prod / max_neg; 
    } 

	return prod;
}

int main()
{
	//int arr[] = {-4, -20, -1, -10, 2, 4};
	int arr[] = {  -1, -1, -2, 4, 3  };
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<maxProd(arr,n)<<endl;

	return 0;
}