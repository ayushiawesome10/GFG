#include<bits/stdc++.h>
#include <stack>
using namespace std;

void minSwap(char s[], int n)
{
    stack<char> st;
    int count = 0, j;
    for(int i=0; s[i]!='\0'; i++)
    {
        if(s[i] == '[')
            st.push(s[i]);
        else if(s[i] ==']' && !st.empty() && st.top()=='[')
            st.pop();
        else if(s[i]==']')
        {
            j = i;
            while(s[j]!='[')
                j++;
            if(s[j]=='[')
            {
                swap(s[i],s[j]);
                count = count+(j-i);
                st.push(s[i]);
            }
        }
    }
    cout<<count<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        char s[n];
        for(int i=0; i<n; i++)
            cin>>s[i];
        
        minSwap(s,n);
    }
    return 0;
}