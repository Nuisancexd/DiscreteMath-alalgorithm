#include <iostream>
#include <vector>

#include "Graph.h"

class IstokStok : public adj_list_node
{
public:
	void istok_stok(graph* g, int** matrix, std::vector<int>& st, std::vector<int>& ist)
	{
		for (int i = 0; i < g->v; ++i)
		{
			adj_list_node* root = g->arr[i].head;
			while(root)
			{
				matrix[i][root->data] = 1;
				root = root->next;
			}
		}
		
		for (int i = 0; i < g->v; ++i)
		{
			bool succ = true;
			for (int j = 0; j < g->v && succ; ++j)
			{
				if (matrix[i][j] == 1)
				{
					succ = false;
				}
			}
			if (succ)
			{
				st.push_back(i);
			}
		}
		for (int i = 0; i < g->v; ++i)
		{
			bool succ = true;
			for (int j = 0; j < g->v && succ; ++j)
			{
				if (matrix[j][i] == 1)
				{
					succ = false;
				}
			}
			if (succ)
			{
				ist.push_back(i);
			}
		}
	}
};


void graph_node::add_edge_s(graph* grph, int src, int dst)
{
	adj_list_node* nptr = new_adj_list_node(dst);
	nptr->next = grph->arr[src].head;
	grph->arr[src].head = nptr;
}


int main()
{
	setlocale(LC_ALL, "rus");

	int vert = 5;

	graph* g;
	graph_node gn;

	g = gn.create_graph(vert);
	gn.add_edge_s(g, 2, 0);
	gn.add_edge_s(g, 2, 1);
	gn.add_edge_s(g, 1, 4);
	// 2 3 - истоки, так как в них не входит ни одного ребра
	// 0, 3, 4 - стоки, так как из них не исходит ни одного ребра

	gn.print_graph(g);

	int** matrix = matrix = new int* [vert];
	for (int i = 0; i < vert; ++i)
	{
		matrix[i] = new int[vert];
	}

	for (int i = 0; i < vert; ++i)
	{
		for (int j = 0; j < vert; ++j)
		{
			matrix[i][j] = 0;
		}
	}

	IstokStok is;
	std::vector<int> st;
	std::vector<int> ist;

	is.istok_stok(g, matrix, st, ist);

	for (int i = 0; i < vert; ++i)
	{
		for (int j = 0; j < vert; ++j)
		{
			std::cout << matrix[i][j] << " ";
		}std::cout << std::endl;
	}std::cout << std::endl;
	
	for (auto e : st)
	{
		std::cout << "Стоки: " << e << " ";
	} std::cout << std::endl;

	for (auto e : ist)
	{
		std::cout << "Истоки: " << e << " ";
	} std::cout << std::endl;
}
