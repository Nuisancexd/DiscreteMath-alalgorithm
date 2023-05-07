struct tree
{
	int data;
	tree* left;
	tree* right;
};


void insert_(int x, tree* root)
{
	if (x < root->data)
	{
		if (root->left)
		{
			insert_(x, root->left);
		}
		else
		{
			root->left = new tree;
			root->left->data = x;
			root->left->left = NULL;
			root->left->right = NULL;
		}
	}
	else if (x >= root->data)
	{
		if (root->right)
		{
			insert_(x, root->right);
		}
		else
		{
			root->right = new tree;
			root->right->data = x;
			root->right->right = NULL;
			root->right->left = NULL;
		}
	}
}

void insert(int x, tree* root)
{
	if (root)
	{
		insert_(x, root);
	}
	else
	{
		root = new tree;
		root->data = x;
		root->left = NULL;
		root->right = NULL;
	}
}


void traverse_tree(tree* t)
{
	if (t)
	{
		traverse_tree(t->left);
		if (t->data)
			std::cout << t->data << " ~ ";
		traverse_tree(t->right); 
	}
}
