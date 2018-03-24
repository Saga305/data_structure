#include"tree.h"
T::T() {
	root = NULL;
}

tree * T::createNode()
{
	
	tree *t = (tree*)malloc(sizeof(tree));
	if(t)
	{
		t->data = 0;
		t->left = NULL;
		t->right = NULL;
	}
	return t;
}

void T::insert(int data)
{
	tree *t, *p;
	t = createNode();
	if(t)
	{
		t->data = data;
	}
	else
	{
		return;
	}

	p = root;

	if( root == NULL )
	{
		root = t;
	}
	else
	{
		tree *curr = root;
		while(curr)
		{
			p = curr;
			if(t->data > curr->data)
			{
				curr = curr->right;
			}
			else
			{
				curr = curr->left;
			}
		}
		if(t->data > p->data)
		{
			p->right = t;
		}
		else
		{
			p->left = t;
		}
	}
}

void T::display(tree *t)
{
	if(t->left)
	 display(t->left);
	 cout<<" "<<t->data;
	 if(t->right)
	 display(t->right);
}

int T::depth(tree *c)
{
	tree *t = c;
	if( t == NULL)
	{
		return 0;
	}
	else
	{
		int ld = depth(t->left);
		int rd = depth(t->right);
		if(ld > rd)
		{
			return ld + 1;
		}
		else
		{
			return rd + 1;
		}
	}
}

int T::min(tree *t)
{
	tree * curr = t;
	while( curr->left != NULL)
	{
		curr = curr->left;
	}
	return curr->data;
}

int T::max(tree *t)
{
	tree * curr = t;
	while( curr->right != NULL)
	{
		curr = curr->right;
	}
	return curr->data;
}

int main()
{
T t;
t.insert(10);
t.insert(9);
t.insert(15);
t.insert(1);
t.insert(3);
t.display(t.rot());
std::cout<<" \n Depth = "<<t.depth(t.rot())<<std::endl;
std::cout<<" \n Min = "<<t.min(t.rot())<<std::endl;
std::cout<<" \n Max = "<<t.max(t.rot())<<std::endl;
return 0;
}
