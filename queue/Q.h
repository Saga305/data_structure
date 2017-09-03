#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

typedef struct ADTQ {
	int front, rear;
	int capacity;
	int *arr;
}adt;

class Q
{
private:
	adt *q;
public:
	Q();
	int front();
	int rear();
	bool createQ(int);
	bool isQempty();
	bool isFullQ();
	int Qcapacity();
	void doubleQ();
	void halfQ();
	void enQ(int);
	int deQ();
	int Qsize();
	void deleteQ();
};
