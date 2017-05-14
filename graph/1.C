#include<stdio.h>

int graph[20][20],p,dist[20],visited[20];
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
int bfs(int v,int a,int b)
{

int i,j=0;
for(l=1;l<=v;l++){dist[l]=0;visited[l]=0;}

insert(a);
   do
   {
   int u=remove1();
   printf("%d ",u);
   for(i=1;i<=v;i++)
   {
   if(graph[u][i]&&visited[i]==0)
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
int j1;
int visited1[20];
void dfs(int v,int i)
{
printf("%d ",i);
visited1[i]=1;

for( j1=1;j1<=v;j1++)
{if(graph[i][j1]==1&&visited1[j1]==0)
dfs(v,j1);
else if(graph[i][j1]==1&&visited1[j1]==1)
printf("Cycle");
}
}
void complete(int graph[][20],int v)
{
int i,j,f=0;
  for(i=1;i<=v;i++)
  {
  for(j=1;j<=v;j++)
  {
  if(i!=j)
  if(!graph[i][j])
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
void degree(int graph[][20],int v,int u)
{
int i,f=0,g=0;
for(i=1;i<=v;i++)
{
if(graph[u][i]==1)
f++;
if(graph[i][u]==1)
g++;
}
 printf("\nUndirected: Degree = %d",(f+g));
 printf("\nDirected: In-degree = %d, Outdegree = %d",g,f);
}

main()
{
int v,e,i,a,b,u;
q.front=-1;
q.rear=-1;
//getch();


printf("\nEnter number of vertices ");
scanf("%d",&v);
printf("\nEnter number of edges ");
scanf("%d",&e);
printf("\nEnter edges ");
for(i=0;i<e;i++)
{
  scanf("%d%d",&a,&b);
  graph[a][b]=1;
 // graph[b][a]=1;
 if(graph[b][a]==0)
 graph[b][a]=-1;
}
complete(graph,v);
printf("\nEnter node ");
scanf("%d",&u);
degree(graph,v,u);
printf("\nEnter 2 vertices ");
scanf("%d%d",&a,&b);
if(bfs(v,a,b))
printf("path exists ");
else
printf("No path exists ");
 p=bfs(v,1,v+1);
for(i=1;i<=v;i++)
printf("\nNode: %d, Distance: %d\n",i,dist[i]);
printf("\n");
dfs(v,1);
//getch();
return 0;
}
