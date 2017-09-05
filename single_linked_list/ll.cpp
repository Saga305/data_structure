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
		printf ("%d\t",temp->data);
		temp = temp->link;
	}
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
		i = 1;
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
int main()
{
	LL *ob = new LL();
	ob->addAtEnd(20);
	printf("lenght = %d\n",ob->length());
	ob->addAtBegin(30);
	ob->addAtEnd(50);
	ob->addAtEnd(100);
	printf("lenght = %d\n",ob->length());
	ob->print();
	ob->del(1);
	ob->print();

}