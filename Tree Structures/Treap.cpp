#include <iostream>

#include "tree.h"


// max(root1) < min(root2)
tree* merge(tree* root1, tree* root2)
{
	if (!root2)
		return root1;
	if (!root1)
		return root2;

	if (root1->data > root2->data)
	{
		root1->right = merge(root1->right, root2);
		return root1;
	}
	else
	{
		root2->left = merge(root1, root2->left);
		return root2;
	}
}

void split(tree* root3, int k, tree* &root1, tree* &root2)
{
	if (!root3)
	{
		root1 = root2 = NULL;
		return;
	}
	if (k > root3->data)
	{
		split(root3->right, k, root3->right, root2);
		root1 = root3;
	}
	else
	{
		split(root3->left, k, root1, root3->left);
		root2 = root3;
	}
}

int main()
{
	tree* root1 = new tree();
	insert(8, root1);
	insert(3, root1);
	insert(14, root1);
	insert(1, root1);
	insert(20, root1);
	insert(4, root1);
	insert(16, root1);
		
	std::cout << "First tree: ";
	traverse_tree(root1);
	std::cout << std::endl;
	tree* root2 = new tree();
	insert(23, root2);
	insert(25, root2);
	insert(24, root2);
	insert(26, root2);

	std::cout << "Second tree: ";
	traverse_tree(root2);

	tree* root3 = new tree();
	root3 = merge(root1, root2);
	std::cout << "\nMerge first & second tree: ";
	traverse_tree(root3);

	tree* root1_ = new tree();
	tree* root2_ = new tree();
	tree* root3_ = new tree();
	insert(8, root3_);
	insert(3, root3_);
	insert(14, root3_);
	insert(1, root3_);
	insert(20, root3_);
	insert(4, root3_);
	insert(16, root3_);
	insert(23, root3_);
	insert(25, root3_);
	insert(24, root3_);
	insert(26, root3_);
	std::cout << "\nSplit merge tree\n";
	split(root3_, 8, root1_, root2_);
	traverse_tree(root1_);
	std::cout << std::endl;
	traverse_tree(root2_);
	std::cout << std::endl;
}
