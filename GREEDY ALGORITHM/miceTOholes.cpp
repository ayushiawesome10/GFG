#include <bits/stdc++.h>
using namespace std;

int miceToholes(int holes[], int mice[], int n)
{
    sort(holes,holes+n);
    sort(mice,mice+n);

    int max = abs(holes[0] - mice[0]);
    for(int i=1; i<n; i++)
    {
        int sub = holes[i] - mice[i];
        if(abs(sub) > max)
            max = abs(sub);
    }
    return max;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int holes[n], mice[n];
        
        for(int i=0; i<n; i++)
            cin>>holes[i];
        for(int i=0; i<n; i++)
            cin>>mice[i];
            
        cout<<miceToholes(holes,mice,n)<<endl;
    }
	return 0;
}