// C++ Program to print 
// count of nodes 
// at given level. 
#include <iostream> 
#include <list> 
#include <vector>
#include <queue>

using namespace std; 

// This class represents 
// a directed graph 
// using adjacency 
// list representation 
class Graph { 
	// No. of vertices 
	int V; 

	// Pointer to an 
	// array containing 
	// adjacency lists 
	list<int>* adj; 

public: 
	// Constructor 
	Graph(int V); 

	// function to add 
	// an edge to graph 
	void addEdge(int v, int w); 

	// Returns count of nodes at 
	// level l from given source. 
	int BFS(int s, int l); 
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	// Add w to v’s list. 
	adj[v].push_back(w); 

	// Add v to w's list. 
	adj[w].push_back(v); 
} 

int Graph::BFS(int s, int l) 
{ 
	bool visited[V] = {false};
	queue<int> q;
	int level[V] = {0};
	//int s;

	q.push(0);
	visited[0] = true;
	level[s] = 0;

	while(!q.empty())
	{
		s = q.front();
		q.pop();

		for(auto i=adj[s].begin(); i!=adj[s].end(); i++)
		{
			if(!visited[*i])
			{
				q.push(*i);
				visited[*i] = true;
				level[*i] = level[s]+1;
			}
		}
	}
	int count = 0;
	for(int i=0; i<V; i++)
	{
		if(level[i] == l)
			count++;
	}
	return count;
} 

// Driver program to test 
// methods of graph class 
int main() 
{ 
	// Create a graph given 
	// in the above diagram 
	Graph g(6); 
	g.addEdge(0, 1); 
	g.addEdge(0, 2); 
	g.addEdge(1, 3); 
	g.addEdge(2, 4); 
	g.addEdge(2, 5); 

	int level = 2; 

	cout << g.BFS(0, level); 

	return 0; 
} 
/*
Adj list

0 --> 1 -> 2
1 --> 0 -> 3
2 --> 0 -> 4 -> 5
3 --> 1
4 --> 2
5 --> 3

		Tree graph
			0
		  /   \
		 1     2
		/      /\
	   3      4  5*/