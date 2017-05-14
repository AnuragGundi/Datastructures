#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int dist[20],visited[20];
int ne=1,parent[100];
int a,u,b,v;
int min,mincost;
int find(int i)
{
while(parent[i])
i=parent[i];
return i;
}
int uni(int i,int j)
{
if(i!=j)
{
parent[j]=i;
return 1;
}
return 0;
}
struct AdjListNode
{
int dest;
int weight;
struct AdjListNode *next;
};
struct AdjList
{
struct AdjListNode *head;
};
struct Graph
{
int v;
struct AdjList *array;
};
struct Graph *createGraph(int v)
{
struct Graph *graph=(struct Graph *)malloc(v*sizeof(struct AdjList));
int i;
graph->v=v;
for(i=1;i<=v;i++)
graph->array[i].head=NULL;
return graph;
}
void addEdge(struct Graph *graph,int src,int dest,int wt)
{
struct AdjListNode *newNode=(struct AdjListNode *)malloc(sizeof(struct AdjListNode));
newNode->dest=dest;
newNode->next=graph->array[src].head;
newNode->weight=wt;
graph->array[src].head=newNode;

}
int checkEdge(struct Graph *graph,int src,int dest)
{
struct AdjListNode *p=graph->array[src].head;
int j=0;
while(p!=NULL)
{
if(p->dest==dest)
{       j=1;
break;
}
p=p->next;
}
return j;
}

void kruskal(struct Graph *graph)
{   int i;
struct AdjListNode *w=(struct AdjListNode *)malloc(sizeof(struct AdjListNode));
int n=graph->v;
 printf("%d",n);
while(ne<n)
 {
 int min=999;
  // printf("%d",n);
for(i=1;i<=n;i++)
   {

   struct AdjListNode *p=graph->array[i].head;

    while(p!=NULL)
    {
      if(p->weight<min)
      {
      w=p;
      min=p->weight;
      a=u=i;
      b=v=p->dest;
      }
      p=p->next;
    }
   }

 u=find(u);
 v=find(v);
 if(uni(u,v))
 {
 printf("\n%d edge (%d,%d) = %d\n",ne++,a,b,min);
 mincost+=min;
 }
 w->weight=999;
 }
 printf("\nMinimum cost = %d\n",mincost);
}
main()
{
//clrscr();
int V,e;
  printf("how many vert ? ");
scanf("%d",&V);
struct Graph *graph=createGraph(V);
printf("how many edges? ");
scanf("%d",&e);
printf("Enter edges ");
int a,b;
int i,wt;
for(i=0;i<e;i++)
{
scanf("%d%d%d",&a,&b,&wt);
addEdge(graph,a,b,wt);
//addEdge(graph,b,a,wt);
}

kruskal(graph);
getch();
return 0;
}
