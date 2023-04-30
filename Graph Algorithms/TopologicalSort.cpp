#include <iostream>
#include <stack>
#include <vector>

#include "Graph.h"

class DFS : public adj_list_node
{
public:
	void dfs(graph* g, int _v, bool* visited, std::stack<int>& stack)
	{
		visited[_v] = true;
		std::vector<int> vec;
		adj_list_node* root = g->arr[_v].head;

		while (root)
		{
			vec.push_back(root->data);
			root = root->next;
		}

		for (int i = 0; i < vec.size(); ++i)
		{
			std::cout << i << vec[i] << std::endl;
			if (!visited[vec[i]])
			{
				dfs(g, vec[i], visited, stack);
			}
		}
		stack.push(_v);
	}
};

void graph_node::add_edge_s(graph* grph, int src, int dst)
{
	adj_list_node* nptr = new_adj_list_node(dst);
	nptr->next = grph->arr[src].head;
	grph->arr[src].head = nptr;
}


class TopologicalSort : public DFS
{
public:
	void topological_sort(graph* g)
	{
		bool* visited = new bool[g->v];
		std::stack<int> st;

		for (int i = 0; i < g->v; ++i)
		{
			visited[i] = false; 
		}

		for (int i = 0; i < g->v; ++i)
		{
			if (!visited[i])
			{
				dfs(g, i, visited, st);
			}
		}

		while (!st.empty())
		{
			std::cout << st.top() << " ";
			st.pop();
		}std::cout << std::endl;
	}
};


int main()
{
	int vert = 8;

	graph* g;
	graph_node gn;

	g = gn.create_graph(vert);
	gn.add_edge_s(g, 0, 3);
	gn.add_edge_s(g, 0, 4);
	gn.add_edge_s(g, 1, 3);
	gn.add_edge_s(g, 2, 4);
	gn.add_edge_s(g, 2, 7);
	gn.add_edge_s(g, 3, 5);
	gn.add_edge_s(g, 3, 6);
	gn.add_edge_s(g, 3, 7);
	gn.add_edge_s(g, 4, 6);


	TopologicalSort ts;
	ts.topological_sort(g);

	gn.print_graph(g);

}
