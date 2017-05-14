#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int dist[20],visited[20];
struct AdjListNode
{
int dest;
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
for(i=0;i<v;i++)
graph->array[i].head=NULL;
return graph;
}
void addEdge(struct Graph *graph,int src,int dest)
{
struct AdjListNode *newNode=(struct AdjListNode *)malloc(sizeof(struct AdjListNode));
newNode->dest=dest;
newNode->next=graph->array[src].head;
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
void complete(struct Graph *graph,int v)
{
int i,j,f=0;
  for(i=1;i<=v;i++)
  {
  for(j=1;j<=v;j++)
  {
  if(i!=j)
  if(!checkEdge(graph,i,j))
  {
  f++;
  break;
  }
  }
  }
  if(!f)
  printf("complete");
  else
  printf("incomplete");
}
void degree(struct Graph *graph,int v,int u)
{
int i,f=0,g=0;
for(i=1;i<=v;i++)
{
if(checkEdge(graph,u,i))
f++;
if(checkEdge(graph,u,i))
g++;
}
 printf("\nUndirected: Degree = %d",(f+g));
 printf("\nDirected: In-degree = %d, Outdegree = %d",g,f);
}

struct queue
{
int front,rear;
int a[20];
}q;
void insert(int y)
{
if((q.rear==19&&q.front==0)||(q.rear==q.front-1))
printf("full");
else
{
 if(q.rear==-1)
 q.front=0;
 q.rear=(q.rear+1)%20;
 q.a[q.rear]=y;
}
}
int remove1()
{
if(q.front==-1)
printf("empty");
else
{
int y=q.a[q.front];
if(q.front==q.rear)
q.front=q.rear=-1;
else
q.front=(q.front+1)%20;
return y;
}

}
int l;
int bfs(struct Graph *graph,int v,int a,int b)
{

int i,j=0;
for(l=1;l<=v;l++){
dist[l]=0;visited[l]=0;
}

insert(a);
   do
   {
   int u=remove1();
   if(u)
   printf("%d ",u);
   for(i=1;i<=v;i++)
   {
		   if(checkEdge(graph,u,i)&&visited[i]==0)
	   {
	       if(i==b)
		 {
		      j=1;
		      break;
		 }
      insert(i);
      visited[i]=1;
      dist[i]=dist[u]+1;
	   }
    }
   visited[u]=2;

   }
   while(q.front!=-1);
   return j;
}
int visited1[20];
void dfs(struct Graph *graph,int v,int i)
{
printf("%d ",i);
visited1[i]=1;
	 int j1;
for( j1=1;j1<=v;j1++)
{if(checkEdge(graph,i,j1)&&visited1[j1]==0)
dfs(graph,v,j1);
else if(checkEdge(graph,i,j1)&&visited1[j1]==1)
printf("Cycle");
}
}
main()
{
//clrscr();
int v,e,i;
printf("how many vert ? ");
scanf("%d",&v);
struct Graph *graph=createGraph(v);
printf("how many edges? ");
scanf("%d",&e);
printf("Enter edges ");
int a,b;
for(i=0;i<e;i++)
{
scanf("%d%d",&a,&b);
addEdge(graph,a,b);
//addEdge(graph,b,a);
}
complete(graph,v);
bfs(graph,v,1,v+1);
printf("enter node ");
scanf("%d",&a);
degree(graph,v,a);
dfs(graph,v,1);
getch();
return 0;
}
