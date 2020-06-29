//From coding ninjas easy to understand but gives problems for other input
#include <iostream>
#include <algorithm>
using namespace std;

class Edge{
public:
	int source;
	int dest;
	int weight;
};

bool compare(Edge e1, Edge e2)
{
	return  e1.weight < e2.weight;
}

int find(int i, int* parent)
{
	if(parent[i] == i)
		return i;
	return find(parent[i], parent);
}

void kruskal(Edge *input, int n, int e)
{
	sort(input, input+e, compare);

	Edge *output = new Edge[n-1];
	
	int *parent = new int[n];
	
	for(int i=0; i<n; i++)
		parent[i] = i;

	int count = 0;
	int i=0;
	
	while(count != n-1)
	{
		Edge current = input[i];

		int sourceParent = find(current.source, parent);
		int destParent = find(current.dest, parent);

		if(sourceParent != destParent)
		{
			output[count] = current;
			count++;
			parent[sourceParent] = destParent;
		}	
		i++;
	}

	cout << "\nDISPLAYING THE OUTPUT OF KRUSKAL ALGORITHM\n";

	for(int i=0; i<n-1; i++)
		if(output[i].source < output[i].dest)
			cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;

		else
			cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
}		

int main()
{
	int n, E;
	cin >> n >> E;

	Edge *input = new Edge[E];

	cout<<"\nEnter the values of the graph : source : dest : weight\n";
	for(int i=0; i<E; i++)
		cin >> input[i].source >> input[i].dest >> input[i].weight;
	
	kruskal(input, n, E);

	return 0;
}


//INPUT
/*6 11
1 3 1
0 1 2
0 3 3
0 2 4
4 5 5
2 3 6
3 5 7
2 1 8
2 4 9
3 4 11
2 5 10*/

/*4 5
0 1 10 
0 2 6
0 3 5 
1 3 15
2 3 4*/
