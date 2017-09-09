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
		void push(int);
		void print();
		int pop();
		
};
