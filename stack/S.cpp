#include"S.h"

Stack::Stack(int cap)
{
	_top = -1;
	_capacity = cap;
	_arr = (int*) malloc(sizeof(int) *cap);
}

int Stack::top()
{
	return _top;
}

void Stack::top(int val)
{
	_top = val;
}

int Stack::capacity()
{
	return _capacity;
}

void Stack::print() {
	if(!isStackEmpty())
	{
		int i = top();
		printf("Stored stack values:\n");
		printf("Index\tValue\n");
		for(;i >= 0; i--)
		{
			printf("id[%d]\t%d\n",i,unFill(i));
		}
	}
	else
	{
		printf("[Stack::print] Stack is empty\n");
	}
}

bool Stack::isStackEmpty() {
	if( top() == -1)
	{
		return true;
	}
	return false;
}

bool Stack::isStackFull()
{
	if(top() == capacity() -1)
	{
		return true;
	}
	return false;
}

void Stack::fill(int id, int val)
{
	_arr[id] = val;
}

int Stack::unFill(int id)
{
	return _arr[id];
}

void Stack::push(int val)
{
	if(isStackFull())
	{
		printf("[Stack::push] Can not push due to stack overflow\n");\
			return;
	}
	top(top() + 1);
	fill(top(),val);	
}

int Stack::pop()
{
	if(isStackEmpty())
	{
		printf("[Stack::pop] Can not pop due to stack underflow\n");
		return 0;
	}
	int val =  unFill(top());
	top(top() - 1);
	return val;
}


