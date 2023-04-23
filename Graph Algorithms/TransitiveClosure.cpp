#include <iostream>

#include "Graph.h"


class TransitiveClosure : public adj_list_node
{
public:

	int** transitive_closure(graph* grph, int** matrix)
	{
		for (int i = 0; i < grph->v; ++i)
		{
			adj_list_node* root = grph->arr[i].head;
			if (root)
			{
				matrix[i][root->data] = 1;
				root = root->next;
			}
		}
		for (int k = 0; k < grph->v; ++k)
		{
			for (int i = 0; i < grph->v; ++i) 
			{
				for (int j = 0; j < grph->v; ++j) 
				{
					if (matrix[i][k] && matrix[k][j]) 
					{
						matrix[i][j] = 1;
					}
				}
			}
		}
		return matrix;
	}
};


/*
void add_edge(graph* grph, int src, int dst)
	{
		adj_list_node* nptr = new_adj_list_node(dst);
		nptr->next = grph->arr[src].head;
		grph->arr[src].head = nptr;
		//nptr = new_adj_list_node(src);
		//nptr->next = grph->arr[dst].head;  -> уберем привязку принимающий узел в графе
		//grph->arr[dst].head = nptr;
	}

*/

int main()
{
	int vert = 4;

	graph* g;
	graph_node gn;

	g = gn.create_graph(vert);
	gn.add_edge(g, 3, 0);
	gn.add_edge(g, 0, 1);
	gn.add_edge(g, 2, 3);

	gn.print_graph(g);
	std::cout << std::endl;

	int** matrix = matrix = new int*[vert];
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


	TransitiveClosure TC;
	matrix = TC.transitive_closure(g, matrix);

	for (int i = 0; i < vert; ++i)
	{
		for (int j = 0; j < vert; ++j)
		{
			std::cout << matrix[i][j] << " ";
		}std::cout << std::endl;
	}
}


/*
	0 -> 1
	^         
	|
	3 <- 2

	транзитивное замыкание
	0 -> 1
	^ \/ ^
	| /\ |
	3 <- 2

*/
