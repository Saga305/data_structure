#include<iostream>
#include<cstdlib>
#include<cstdio>

typedef struct linkedList
{
	int data;
	struct linkedList *link;
}ll;

using namespace std;

class LL
{
	private:
		ll *hd;

	public:
		LL()
		{
			hd = NULL;
		}
		void addAtEnd(int);
		void addAtBegin(int);
		void print();
		int length();
		void del(int);
		void addAtAfter(int,int);
};
