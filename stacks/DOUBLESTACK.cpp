#include<stdio.h>
#include<conio.h>
#define MAX 5
struct stack 
{
	int top1,top2;
	int n[MAX];
};
void push1(struct stack *p)
{
 	int k;
 	printf("enter a value to push");
 	scanf("%d",&k);
 	if((p->top1)==(p->top2)-1)
 	printf("stack full\n");
 	else (p->n[++(p->top1)]=k);
 	
 }
 void push2(struct stack *p)
 {
 	int k;
 	printf("enter a value to push");
 	scanf("%d",&k);
 	if((p->top1)==(p->top2)-1)
 	printf("stack full\n");
 	else (p->n[--(p->top2)]=k);
 	
 }
void pop1(struct stack *p)
{
 		if((p->top1)==-1)
 	printf("stack empty\n");
 	else printf("%d",p->n[p->top1--]);
 	
 }
 void pop2(struct stack *p)
 {
 		if((p->top2)==MAX)
 	printf("stack empty\n");
 	else printf("%d",p->n[p->top2++]);
 	
 }
 main(){
 	struct stack s;
 	s.top1=-1;
 	s.top2=MAX;
 	int t;
 	char ch;
 	do{
 		printf("1.push1\n2.pop1\n3.push2\n4.pop2");
 		scanf("%d",&t);
 		switch(t){
 			case 1 : push1(&s);
 			break;
 			case 2 : pop1(&s);
 			break;
 			case 3 : push2(&s);
 			break;
 			case 4 : pop2(&s);
 			break;
 		} printf("to continue press 'y'\n");
 		scanf("%s",&ch);
 	}while(ch=='y'||ch=='Y');
    
 
 
 	getch();
 	
 }
