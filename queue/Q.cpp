#include"Q.h"
Q::Q() {
	q = (adt*)malloc(sizeof(adt));
	if(q)
	{
		q->front = q->rear = -1;
		q->capacity = 0;
		q->arr = NULL;
	}
}

int Q::front() 
{
	return q->front;
}

int Q::rear()
{
	return q->rear;
}

bool Q::createQ(int capacity)
{
	if (q)
	{
		q->capacity = capacity;
		q->arr = (int*) malloc(sizeof(int) * q->capacity);
		if (q->arr)
		{
			return true;
		}
	}
	return false;
}

bool Q::isQempty()
{
	if(q && q->front == -1)
	{
		return true;
	}
	return false;
}

bool Q::isFullQ()
{
	if( (q->front == 0 && q->rear == q->capacity - 1) || (q->front  == q->rear + 1))
	{
		return true;
	}
	return false;
}

int Q::Qcapacity()
{
	return q->capacity;
}

void Q::doubleQ()
{
		q->capacity *= 2;
		int i,j = 0;
		int *temp = (int*) malloc(q->capacity * sizeof(int));
		for(i=q->front; i != q->rear; j++)
		{
			temp[j] = q->arr[i];
			if( i == (q->capacity/2) - 1 && q->front != 0)
			{
				i = 0;
			}
			else
			{
				i++;
			} 
		}
		temp[j] = q->arr[q->rear];
		free(q->arr);
		q->arr = temp;
		q->rear = (q->capacity/2)/1 -1;
		q->front = 0;
}

void Q::halfQ()
{
		int i = 0, j;
		int* temp = (int*) malloc((q->capacity/2)* sizeof(int));
		for(j = q->front; i < (q->capacity/2) ; i++)
		{
			temp[i] = q->arr[j];
			if(j == q->capacity-1)
			{
				j = 0;
			}
			else
			{
				j++;
			}
		}
		free(q->arr);
		q->arr = temp;
		q->capacity /= 2;
//NOTE: 
		if(q->capacity == 1)
		{
			q->front = q->rear = -1;
		}
		else
		{
			q->rear = q->capacity-1;
			q->front = 0;
		}
}

void Q::enQ(int val)
{
	if(Qcapacity() < 1)
	{
		printf("Invalid capacity\n");
	}
	else if(isQempty())
	{
		q->front = 0;
		q->rear = 0;
		q->arr[q->rear] = val;
	}
	else if(isFullQ())
	{
		doubleQ();
		q->rear += 1;
		q->arr[q->rear] = val;
	}
	else
	{
		if(q->rear == Qcapacity() -1)
		{
			q->rear = 0;
		}
		else
		{
			q->rear += 1;
		}
		q->arr[q->rear] = val;
	}
}

int Q::deQ()
{
	int val;
	if(isQempty())
	{
		printf("Underflow\n");
	}
	else if(front() == rear())
	{
		val = q->arr[front()];
		q->front = q->rear = -1;
	}
	else if( front() == Qcapacity() - 1 )
	{	
		val = q->arr[front()];
		q->front = 0;
	}
	else
	{
		val = q->arr[front()];
		q->front += 1;
	}
	if(front() >-1)
	{
		if(Qsize() <= Qcapacity()/2)
		{
			halfQ();
		}
	}
	return val;
}

int Q::Qsize()
{
	int i, size = 0;
	for (i = front(); i != rear() ;)
	{
		size++;
		if(i == Qcapacity() - 1)
		{
			i = 0;
		}
		else
		{
			i++;
		}
	}
	size++;
	return size;
}

void Q::deleteQ()
{
	free(q->arr);
	free(q);
	q = NULL;
}


