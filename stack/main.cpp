#include"S.h"

int main()
{
	Stack s(3);
	int option = 1,choice;
	printf ("------------------------------------------\n");
	printf ("      1    -->    PUSH               \n");
	printf ("      2    -->    POP               \n");
	printf ("      3    -->    DISPLAY               \n");
	printf ("      4    -->    EXIT           \n");
	printf ("------------------------------------------\n");

	while (option)
	{
		printf ("Enter your choice\n");
		scanf    ("%d", &choice);

		switch (choice)
		{
			case 1:
				{
					printf("Enter the value you want to push\n");
					scanf("%d", &choice);
					s.push(choice);
				}
				break;
			case 2:
				{
					int val = 0;
					val = s.pop();
					if(val)
						printf ("poped val = %d\n",val);
				}
				break;
			case 3:
				s.print();
				break;
			case 4:
				option = 0;
		}
	}
	return 0;
}
