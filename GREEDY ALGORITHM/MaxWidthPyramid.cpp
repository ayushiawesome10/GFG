//Find maximum height pyramid from the given array of objects
#include <iostream>
#include <algorithm>
using namespace std;

int maxLevel(int arr[], int n)
{
	int height = 1;
	sort(arr, arr+n);
	
	int prev_count=1, prev_width=arr[0]; 

	int cur_count =0, cur_width=0;
	for(int i=1; i<n; i++)
	{
		cur_width += arr[i];
		cur_count += 1;

		if(cur_count > prev_count && cur_width > prev_width)
		{
			prev_width = cur_width;
			prev_count = cur_count;

			height++;
			
			cur_width = 0;
			cur_count = 0;
		}
	}
	return height;
}

// Driver Program 
int main() 
{ 
    //int boxes[] = {10, 20, 30, 50, 60, 70};	//3 
	int boxes[] = {40, 100, 20, 30};	//2
    int n = sizeof(boxes)/sizeof(boxes[0]); 
    cout << maxLevel(boxes, n) << endl; 
    return 0; 
} 