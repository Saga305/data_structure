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
	int min(tree *);
	void mirror(tree *);
	tree *  minNode(tree *);
	int max(tree *);
	int max (int a, int b)
	{
		return (a>b)?a:b;
	}
	tree * del(tree *,int );
	int diameter(tree *);
	tree* rot()
	{
		return root;
	}
	void rooot(tree * t)
	{
		root =  t;
	}
	static bool isMirror( tree*, tree *);
};
