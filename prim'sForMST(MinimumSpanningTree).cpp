#include<bits/stdc++.h>
using namespace std;
#define m 100
int graph[m][m];
int n;
int d[m],pre[m];
bool flag[m];
int N=0;
int printarray[m];
void initialize(int s)
{
    for(int i=0;i<n;i++)
    {
        d[i]=INT_MAX;
        pre[i]=-1;
    }
    d[s]=0;
}
void relax(int u,int v)
{
   if(d[v]>graph[u][v])
   {
       d[v]=graph[u][v];
       pre[v]=u;
   }
}
int extract_min()
{
    int f=INT_MAX;
    int index=-1;
    for(int i=0;i<n;i++)
    {
        if(flag[i]&&f>d[i]){
            f=d[i];
            index=i;
        }
    }
    return index;
}
void prim(int s)
{
    initialize(s);
    for(int i=0;i<n;i++)
    {
        flag[i]=true;
    }
    int queueSize=n;
    while(queueSize--){
        int u=extract_min();
        printarray[N]=u;
         N++;
         flag[u]=false;
        for(int v=0;v<n;v++)
        {
            if(graph[u][v]>0){
                relax(u,v);
                graph[v][u]=0;
            }
        }

    }

}
void read()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>graph[i][j];
        }
    }
}
void printPath()
{
    int cost=0;
    cout<<"Minimum spanning Tree"<<endl;
    cout<<"U->V  W"<<endl;
    for(int i=1;i<N;i++)
    {
            cout<<pre[printarray[i]]<<"->"<<printarray[i]<<"  "<<graph[pre[printarray[i]]][printarray[i]]<<endl;
            cost+=graph[pre[printarray[i]]][printarray[i]];
    }
    cout<<"Cost:"<<cost<<endl;

}
int main()
{
    freopen("kruskal.txt","r",stdin);
    read();
    cout<<"Number of vertices:"<<n<<endl;
    cout<<"____Graph:____"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    int s=0;
    prim(s);
    printPath();
    cout<<endl;
    return 0;
}
