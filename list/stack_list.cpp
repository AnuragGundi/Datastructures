#include<stdio.h>
#include<malloc.h>
struct node
{
	int info;
	struct node *next;
}s;
typedef struct node *nodeptr;

nodeptr head=NULL,last;

nodeptr getnode()
{
nodeptr p=(nodeptr)malloc(sizeof(s));
return p;

}

void freenode(nodeptr p)
{
	free(p);
}



void push()
{
	int x,ins;
	printf("enter the element to push\n" );
	scanf("%d",&x);
	nodeptr p=getnode();
	p->info=x;
	
	if(head==NULL)
	{
		head=p;
		head->next=NULL;
		return;
	}
		p->next=head;
	head=p;	
	
}

void pop()
{
if(head==NULL)
  {
	printf("stack is empty\n");
	return;
  }
  nodeptr p=getnode(); 
  p=head;
head=head->next;
printf("element popped is %d",p->info);
free(p);
}

void display()
{
if(head==NULL)
{
printf("stack is empty\n");
return;
}
printf("\nstack is:\n");
	last=head;
	while(last!=NULL)
	{
		printf("  %d  ",last->info);
		last=last->next;
	}
}

int main()
{
 int choice;
 	printf("implementation of stack using linked list\n\n");
    while (1)
    {
        printf("\n1.push \n");
        printf("2.pop \n");
        printf("3.Display \n");
        printf("4.Quit \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
            push();
            break;
            case 2:
            	pop();
            case 3:
            display();
            break;
            case 4:return 0;
			default:
            printf("Wrong choice \n");
        } 
    } 
return 0;	
  }
