#include<stdio.h>
#include<stdlib.h>

struct list
{
	int value;
	struct list *next;
}s;


typedef struct list *node;

node getnode()
{
	node p;
	p=(node)malloc(sizeof(s));
	return p;
}

int check(node s,node head)
{
	if(s==head)
	return 1;
	else return 0;
}
void delete(node s,node head)
{

	node p=getnode();
	p=head;
	
	while(p->next!=s)
	{
		p=p->next;
	}

	
	p->next=s->next;
	free(s);
	
}
int main()
{
	
	int i,x,n,count,flag=0,g=1,f=1;
	node head=getnode();

	
	printf("enter the value of students shortlisted.. enter -1 to stop:\n");
	scanf("%d",&x);

	if(x!=-1)
	   head->value=x;
	else
	   printf("no student shortlisted...enter again..");
	
	node p=getnode();
    p=head;
    

    
	while(1)
	{
	  
	 scanf(" %d",&x);
     if(x!=-1)
	   {
	   	 node q=getnode();
	     
	     
	     q->value=x;
	     q->next=NULL;
	     
	     p->next=q;
	     p=q;
	     g++;
	   }
	   else
	   break;
      }
	  p->next=head;
	 
	 printf("\nenter the number of persons to be skipped : ");
	 scanf("%d",&n);
	 
	 
	 count=1;
	 node s=getnode();
	 node t=getnode();
	 s=head;
	 while(f++!=g)
	 {
	   	while(count!=n)
	 	{
	 		count++;
	 		s=s->next;
	 	}
	 	t=s->next;
	 	if(check(s,head) ) flag=1;
	 	delete(s,head);
	 	if(flag==1)head =t;
	 	s=t;
	 	count=1;
	}
	 
	 printf("\nthe class representative is %d",head->value);
     return 0;
}
