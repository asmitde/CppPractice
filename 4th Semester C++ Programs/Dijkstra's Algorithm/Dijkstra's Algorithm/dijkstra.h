class Dijkstra
{
private:
	int **graph, noOfNodes;
	bool *V, *S;
	int *D;
	int source;

	void process();
	bool VequalToS();

public:
	Dijkstra(int **g, int n, int s);

	int getMinimumPathWeight(int d);
	int* getMinimumPathWeight();
};

Dijkstra::Dijkstra(int **g, int n, int s)
{
	graph = g;
	noOfNodes = n;
	source = s;

	V = new bool[n];
	for(int i = 0; i < n; i++)
		V[i] = true;

	S = new bool[n];
	for(int i = 0; i < n; i++)
		S[i] = false;

	D = new int[n];

	process();
};

void Dijkstra::process()
{
	S[source] = true;
	D[source] = 0;

	for(int i = 0; i < noOfNodes; i++)
	{
		if(i == source)
			continue;

		D[i] = graph[source][i];
	}

	while(!VequalToS())
	{
		int v, l = 9999;
		for(int i = 0; i < noOfNodes; i++)
		{
			if(S[i])
				continue;

			if(D[i] < l)
			{
				l = D[i];
				v = i;
			}
		}

		S[v] = true;
		
		for(int i = 0; i < noOfNodes; i++)
		{
			if(S[i])
				continue;

			D[i] = std::min(D[i], D[v] + graph[i][v]);
		}
	}
}

bool Dijkstra::VequalToS()
{
	for(int i = 0; i < noOfNodes; i++)
	{
		if(V[i] != S[i])
			return false;
	}

	return true;
}

int Dijkstra::getMinimumPathWeight(int d)
{
	return D[d];
}

int* Dijkstra::getMinimumPathWeight()
{
	return D;
}