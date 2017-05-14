#include<stdio.h>
#include<conio.h>
struct stack
{
char a[100];
int top;
}temp;
char u;

int pop(stack *s)
{
if(s->top!=-1)
{
return s->a[s->top--];
}
}
int isbracket(char a)
{
if(a=='['||a==']'||a=='{'||a=='}'||a=='('||a==')')
return 1;
else return 0;
}
char q1[]="([{",q2[]=")]}";
int comp(char a,char b)
{
int i,d1,d2,f1=0,f2=0;
for(i=0;i<3;i++)
{
if(q1[i]==a)
{
d1=i;
f1++;
}
if(q2[i]==b)
{
d2=i;
f2++;
}
}

if(d1==d2)
return 1;
if(f2==0&&f1!=0)
return -1;
else return 0;
}
int isoperator(char t)
{
if(t=='+'||t=='-'||t=='*'||t=='/'||t=='$')
return 1;
else return 0;
}
int validate(char a[])
{
int i=0,k=0;
while(a[i]!='\0')
{
if(isoperator(a[i])&&isoperator(a[i+1]))
{
k++;
break;
}
else if(isbracket(a[i]))
{
if(temp.top!=-1)
{
if(!comp(temp.a[temp.top],a[i]))
{
k++;
break;
}
else{
int y;
if(comp(temp.a[temp.top],a[i])==1)

 y=pop(&temp);
else
temp.a[++temp.top]=a[i];
}
}
else
temp.a[++temp.top]=a[i];
   }


i++;

}
if(temp.top!=-1)
k=1;
if(k)
return 0;
else return 1;
}
main()
{

temp.top=-1;
char a[100];
gets(a);
if(validate(a))
printf("Valid");
else printf("no");
getch();
return 0;
}
