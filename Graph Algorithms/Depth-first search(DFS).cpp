
#include <iostream>
#include <stack>
#include <vector>

#include "Graph.h"

class DFS : public adj_list_node
{
public:
	
	void dfs(graph* grph, int v)
	{
		std::stack<int> st;
		std::vector<bool> visited(v, false);

		st.push(v);

		while (!st.empty())
		{
			v = st.top();
			std::cout << v << std::endl;
			st.pop();

			for (int i = 0; i < grph->v; ++i)
			{
				if (visited[i]) continue;
				adj_list_node* root = grph->arr[i].head;
				if (root)
				{
					visited[i] = true;
					st.push(root->data);
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

	DFS dfs;

	dfs.dfs(g, vert);

	gn.print_graph(g);
}
