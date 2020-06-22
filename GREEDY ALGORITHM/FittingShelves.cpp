#include <iostream>
using namespace std;

void maxShelves(int wall, int m, int n) 
{ 
    // for simplicity, Assuming m is always smaller than n 
    // initializing output variables 
    int num_m = 0, num_n = 0, min_empty = wall; 
  
    // p and q are no of shelves of length m and n 
    // rem is the empty space 
    int p = 0, q = 0, rem; 
  
    while (wall >= n) { 
        // place as many shelves of length m 
        // in the remaining part 
        p = wall / m; 
        rem = wall % m; 
  
        // update output variablse if curr 
        // min_empty <= overall empty 
        if (rem <= min_empty) { 
            num_m = p; 
            num_n = q; 
            min_empty = rem; 
        } 
  
        // place one more shelf of length n 
        q += 1; 
        wall = wall - n; 
    } 
  
    cout << num_m << " " << num_n << " "
         << min_empty << endl; 
} 


int main(int argc, char const *argv[])
{
	cout<<"\nEnter the no. of test cases : ";
	int t;
	cin>>t;
	while(t--)
	{
		int w,m, n;
		cout<<"\nLength of the wall        : ";
		cin>>w;
		cout<<"Min. length among the two : ";
		cin>>m;
		cout<<"Max. length among the two : ";
		cin>>n;

		maxShelves(w,m,n);
	}
	return 0;
}