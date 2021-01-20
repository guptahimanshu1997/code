#include<stdio.h>
#include<malloc.h>
struct node{
int data;
struct node* link;
};
struct ndoe *start =  NULL;
struct node* createnode()
{
    struct node *n = (struct node*)malloc(sizeof(struct node));
    return n;
}
void insert(int num)
{
    struct node *temp;
    temp = createnode();
     temp->data = num;
     temp->link = NULL;
     if(start==NULL)
        start = temp;
     else
     {
         struct node *t;

         t = start;
         while(t->link != NULL)
            t = t->link;
         t->link = temp;
     }
}

void display()
{

    struct node *t;
    t = start;
                if(t==NULL) { printf("Link list is Empty \n "); return; }

    while(t!=NULL)
    {
       printf("%d ",t->data);
       t = t->link;
    }

}
void delete()
{

    struct node *temp;
    temp = start;
        if(temp==NULL) { printf("Link list is Empty \n "); return; }

    start = temp->link;
}

void reverse()
{
    struct node *p,*q,*r;
    p = start;
    q=NULL;
    r = NULL;
    while(p!=NULL){
    r = q;
    q = p;
    p = p->link;
    q->link  = r;}
    start  = q;
}

int  search()
{
     int number;
    struct node *temp;
    temp = start;
            if(temp==NULL) { printf("Link list is Empty \n "); return; }
             printf("Enter Number \n");
         scanf("%d",&number);

    while(temp!=NULL)
    {
        if(temp->data==number)
          {
             printf("Number found");
             break;

          }
        temp = temp->link;

    }

       printf("Number not found");

}
int main()
{
    while(1){
    printf("1: ADD \n");
    printf("2: DISPLAY \n");
    printf("3: DELETE \n");
    printf("4: SEARCH \n");
    printf("5: REVERSE \n");
    int n;
    scanf("%d",&n);
    int num;
    int number;
    switch(n)
    {
    case 1:
    printf("enter node \n");
    scanf("%d",&num);
    insert(num);
    break;

    case 2: display();
             printf("\n"); break;

    case 3: delete(); break;
    case 4:  search(); break;
    case 5: reverse(); break;
    default : printf("invalid input \n");

    }
}

}
