#include<stdio.h>
#include<conio.h>
struct stack
{
	int x[5];
	int top;
	
};
struct stack s;

void push(struct stack *s,int a)
{
	if(s->top==4)
	printf("Full");
	else
	{
		s->top++;
		s->x[s->top]=a;
	}
}
int pop(struct stack *s)
{
	if(s->top==-1)
	printf("Empty");
	else
	{
		int t=s->x[s->top];
		s->top--;
		return t;
	}
}
void display()
{
	int i;
	for(i=s.top;i>=0;i--)
	{
		printf("%d\n",s.x[i]);
	}
}
main()
{
	int c,ch,j;
	s.top=-1;
	do
	{
		printf("Enter choice - 1- push\n 2- pop\n 3-display\n");
		scanf("%d",&c);
		if(c==1)
		{
			printf("Enter number:");
			scanf("%d",&j);
			push(&s,j);
			
		}
		else if(c==2)
		{
			printf("%d is popped",pop(&s));
			
		}
		else if(c==3)
	display();
	else printf("Wrong");
	printf("Press 1 to continue\n");
	scanf("%d",&ch);
	}
	while(ch==1);
	getch();
	return 0;
}
