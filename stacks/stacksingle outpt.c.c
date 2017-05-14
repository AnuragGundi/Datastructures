#include <stdio.h>
#include <stdlib.h>
#define max 10
 
int top1, top2, array[max];
void push(void)
{
    int x, ch;
    if (top1 == top2 - 1)
    {
        printf("stack overflow \n");
        return;
    }
    printf("enter a no \n");
    scanf("%d", &x);
    printf("\n press 1 to push the element in 1st stack or press 2 for stack 2:");
    scanf("%d", &ch);
    if (ch == 1)
        array[++top1] = x;
    else
        array[--top2] = x;
    printf("%d element is successfully pushed \n", x);
    return;
}
void pop(void)
{
    int y, ch;
    printf("\n press 1 to pop the element from 1st stack or press 2 for from stack 2");
    scanf("%d", &ch);
    if (ch == 1)
    {
        if (top1 == -1)    // Condition for checking If Stack 1 is Empty
        {
            printf("stack underflow \n");
            return;
        }
        y = array[top1];
        array[top1--]=0;
    }
    else
    {
        if (top2 == max) // Condition for checking If Stack 2 is Empty
        {
            printf("stack underflow \n");
            return;
        }
        y = array[top2];
        array[top2++] = 0;
    }
    printf("%d element is successfully poped from stack \n", y);
    return;
}
void display(void)
{
    int i;
    if (top1 == -1)
    {
        printf("stack 1 is empty \n");
    }
    else
    {
        printf("elements of Stack 1 are : \n");
        for (i = 0; i = top2; i--)
        {
            printf("%d\n", array[i]);
        }
    return ;
}
}
 
void main(void)
{
    int ch;
    top1 = -1, top2 = max;
 
    do
    {
        printf("1:push\n 2:pop\n 3:display\n 4:exit\n choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:push();
            break;
        case 2:pop();
            break;
        case 3:display();
            break;
        case 4:printf("quits from program \n");
            break;
        default:printf("wrong choice \n");
            break;
        }
    } while (ch!= 4);
}

