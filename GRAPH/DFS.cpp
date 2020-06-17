// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/
void dfsutil(vector<int> g[], int i, bool visited[], vector<int>* result)
{
    visited[i] = true;
    result->push_back(i);
    
    for(auto j=g[i].begin(); j!=g[i].end(); j++)
    {
        if(!visited[*j])
        {
            //visited[*j] = true;
            dfsutil(g,*j,visited,result);
        }
    }
    
}
//Count gives the total no. of connected nodes in the graph
vector<int> dfs(vector<int> g[], int N)
{
    
    // Your code here
    bool visited[N] = {false};
    int count =0;
    vector<int> res;
    for(int i=0; i<N; i++)
    {
        if(visited[i]==false)
        {
            count++;
            dfsutil(g,i,visited,&res);
        }
    }
    cout<<"No. of disconnected graph : "<<count<<endl;
    return res;
}



// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}  // } Driver Code Ends