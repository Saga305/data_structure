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

int main()
{
T t;
t.insert(20);
t.insert(10);
t.insert(15);
t.insert(25);
t.insert(30);
t.insert(35);
t.insert(40);
t.insert(45);
t.insert(50);
t.insert(55);
t.display(t.rot());
return 0;
}
