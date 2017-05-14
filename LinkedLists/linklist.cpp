#include<stdio.h>
#include<stdlib.h>
#define max 10
struct node
{ int a;
 struct node *next;
} ;
main()
{ 
  struct node *head= NULL; 
  int n,i;
  printf("enter n,number of nodes");
  scanf("%d",&n);
  printf("enter elemens of each node");
  for(i=0;i<n;i++)
   { 
       struct node *list=(struct node*)malloc(sizeof(struct node));
       scanf("%d",& list->a);
       list->next=head;
       head=list;
   }
struct node *p;
p=head;
printf("displaying...");
i=0;
while(p!=NULL)
{
  printf("\n%d",p->a);
  p=p->next;
  i++;
}
printf("\n there are %d nodes",i);

}
