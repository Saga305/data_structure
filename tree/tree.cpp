#include"tree.h"
T::T() {
	root = NULL;
}

tree * T::createNode(int d= 0)
{
	
	tree *t = (tree*)malloc(sizeof(tree));
	if(t)
	{
		t->data = d;
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

tree * T::minNode(tree *t)
{
	tree * curr = t;
	while( curr->left != NULL)
	{
		curr = curr->left;
	}
	return curr;
}

tree * T::del(tree *root,int data)
{
	if (root == NULL) return root;

	// If the data to be deleted is smaller than the root's data,
	// then it lies in left subtree
	if (data < root->data)
		root->left = del(root->left, data);

	// If the data to be deleted is greater than the root's data,
	// then it lies in right subtree
	else if (data > root->data)
		root->right = del(root->right, data);

	// if data is same as root's data, then This is the tree
	// to be deleted
	else
	{
		// tree with only one child or no child
		if (root->left == NULL)
		{
			tree *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			tree *temp = root->left;
			free(root);
			return temp;
		}

		// tree with two children: Get the inorder successor (smallest
		// in the right subtree)
		tree* temp = minNode(root->right);

		// Copy the inorder successor's content to this tree
		root->data = temp->data;

		// Delete the inorder successor
		root->right = del(root->right, temp->data);
	}
	return root;
}

int T::diameter(tree *root)
{
	tree * t= root;
	if(t == NULL)
	{
		return 0;
	}
	int lh = depth(t->left);
	int rh = depth(t->right);

	int ld = diameter(t->left);
	int rd = diameter(t->right);

	return max(lh+rh+1,max(ld,rd));
}

void T::mirror(tree * t)
{
	if(t == NULL)
	{
		return;
	}
	else
	{
		tree * temp;

		mirror(t->left);
		mirror(t->right);

		temp = t->left;
		t->left = t->right;
		t->right = temp;
	}
}
bool T::isMirror(tree* t1, tree* t2)
{
	if( t1 == NULL && t2 == NULL)
	{
		return true;
	}

	if( t1 == NULL || t2 == NULL)
	{
		return false;
	}

	return (t1->data == t2->data && isMirror(t1->left,t2->right) && isMirror(t1->right,t2->left));
}

bool T::isSym(tree *t)
{
	return T::isMirror(t,t);
}

int main()
{
T t;
t.insert(50);
t.insert(30);
t.insert(70);
t.insert(60);
t.insert(80);
t.insert(20);
t.insert(40);
t.display(t.rot());
std::cout<<" \n Depth = "<<t.depth(t.rot())<<std::endl;
std::cout<<" \n Min = "<<t.min(t.rot())<<std::endl;
std::cout<<" \n Max = "<<t.max(t.rot())<<std::endl;
t.rooot(t.del(t.rot(),50));
t.display(t.rot());
std::cout<<std::endl;
t.mirror(t.rot());
t.display(t.rot());
std::cout<<" \n Diameter = "<<t.diameter(t.rot())<<std::endl;

T t1;
t1.insert(60);
t1.insert(30);
t1.insert(70);
t1.insert(80);
t1.insert(20);
t1.insert(40);
std::cout<<" Is mirror = "<<T::isMirror(t.rot(),t1.rot())<<std::endl;

//Symmetric Tree
T t2;
t2.rooot(t2.createNode(1));
t2.rot()->left= t2.createNode(2);
t2.rot()->right= t2.createNode(2);
t2.rot()->left->left= t2.createNode(3);
t2.rot()->right->right= t2.createNode(3);
t2.rot()->left->right= t2.createNode(4);
t2.rot()->right->left= t2.createNode(4);
t2.display(t2.rot());
std::cout<<"\n Is Symmetric = "<<T::isSym(t2.rot())<<std::endl;

return 0;
}
