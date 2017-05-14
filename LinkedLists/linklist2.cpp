#include<stdio.h>
#include<stdlib.h>
#define max 10
struct node
{ int data;
 struct node *next;
};

main()
{ 

 struct node *head=(struct node*)malloc(sizeof(struct node));
 struct node *q=(struct node*)malloc(sizeof(struct node)); 
 int n,i;
 printf("enter n,number of nodes");
 scanf("%d",&n);
 head=NULL;

  printf("enter elemens of each node");
  scanf("%d",& q->data);
  head=q;
  q->next=NULL;
  for(i=1;i<n;i++)
{ 
  struct node *list=(struct node*)malloc(sizeof(struct node));
  scanf("%d",&list->data);
  list->next=NULL;
  q->next=list;
  q=q->next;
}
  struct node *p=(struct node*)malloc(sizeof(struct node));
  p=head;
  printf("displaying...");
  i=0;
while(p!=NULL)
{
   printf("\n%d",p->data);
   p=p->next;
   i++;
}
printf("\n there are %d nodes",i);

}
