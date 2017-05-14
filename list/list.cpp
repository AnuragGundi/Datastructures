#include<stdio.h>
#include<malloc.h>
struct node
{
	int info;
	struct node *next;
}s;
typedef struct node *nodeptr;

nodeptr head=NULL;  
nodeptr last;

nodeptr getnode()
{
nodeptr q=(nodeptr)malloc(sizeof(s));
return q;

}

void freenode(nodeptr q)
{
	free(q);
}



void insert()
{
	int x,ins;
	printf("enter the element to insert\n" );
	scanf("%d",&x);
	printf("where do you want to insert:\n1.head\n2.tail\n");
	scanf("%d",&ins);
	nodeptr q=getnode();
	q->info=x;
	
	if(head==NULL)
	{
		head=q;
		head->next=NULL;
		return;
	}
if(ins==1)
{
	
	q->next=head;
	head=q;	
}
if(ins==2)
{
	last=head;
	while(last->next!=NULL)
		last=last->next;
	last->next=q;
	q->next=NULL;
	}
}
void display()
{
if(head==NULL)
{
printf("list is empty\n");
return;
}
printf("\nlist is:\n");
	last=head;
	while(last!=NULL)
	{
		printf("%d  ",last->info);
		last=last->next;
	}
}

int main()
{
 int choice;
    while (1)
    {
        printf("\n1.Insert element to list \n");
        printf("2.Display all elements of list \n");
        printf("3.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            insert();
            break;
            case 2:
            display();
            break;
            case 3:return 0;
			default:
            printf("Wrong choice \n");
        } 
    } 
return 0;	
}
