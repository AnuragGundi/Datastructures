#include<stdio.h>
#include<conio.h>
#define MAX 5
struct stack 
{
	int top;
	int n[MAX];
};
void push(struct stack *p){
 	int k;
 	printf("enter a value to push");
 	scanf("%d",&k);
 	if((p->top)==MAX)
 	printf("stack full\n");
 	else (p->n[++(p->top)]=k);
 	
 }
void pop(struct stack *p){
 		if((p->top)==-1)
 	printf("stack empty\n");
 	else printf("%d",p->n[p->top--]);
 	
 }
 void top(struct stack *p){
 	if((p->top)==-1)
 	printf("stack empty\n");
 	else printf("%d",p->n[p->top]);
 }
 main(){
 	struct stack s;
 	s.top=-1;
 	int t;
 	char ch;
 	do{
 		printf("1.push\n2.pop\n3.top\n");
 		scanf("%d",&t);
 		switch(t){
 			case 1 : push(&s);
 			break;
 			case 2 : pop(&s);
 			break;
 			case 3 : top(&s);
 			break;
 		} printf("to continue press 'y'\n");
 		scanf("%s",&ch);
 	}while(ch=='y'||ch=='Y');
    
 
 
 	getch();
 	
 }
