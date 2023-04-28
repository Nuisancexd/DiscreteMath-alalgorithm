#include <iostream>
#include <vector>

#define MAX 100

struct Edge
{
	int v, u, weight;

	Edge(int v, int u, int weight)
	{
		this->v = v;
		this->u = u;
		this->weight = weight;
	}
};


class FordBellman
{
public:
	std::vector<Edge> edge;
	int v;
	FordBellman(std::vector<Edge>& _edge) 
	{
		this->edge = _edge; 
	}
	

	void ford_bellman(int source, int v, int e, int* dst)
	{
		int* dist = new int[v];

		for (int i = 0; i < v; ++i)
		{
			dist[i] = MAX;
		}
		dist[source] = 0;
	
		for (int i = 0; i < v - 1; ++i)
		{
			for (int j = 0; j < e; ++j)
			{
				if (dist[edge[j].v] < MAX)
				{
					dist[edge[j].u] = std::min(dist[edge[j].u], dist[edge[j].v] + edge[j].weight);
				}
			}
		}

		memcpy(dst, dist, sizeof(int) * e);
	}
};


int main()
{
	int vert = 4;
	int edges = 5;

	std::vector<Edge> edge;
	
	edge.push_back(Edge(0, 3, 4));
	edge.push_back(Edge(3, 2, 3));
	edge.push_back(Edge(3, 1, 1)); 
	edge.push_back(Edge(1, 2, 5));
	edge.push_back(Edge(2, 0, 6));


	FordBellman fb(edge);
	int* dist = new int[vert];
	int source = 2;
	fb.ford_bellman(source, vert, edges, dist);

	for (int i = 0; i < vert; ++i)
	{
		std::cout << dist[i] << " ";
	}
}
