#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

class Stack
{
private:
int _top;
int _capacity;
int *_arr;
public:
Stack() {}
Stack(int);
int top();
void top(int);
int capacity();
bool isStackEmpty();
bool isStackFull();
void fill(int,int);
int unFill(int);
void print();
void push(int);
int pop();







};
