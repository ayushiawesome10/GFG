// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}// } Driver Code Ends


/* You have to complete this function*/

/* Function to do BFS of graph
*  g[]: adj list of the graph
*  N : number of vertices
*/
// 

//Below one also works
vector <int> bfs(vector<int> g[], int N) {

    // Your code here
    queue<int> q;
    vector<int> result;
    bool visited[N] ={false};
    q.push(0);
    result.push_back(0);
    visited[0] = true;

    while(!q.empty())
    {
        int front = q.front();
        q.pop();
        for(auto i=g[front].begin(); i!=g[front].end(); i++)
        {
            if(visited[*i]==false)
            {
                result.push_back(*i);
                q.push(*i);
                visited[*i] = true;
            }
        }
        
    }
    return result;
}


//Does not print the last node
//vector <int> bfs(vector<int> g[], int N) {

//     // Your code here
//     bool visited[N] = {false};
//     queue<int> q;
//     vector<int> result;
    
//     q.push(0);
//     visited[0] = true;
//     result.push_back(0);
    
//     while(!q.empty())
//     {
//         int top = q.front();
//         q.pop();
        
//         //for(auto i=g[top].begin(); i<g[top].end(); i++)
//         for(auto i=0; i<=g[top].size(); i++)
//         {
//             if(visited[i] == false)
//             {
//                 visited[i] = true;
//                 result.push_back(i);
//                 q.push(i);
//             }
//         }
//         //q.pop();
//     }
    
//     return result;
// }