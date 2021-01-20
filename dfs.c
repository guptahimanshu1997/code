#include <stdio.h>
int stack[10];
int top=-1;
int visited[10];
int n;
int a[10][10];
void push(int val){
    stack[++top]=val;
}
int pop(){
    int ver=stack[top--];
    printf("%d\t",ver);
    return ver;
}
int stackempty(){
    if(top==-1)
    return 1;
    else
    return 0;
}
void dfs(int source){
    push(source);
    visited[source]=1;
    while(!stackempty()){
        int i;
        int v=pop();
        for(i=n-1;i>=0;i--){
            if(a[v][i]&&!(visited[i])){
                push(i);
                visited[i]=1;
            }
        }
    }
}
int main(void) {

int t;
scanf("%d",&t);
while(t--){
 int E;
 printf("Enter the Number of nodes and edges in");
 if(t==1) printf(" First Graph:\n");
 if(t==0) printf(" Second Graph\n");
 scanf("%d %d",&n,&E);
 int c,b;
 for(c=0;c<n;c++) for(b=0;b<n;b++) a[c][b]=0;
 for(c=0;c<n;c++) visited[c] = 0;
 if(t==0) n = n+1;
 printf("Enter edges between nodes\n");
 for(int i=0;i<E;i++)
 {

     int u,v;
    scanf("%d %d",&u,&v);
     a[u][v] = 1;
     a[v][u] = 1;
 }
 printf("\nDFS:\n");
 dfs(1);
 printf("\n");
 }
 return 0;
}
