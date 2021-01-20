#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/'|| x=='%')
        return 2;
    return 0;
}

int main()
{
    char exp[100];
    char *e, x;
    scanf("%[^\n]%*c", exp);
    int i;
    for (i = 0; exp[i] != '\0'; ++i);
    char exp2[100];
    int j = 0;
    int k;
    for(k=0;k<=i;k++)
    {
        if(exp[k]!=' ')
            exp2[j++] = exp[k];
    }
    printf("\n");
    e = exp2;

    while(*e != '\0')
    {
        if(isalpha(*e) || isdigit(*e))
        {
            if(isalpha(*e))
                 printf("%c ",*e);
            else{
                 while(isdigit(*e))
                 {
                    printf("%c",*e); e++;
                 }
                 printf(" ");
                 e--;
        }
         }
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
                printf("%c ",pop());
            push(*e);
        }
        e++;
    }

    while(top != -1)
    {
        printf("%c ",pop());
    }return 0;
}
