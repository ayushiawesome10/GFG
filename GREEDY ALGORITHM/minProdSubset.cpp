#include <iostream>
using namespace std;

int minProd(int arr[], int n)
{
	int zeroCount = 0, posCount = 0, negCount = 0;
	int max_neg, min_pos, prod;

	for(int i=0; i<n; i++)
	{
		if(arr[i] < 0)
		{
			negCount++;
			max_neg = max(max_neg, arr[i]); 
		}
		
		else if(arr[i] == 0)
		{
			zeroCount++;
		}
		
		else
		{
			posCount++;
			min_pos = min(min_pos, arr[i]);
		}
		prod *= arr[i];
	}

	if(zeroCount==n || (negCount==0 && zeroCount > 0))
		return 0;
	if(negCount == 0)
		return min_pos;
	if(negCount%2==0 && negCount!=0)
		prod = prod/max_neg;
	return prod;
}

int main()
{
	int arr[] = {-1,-1,-2,4,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout<<minProd(arr,n)<<endl;

	return 0;
}