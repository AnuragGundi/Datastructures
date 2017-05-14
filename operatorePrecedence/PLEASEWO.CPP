#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>
struct stack
{
int a[100];
int top;
}s,temp;
char u;
char *rev(char s[])
{
int i,j;
for(i=0,j=strlen(s)-1;i<j;i++,j--)
{
char t=s[i];
s[i]=s[j];
s[j]=t;
}
s[strlen(s)]='\0';
return s;
}

int pop(stack *s)
{
if(s->top!=-1)
{
return s->a[s->top--];
}
}
int operate(int a,int b,char c)
{
if(c=='+')
return a+b;
else if(c=='-')
return a-b;
else if(c=='*')
return a*b;
else if(c=='/')
return a/b;
else if(c=='$')
return pow(a,b);
}
int evaluate(char a[])
{
int i=0;
while(a[i]!='\0')

{

  int h=i,f=0,l=0;
if(a[i]>='0'&&a[i]<='9')
{
while(f==0&&a[h]!='\0')
{
if(a[h]>='0'&&a[h]<='9')
temp.a[++temp.top]=a[h]-48;
else
f++;
h++;
}
int sum=0,p=temp.top;
while(temp.top!=-1){
int u=pop(&temp);
sum+=u*pow(10,p--);
}
s.a[++s.top]=sum;

i=h;
}
else if(a[i]==' ')
{
i++;
printf("\n");
}
else
{
int pop2=pop(&s);
int pop1=pop(&s);

int jj=operate(pop1,pop2,a[i]);
s.a[++s.top]=jj;

i++;

}}
return s.a[s.top];
}
int main()
{

  s.top=-1,temp.top=-1;
  char a[100];
  gets(a);
  printf("%d",evaluate((rev(a))));
  getch();
  return 0;
}
