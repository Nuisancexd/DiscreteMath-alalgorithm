#include <iostream>
#include <queue>
#include <vector>

#include "Graph.h"


class BFS : public adj_list_node
{
public:
	void bfs(graph* grph, int v)
	{
		std::vector<bool> visited(v, false);
		std::queue<int> que;
		que.push(v);
		visited[v - 1] = true;
		while (!que.empty())
		{
			v = que.front();
			std::cout << v << std::endl;
			que.pop();

			for (int i = 0; i < grph->v; ++i)
			{
				if (visited[i]) continue;
				adj_list_node* root = grph->arr[i].head;
				if (root)
				{
					visited[i] = true;
					que.push(root->data);
					root = root->next;
				}
			}
		}
	}

};




int main()
{
	int vert = 6;

	graph* g;
	graph_node gn;

	g = gn.create_graph(vert);
	gn.add_edge(g, 0, 1);
	gn.add_edge(g, 0, 2);
	gn.add_edge(g, 1, 2);
	gn.add_edge(g, 1, 3);
	gn.add_edge(g, 2, 3);
	gn.add_edge(g, 3, 4);
	gn.add_edge(g, 4, 0);
	gn.add_edge(g, 4, 1);
	gn.add_edge(g, 4, 5);

	BFS bfs;
	bfs.bfs(g, vert);
	std::cout << std::endl;
	gn.print_graph(g);

}
