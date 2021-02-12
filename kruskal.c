#include <stdio.h>
#include <stdlib.h>
struct Edge
{
	int source;
	int des;
	int weight;
};
int compare(const void* a, const void* b)
{
	struct  Edge* edge1  = (struct Edge*)a;
	struct  Edge* edge2  = (struct Edge*)b;
	return edge1->weight > edge2->weight;
}
int find(int v,int *parent)
{
	if(v==parent[v])
		return v;
	return find(parent[v],parent);
}
int main(int argc, char const *argv[])
{
	int V,E;
	scanf("%d %d",&V,&E);
	struct Edge *edge = (struct Edge*)malloc(sizeof(struct Edge)*E);
	int i;
	for (i = 0; i < E; ++i)
	{
		int s,d,w;
		scanf("%d %d %d",&s,&d,&w);
		edge[i].source = s;
		edge[i].des = d;
		edge[i].weight = w;
	}
	printf("MST of the Graph is:\n");
	qsort(edge,E,sizeof(struct Edge),compare);
	int *parent = (int*)malloc(sizeof(int)*V);
	for (int i = 0; i < V; ++i)
	parent[i] = i;
    int count = 0;
     i =0;
    while(count!=V-1)
    {
    	struct Edge* curr;
    	curr->source = edge[i].source;
    	curr->des    = edge[i].des;
    	curr->weight = edge[i].weight;
    	i++;
    	int source = find(curr->source,parent);
    	int des    = find(curr->des,parent);
    	if(source!=des)
    	{
    		printf("%d ",curr->source);
    		printf("%d ",curr->des);
    		printf("%d ",curr->weight);
    		printf("\n");
    		count++;
    		parent[source] = des;

    	}
     }
	return 0;
}
