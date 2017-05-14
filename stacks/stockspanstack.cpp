#include<stdio.h>
#include<conio.h>
#define MAX 10
struct stack {
	int top;
	int n[MAX];
};
void push(struct stack *p,int k){
 	
 	if((p->top)==MAX)
 	printf("stack full\n");
 	else (p->n[++(p->top)]=k);
 	
 }
void pop(struct stack *p){
 		if((p->top)==-1)
 	printf("stack empty\n");
 	else p->top--;
 	
 }
 main()
 {
 	struct stack s;
 	s.top=-1;
 	int n, price[100],span[100];
 	printf("enter no of days\n");
 	scanf("%d",&n);
 	printf("enter prices\n");	
 	for(int i=0;i<n;i++)
 	scanf("%d",&price[i]);
 	push(&s,0);
 	span[0]=1;
 	for(int i=1;i<n;i++)
	 {
 	while(s.top!=-1&&price[i]>price[s.n[s.top]])
 	{
 		 pop(&s);
 	     
 	}
 	span[i]=i-s.n[s.top];
	 push(&s,i);

 	
      }
 	for(int i=0;i<n;i++)
 
 	printf("%d  ",span[i]);
 	getch();
 }
 
 	
 	
 	
 	
 
