#include "stacklnk.h"
#include "queuelnk.h"

class Graph
{
private:
	int noOfNodes;
	bool *isVisited;
	int *num, *pred;
	int n;

	void strongDFS(int v);

public:
	bool **adjacency;
	int **wtMat;

	Graph(int n);
	~Graph();

	void dfsTraversal(int s);
	void bfsTraversal(int s);
	int getNoOfConnectedComponents();
	int getNoOfStronglyConnectedComponents();
	void minimumSpanningTree();

	friend ostream& operator<<(ostream &gout, Graph &gph);
	friend istream& operator>>(istream &gin, Graph &gph);
};

Graph::Graph(int n)
{
	noOfNodes = n;

	isVisited = new bool[n];

	adjacency = new bool*[n];
	for(int i = 0; i < n; i++)
		adjacency[i] = new bool[n];

	wtMat = new int*[n];
	for(int i = 0; i < n; i++)
		wtMat[i] = new int[n];
}

Graph::~Graph()
{
	delete []isVisited;
	delete []adjacency;
}

ostream& operator<<(ostream &gout, Graph &gph)
{
	for(int i = 0; i < gph.noOfNodes; i++)
	{
		for(int j = 0; j < gph.noOfNodes; j++)
			gout<<(int)gph.adjacency[i][j]<<"\t";

		gout<<endl;
	}

	return gout;
}

istream &operator>>(istream &gin, Graph &gph)
{
	for(int i = 0; i < gph.noOfNodes; i++)
		for(int j = 0; j < gph.noOfNodes; j++)
			gin>>gph.wtMat[i][j];

	return gin;
}

void Graph::dfsTraversal(int s)
{
	Stack<int> trvStck;
	trvStck.push(s);

	for(int i = 0; i < noOfNodes; i++)
		isVisited[i] = false;
	int visitedNodes = 0;

	while(visitedNodes < noOfNodes)
	{
		int node = trvStck.pop();
		
		if(!isVisited[node])
		{
			cout<<node<<" ";
			isVisited[node] = true;
			visitedNodes++;
		}

		for(int i = 0; i < noOfNodes; i++)
		{
			if(i == node)
				continue;

			if(adjacency[node][i] == true && !isVisited[i])
				trvStck.push(i);
		}
	}
}

void Graph::bfsTraversal(int s)
{
	Queue<int> trvQ;
	trvQ.enqueue(s);
	
	for(int i = 0; i < noOfNodes; i++)
		isVisited[i] = false;
	int visitedNodes = 0;

	while(visitedNodes < noOfNodes)
	{

		int node = trvQ.dequeue();

		if(!isVisited[node])
		{
			cout<<node<<" ";
			isVisited[node] = true;
			visitedNodes++;
		}

		for(int i = 0; i < noOfNodes; i++)
		{
			if(i == node)
				continue;

			if(adjacency[node][i] == true && !isVisited[i])
				trvQ.enqueue(i);
		}
	}
}

int Graph::getNoOfConnectedComponents()
{
	Stack<int> trvStck;

	for(int i = 0; i < noOfNodes; i++)
		isVisited[i] = false;
	int visitedNodes = 0;
	int components = 0;

	while(visitedNodes < noOfNodes)
	{
		components++;
		for(int i = 0; i < noOfNodes; i++)
			if(!isVisited[i])
			{
				trvStck.push(i);
				break;
			}

		while(trvStck.getSize())
		{
			int node = trvStck.pop();
			
			if(!isVisited[node])
			{
				isVisited[node] = true;
				visitedNodes++;
			}
	
			for(int i = 0; i < noOfNodes; i++)
			{
				if(i == node)
					continue;
	
				if(adjacency[node][i] == true && !isVisited[i])
					trvStck.push(i);
			}
		}
	}

	return components;
}

int Graph::getNoOfStronglyConnectedComponents()
{
	num = new int[noOfNodes];
	for(int i = 0; i < noOfNodes; i++)
		num[i] = 0;

	pred = new int[noOfNodes];
	for(int i = 0; i < noOfNodes; i++)
		pred[i] = 0;
	n = 1;

	for(int i = 0; i < noOfNodes; i++)
		if(num[i] == 0)
			strongDFS(i);

	return n;
}

void Graph::strongDFS(int v)
{
	Stack<int> trvStck;
	pred[v] = num[v] = n++;
	trvStck.push(v);

	for(int i = 0; i < noOfNodes; i++)
	{
		if(adjacency[v][i] == false)
			continue;

		if(num[i] == 0)
		{
			strongDFS(i);
			pred[v] = min(pred[i], pred[v]);
		}
		else if(num[i] < num[v] && trvStck.top() == i)
			pred[v] = min(pred[v], num[i]);
	}
}

void Graph::minimumSpanningTree()
{
	Graph sptree(noOfNodes);
	for(int i = 0; i < noOfNodes; i++)
		for(int j = 0; j < noOfNodes; j++)
			sptree.adjacency[i][j] = false;

	for(int i = 0; i < noOfNodes; i++)
		isVisited[i] = false;
	isVisited[0] = true;

	for(int i = 1; i < noOfNodes; i++)
	{
		int minWt = 9999, snode = i, dnode = i;
		for(int j = 0; j < noOfNodes; j++)
		{
			if(!isVisited[j])
				continue;

			for(int k = 0; k < noOfNodes; k++)
			{
				if(isVisited[k])
					continue;

				if(wtMat[j][k] < minWt)
				{
					minWt = wtMat[j][k];
					snode = j;
					dnode = k;
				}
			}
		}

		isVisited[dnode] = true;
		sptree.adjacency[snode][dnode] = sptree.adjacency[dnode][snode] = true;
	}

	cout<<endl<<sptree;
}