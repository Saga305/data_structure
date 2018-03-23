#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

typedef struct TREE {
	struct TREE *left;
	int data;
	struct TREE *right;
}tree;

class T
{
private:
	tree *root;
public:
	T();
	void insert(int);
	void display(tree *);
	tree* createNode();
	int depth(tree *);
	tree* rot()
	{
		return root;
	}
};
