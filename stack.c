#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>



 //int Isfull(struct Arraystack *temp);
// int Isempty(struct Arraystack *temp);


//void push (struct Arraystack *temp , int data);

struct Arraystack
{
   int capacity;
   int top;
   int *array;

};


struct Arraystack * createstack(int cap)
{
    struct Arraystack *temp;
    temp = malloc (sizeof(struct Arraystack));
    temp->top=-1;
    temp->capacity=cap;
    temp->array=malloc(sizeof(int)*temp->capacity);
return temp;
}


 int Isfull(struct Arraystack *temp)
 {

if(temp->top==temp->capacity-1)
return 1;
else
    return 0;

}


void push (struct Arraystack *temp , int data)
{

    if(!Isfull(temp))
    {

        temp->top++;
        temp->array[temp->top]=data;
    }
}

int Isempty(struct Arraystack *temp)
{
if(temp->top==-1)
return 1;
else
    return 0;
}

int pop(struct Arraystack *temp)
{
    int data;

    if(!Isempty(temp))
    {
      data =temp->array[temp->top];
        temp->top--;
        return data;
    }
    return -1;
}



main()
{
    struct Arraystack *temp;
    int ch,data;
    while(1)
    {

        printf("\n1 :push");
        printf("\n2 :pop");
        printf("\n3 :exit");
        printf("enter your choice");
        scanf("%d",ch);
        switch(ch)
        {
        case 1:printf("emter your item");
        scanf("%d",&data);
 void push(temp,data);
        break;
        case 2:      data   =    pop(temp);
        if(data==-1)
            printf("stack is empty");
        else
            printf("poped value is %d",data);
        break;
        case 3:exit(0);
        default :
            printf("invalid choice");
        }
    }
}
