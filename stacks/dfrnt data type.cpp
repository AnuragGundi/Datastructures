#include<stdio.h>
#include<conio.h>
#define SIZE 50
union element
{
	int i;
	float f;
	char p[20];
};
struct stack
{
	int top;
	int etype[SIZE];
	union element s[SIZE];
};
struct stack stk;




int stkempty()
{
	if(stk.top==-1)
	return 1;
	else
	return 0;
}


int stkfull()
{
	if(stk.top==SIZE-1)
	return 1;
	else
	return 0;
}


void push()
{
	if(stkfull())
	{
		printf("Stack full.");
		return;
	}
	int i;
	printf("1.Integer\t 2.Float\t 3.String\n");
	scanf(" %d",&i);
	stk.top++;
	if(i==1)
	{
		stk.etype[stk.top]=1;
		int k;
		printf("Enter no. :");
		scanf("%d",&k);
		stk.s[stk.top].i=k;
	}
	else if(i==2)
	{
		stk.etype[stk.top]=2;
		printf("Enter float:");
		float g;
		scanf("%f",&g);
		stk.s[stk.top].f=g;
	}
	else if(i==3)
	{
		stk.etype[stk.top]=3;
		printf("Enter string:");
		scanf("%s",stk.s[stk.top].p);
	}
	else
	printf("Invalid entry ");
}
void pop()
{
	if(stkempty())
	{
		printf("Stack empty");
		return;
	}
	if(stk.etype[stk.top]==1)
	
		printf("\n%d",stk.s[stk.top].i);
	
	else if(stk.etype[stk.top]==2)
	
		printf("\n%f",stk.s[stk.top].f);
	
	else if(stk.etype[stk.top]==3)
	
		printf("\n%s",stk.s[stk.top].p);
	
	stk.top--;
}
int main()
{
	int c;
	stk.top=-1;
	char ch;
	do
	{
		printf("1.push\t2.pop\n");
		scanf("%d",&c);
		if(c==1)
		{
			push();
		}
		else if(c==2)
		{
			pop();
		}
		else
		printf("Invalid entry\n");
		printf("\ndou continue y/n:");
		scanf(" %c",&ch);
	}while(ch=='y');
	getch();
	return 0;
}
