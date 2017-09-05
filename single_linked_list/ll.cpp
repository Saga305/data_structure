#include"ll.h"

void LL::addAtEnd(int data)
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
}

void LL::addAtBegin(int data)
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
}

void LL::print()
{
	ll *temp = hd;
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
int main()
{
	LL *ob = new LL();
	ob->addAtEnd(20);
	ob->addAtBegin(30);
	ob->addAtEnd(50);
	ob->addAtEnd(100);
	ob->print();
	ob->addAtAfter(2,400);
	ob->del(5);
	ob->print();

}