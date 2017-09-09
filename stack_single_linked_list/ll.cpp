#include"ll.h"

void LL::push(int data)
{
	ll *temp;
	temp =(ll *) malloc(sizeof(ll));
	temp->data = data;

	temp->link = hd;
	hd = temp;
}


void LL::print()
{
	ll *temp = hd;
	if( temp == NULL)
	{
		printf("[LL::print] List is empty\n");
	}
	while(temp != NULL)
	{
		printf ("%d-->",temp->data);
		temp = temp->link;
	}
	printf("\n");
}

int LL::pop()
{
	int val;
	ll *temp = hd;
	if( temp == NULL)
	{
		printf("[LL::pop] List is empty\n");
		return 0;
	}
	else
	{
		val = hd->data;
		hd = hd->link;
		temp->link = NULL;
		free(temp);
		return val;
	}
}


int main()
{
	LL *ob = new LL();
	ob->push(20);
	ob->push(30);
	ob->push(40);
	ob->push(50);
	ob->print();
	printf("poped value = %d\n",ob->pop());
	ob->print();

}
