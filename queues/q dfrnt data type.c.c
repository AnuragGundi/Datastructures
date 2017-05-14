
//diffrent data types in queue

#include<stdio.h>
#define MAX 50


union element
{
	int ival;
	float fval;
	char pval[20];
};

struct stack
{
	int front,rear, etype[MAX];
	union element items[MAX];
}s;

void insert()

{


        if (s.front == - 1)
        s.front = 0;
        s.rear++;
        printf("enter ur chioce:\n");
		printf("1.Integer\n2.Real\n3.String\n");
		scanf("%d", &s.etype[s.rear]);
		switch(s.etype[s.rear])
		{
			case 1 :printf("enter integer:\n");
			         scanf("%d", &s.items[s.rear].ival);
				   	   break;
			case 2 : printf("enter float:\n");
			          scanf("%f", &s.items[s.rear].fval);
					 	 break;
			case 3 :printf("enter string:\n");
			         scanf("%s", &s.items[s.rear].pval);
					  	  break;
			default : printf("Invalid data type.\n");
		}
		
	return;
	
}

void del()
{
	 if (s.front == - 1 || s.front > s.rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {switch(s.etype[s.front])
		{
			case 1 : printf("Element deleted from queue is : %d\n", s.items[s.front].ival);
					   s.front++;
					    break;
			case 2 : printf("Element deleted from queue is : %.2f\n", s.items[s.front].fval);
					 s.front++;
					 	 break;
			case 3 : printf("Element deleted from queue is : %s\n", s.items[s.front].pval);
						 s.front++;
						   break;
			default:  printf("\n");
		}
       

    }
} 


void print()
{
	int i;
	if (s.front == - 1)
        printf("Queue is empty \n");
        else{
        
	for(i=s.front; i<=s.rear; i++)
	{
		switch(s.etype[i])
		{
			case 1 : printf("%d\t", s.items[i].ival);
					   break;
			case 2 : printf("%.2f\t", s.items[i].fval);
						 break;
			case 3 : printf("%s\t", s.items[i].pval);
						  break;
			default:  printf("\n");
		}
	}
	printf("\n");
	return;
      }
}
int main()
{
	s.front=s.rear=-1;
	int choice;
	while(1)
	{
		printf("\n");
		printf("enter ur choice:\n");
		printf("1.insert\n2.del\n3.Print\n4.Exit\n");
		scanf("%d", &choice);
	  switch(choice)
	  {
	
		case 1: insert();
		        break;
		case 2:del();
		        break;
		case 3:print();
		       break;
		case 4:return 0;
		default:("wrong choice");
	 }
   }
	return 0;
}
