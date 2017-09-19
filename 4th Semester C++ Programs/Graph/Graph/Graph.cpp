#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
	cout<<"Enter the number of nodes in Graph: ";
	int n; cin>>n;

	Graph g(n);
	cout<<endl<<"Enter the wt matrix of the graph:"<<endl;
	cin>>g;
/*
	cout<<endl<<"Number of connected components in graph: "<<g.getNoOfConnectedComponents();

	cout<<endl<<"Enter the starting node of graph for traversal: ";
	int s; cin>>s;
	cout<<endl<<"DFS Traversal:"<<endl;
	g.dfsTraversal(s);
	
	cout<<endl<<"BFS Traversal:"<<endl;
	g.bfsTraversal(s);
	*/

	g.minimumSpanningTree();
	cout<<endl;
	return 0;
}

