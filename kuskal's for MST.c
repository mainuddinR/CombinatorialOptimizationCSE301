#include<stdio.h>
#define max 100
int n;
int graph[max][max];
typedef struct edge
{
    int u,v,w;
}edge;
typedef struct list
{
    edge value[max];
    int n;
}list;
list spanList;
list TotalEdgeList;
int parents[max];
int findParent(int m)
{
    return parents[m];
}
void changeParent(int u, int v)
{
    for(int i=0;i<n;i++)
    {
        if(parents[i]==v)
            parents[i]=u;
    }

}
void kruskal()
{
    TotalEdgeList.n=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(graph[i][j]!=0){
                TotalEdgeList.value[TotalEdgeList.n].u=i;
                TotalEdgeList.value[TotalEdgeList.n].v=j;
                TotalEdgeList.value[TotalEdgeList.n].w=graph[i][j];
                TotalEdgeList.n++;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        parents[i]=i;
    }
    for(int i=0;i<TotalEdgeList.n-1;i++)
    {
        for(int j=i+1;j<TotalEdgeList.n-1;j++)
        {
            if(TotalEdgeList.value[i].w>TotalEdgeList.value[j].w)
            {
                edge temp=TotalEdgeList.value[i];
                TotalEdgeList.value[i]=TotalEdgeList.value[j];
                TotalEdgeList.value[j]=temp;
            }
        }
    }
    spanList.n=0;
    for(int i=0;i<TotalEdgeList.n;i++)
    {
        int u=findParent(TotalEdgeList.value[i].u);
        int v=findParent(TotalEdgeList.value[i].v);
        if(u!=v)
        {
            spanList.value[spanList.n]=TotalEdgeList.value[i];
            changeParent(u,v);
            spanList.n++;
        }
    }
    int cost=0;
    printf("Minimum Spanning Tree:\n");
    printf("u->v  w\n");
    for(int i=0;i<spanList.n;i++)
    {
        printf("%d->%d  %d\n",spanList.value[i].u,spanList.value[i].v,spanList.value[i].w);
        cost=cost+spanList.value[i].w;
    }
    printf("Cost:%d\n",cost);
}
void read()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
}
int main()
{
    freopen("kruskal.txt","r",stdin);
    read();
    printf("Number of vertices:%d\n",n);
    printf("____Graph:____\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",graph[i][j]);
        }
        printf("\n");
    }
    kruskal();
    return 0;
}
