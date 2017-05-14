#include<stdio.h>
#include<conio.h>
#include<string.h>
struct stack
{
char a[100];
int top;
}s;
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
int precedence(char a,char b)
{
 if(a==')')
 return 0;
 if(b=='(')
 return 1;
 if(b==')')
 return 0;
 if(a==')'&&b=='(')
 return 1;
 if((a=='$'))
 return 1;
 if(b=='$')
 return 0;
 if((a=='*'||a=='/')||b==a)
 return 1;
 if((b=='*'||b=='/'))
 return 0;
 if((a=='+'||a=='-')&&(b!='+'&&b!='-'))
  return 0;
  if((b=='+'||b=='-')&&(b=='+'||b=='-'))
  return 1;

}
int pop()
{
if(s.top!=-1)
{
return s.a[s.top--];
}
}
char y[100];
char *pf(char a[])
{
int i=0,k=0;

while(a[i]!='\0')
{
if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
{
y[k]=a[i];
k++;
}
else
{
while(s.top!=-1&&precedence(s.a[s.top],a[i])>0)
{
//if(1){
y[k]=pop();
k++;
//}
if(a[i]=='('&&s.a[s.top]==')')
{u=pop();break;}
}
if(a[i]!='(')
s.a[++s.top]=a[i];
}

i++;
}
while(s.top!=-1)
{
y[k]=pop();
k++;
}
y[k]='\0';
return y;
}
main()
{
char a[100];
s.top=-1;
scanf("%s",&a);
printf("%s",rev(pf(rev(a))));
getch();
return 0;
}
