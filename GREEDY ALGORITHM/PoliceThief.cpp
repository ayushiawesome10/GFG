#include <bits/stdc++.h>
using namespace std;

int catchThief(char arr[], int k, int n)
{
	int count = 0;
	vector<int> police;
	vector<int> thief;

	for(int i=0; i<n; i++)
	{
		if(arr[i]== 'P')
			police.push_back(i);
		
		else
			thief.push_back(i);
	}

	int i=0,j=0;
	while(i<police.size() && j<thief.size())
	{
		if(abs(police[i]-thief[j]) <= k)
		{
			count++;
			i++;
			j++;
		}
		else if(police[i] < thief[j])
			i++;
		else
			j++;
	}
	
	return count;
}

int main()
{
	int k;
	
	char arr1[] = {'P', 'T', 'T', 'P', 'T'};		//k=1 answer:2
	int n = sizeof(arr1)/sizeof(arr1[0]);
	cout<<"\nEnter the value of k : ";
	cin>>k;
	cout<<"\nThe total thief caught are : "<<catchThief(arr1,k,n)<<endl;

	char arr2[] = {'T', 'T', 'P', 'P', 'T', 'P'};	//k=2 answer:3
	n = sizeof(arr2)/sizeof(arr2[0]);	
	cout<<"\nEnter the value of k : ";
	cin>>k;
	cout<<"The total thief caught are : "<<catchThief(arr2,k,n)<<endl;

	char arr3[] = {'P', 'T', 'P', 'T', 'T', 'P'};	//k=3 answer:3
	n = sizeof(arr3)/sizeof(arr3[0]);
	cout<<"\nEnter the value of k : ";
	cin>>k;
	cout<<"The total thief caught are : "<<catchThief(arr3,k,n)<<endl;
	
	return 0;
}