#pragma once

#include <iostream>

struct adj_list_node
{
	int data;
	adj_list_node* next;
};

struct adj_list
{
	adj_list_node* head;
};

struct graph
{
	int v;
	adj_list* arr;
};

class graph_node
{
public:
	adj_list_node* new_adj_list_node(int data)
	{
		adj_list_node* nptr = new adj_list_node;
		nptr->data = data;
		nptr->next = NULL;
		return nptr;
	}

	graph* create_graph(int v)
	{
		graph* grph = new graph;
		grph->v = v;
		grph->arr = new adj_list[v];

		for (int i = 0; i < v; i++)
		{
			grph->arr[i].head = NULL;
		}
		return grph;
	}

	void add_edge(graph* grph, int src, int dst)
	{
		adj_list_node* nptr = new_adj_list_node(dst);
		nptr->next = grph->arr[src].head;
		grph->arr[src].head = nptr;
		nptr = new_adj_list_node(src);
		nptr->next = grph->arr[dst].head;
		grph->arr[dst].head = nptr;
	}

	void print_graph(graph* grph)
	{
		for (int i = 0; i < grph->v; i++)
		{
			adj_list_node* root = grph->arr[i].head;
			std::cout << "list: " << i << std::endl;
			while (root != NULL)
			{
				std::cout << root->data << "->";
				root = root->next;
			}
			std::cout << std::endl;
		}
	}
};
