#include"ll.h"

ll *loop = NULL;
ll *loop1 = NULL;

/*
@func sadd is used to strore the address of the node to create link
*/
void LL::addAtEnd(int data, bool sadd)
{
	ll *temp;
	temp =(ll *) malloc(sizeof(ll));
	temp->data = data;

	if(hd == NULL)
	{
		temp->link = NULL;
		hd = temp;
	}
	else
	{
		ll *tm;
		tm = hd;
		while(tm->link != NULL)
		{
			tm = tm->link;
		}
		temp->link = NULL;
		tm->link = temp;
	}
	if(sadd)
	{
		loop = temp;
		printf ("[addAtEnd] Loop data = %d\n",loop->data);
	}
}

void LL::addAtBegin(int data,bool sadd)
{
	ll *temp;
	temp =(ll *) malloc(sizeof(ll));
	temp->data = data;
	if(hd == NULL)
	{
		temp->link = NULL;
		hd = temp;
	}
	else
	{
		temp->link = hd;
		hd= temp;
	}

	if(sadd)
	{
		loop1= hd;
		printf ("[addAtBegin] Loop1 data = %d\n",loop1->data);
	}
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

int LL::length()
{
	int count = 0;
	ll *temp = hd;
	while(temp != NULL)
	{
		count++;
		temp = temp->link;
	}
	return count;
}

void LL::del(int loc)
{
	if(loc > length())
	{
		printf("[LL::del] Inavlid location Specified %d, list length is %d\n",loc,length());
	}
	else if( loc == 1)
	{
		ll *temp;
		temp = hd;
		hd = temp->link;
		free(temp);
	}
	else
	{
		ll *temp = hd;
		int i = 1;
		while(i < loc - 1)  //Stop before node you want to delete
		{
			temp = temp->link;
			i++;
		}
		ll * tm = temp->link;
		temp->link = tm->link;
		tm->link = NULL;
		free(tm);
	}
}

void LL::addAtAfter(int loc,int data)
{

	if(length() < loc)
	{
		printf("[LL::AddAtAfter] Invaliid location specified %d, list length is %d\n",loc,length());
	}
	else
	{
		ll *temp = hd;
		int i = 1;
		while(i < loc)  
		{
			temp = temp->link;
			i++;
		}
		ll *tm = (ll*)malloc(sizeof(ll));
		tm->data = data;
		tm->link = temp->link;
		temp->link = tm;

	}
}

void LL::reverse()
{
	ll *prev = NULL;
	ll *current = hd;
	ll *next;
	while(current->link != NULL)
	{
		next = current->link;
		current->link = prev;
		prev = current;
		current = next;
	}
	hd = prev;
}

bool LL::hasloop()
{
	ll *slow = hd;
	ll *fast = hd;
	while(fast->link != NULL)
	{
		if (slow->link)
		{
			slow = slow->link;
		}
		if(fast->link)
		{
			fast = fast->link;
		}
		if(fast->link)
		{
			fast = fast->link;
		}
		if(slow == fast)
		{
			slow = hd;
			while(slow != fast)
			{
				if (slow->link)
				{
					slow = slow->link;
				}
				if(fast->link)
				{
					fast = fast->link;
				}
				if(slow == fast)
				{
					printf ("Loop node data = %d\n",slow->data);
				}
			}
			return true;
		}
	}
	return false;
}

void LL::rec(ll *temp)
{

	if (temp == NULL)
	{
		return;
	}

	if(temp->link == NULL)
	{
		hd = temp;
		return;
	}
	rec(temp->link);
	temp->link->link = temp;
	temp->link = NULL;
}

void LL::recuricveRev() {
	ll *temp = hd;
	rec(temp);
}

int main()
{
	LL *ob = new LL();
	ob->addAtBegin(15,true);
    ob->addAtBegin(10);
    ob->addAtBegin(11);
    ob->addAtBegin(22);
	ob->addAtEnd(50);
	ob->addAtEnd(100,true);
//	ob->addAtAfter(2,400);
	
//	ob->addAtBegin(129);
//	ob->print();
//	ob->print();
//	ob->reverse();
	ob->print();
	ob->recuricveRev();
	ob->print();
	printf("Given linked list hasloop = %d\n",ob->hasloop());
	loop->link = loop1;
	printf("Given linked list hasloop = %d\n",ob->hasloop());

}
