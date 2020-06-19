#include<bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    int deadline;
    int profit;
};

bool compare(Job a,Job b){
    return a.profit > b.profit;
}

void JobSequence(struct Job arr[], int n)
{
    sort(arr,arr+n,compare);
    int count_job = 0, max_profit = 0;
    bool slot[n] = {false};
    
    for(int i=0; i<n; i++)
    {
        for(int j=min(n-1,arr[i].deadline-1); j>=0; j--)
        {
            if(!slot[j])
            {
                slot[j] = true;
                max_profit += arr[i].profit;
                count_job++;
                break;
            }
        }
    }
    cout<<count_job<<" "<<max_profit;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        Job arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i].id>>arr[i].deadline>>arr[i].profit;
        }
        JobSequence(arr,n);
        cout<<endl;
    }
    return 0;
}