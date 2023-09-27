#include<bits/stdc++.h>
using namespace std;
#define size 100
int w[size][size],d[size],pre[size];
int n=0;
bool flag[size];
string name[size];
void Initialize(int s)
{
    for(int i=0; i<n; i++)
    {
        d[i]=INT_MAX;
        pre[i]=-1;
    }
    d[s]=0;
}
void Relax(int u,int v)
{
    if((d[u]+w[u][v])<d[v])
    {
        d[v]=d[u]+w[u][v];
        pre[v]=u;
    }
}
/*int extract_min()
{
    int f=INT_MAX;
    int index=-1;
    for(int u=0;u<n;u++)
    {
            if(flag[u]&&f>d[u]){
                f=d[u];
                index=u;
            }
    }
    return index;
}
*/
void Dijkstra(int s)
{
    //int queueSize=n;

    for(int u=0; u<n; u++)
    {
        for(int v=0; v<n; v++)
        {
            if(w[u][v]!=0)
            {
                Relax(u,v);
            }
        }
    }

}
bool BellmanFord(int s)
{
    Initialize(s);
    int k=0;
    int itr=n-1;
    while(itr--)
    {
        if(k<n){
        Dijkstra(k);
        k++;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(w[i][j]!=0)
            {
                if(d[j]>d[i]+w[i][j])
                    return false;
            }
        }
    }
    return true;
}
void readInput()
{
    int u,v;
    string s;
    while(cin>>s)
    {
        if(s=="END")
            break;
        for(u=0; u<n; u++)
        {
            if(name[u]==s)
                break;
        }
        if(u==n)
        {
            name[n]=s;
            n++;
        }
        cin>>s;
        for(v=0; v<n; v++)
        {
            if(name[v]==s)
                break;
        }
        if(v==n)
        {
            name[n]=s;
            n++;
        }
        cin>>w[u][v];
    }

}
void printGraph()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<w[i][j]<<" ";
        }
        cout<<endl;
    }
}
void printPath(int des)
{
    if(des==-1) return;
    printPath(pre[des]);
    cout<<name[des]<<"->";
}
int main()
{
    freopen("dijkstraInput.txt","r",stdin);
    readInput();
    cout<<"pos states"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<i<<" "<<name[i]<<endl;
    }
    printGraph();
    int s=0;
    if(BellmanFord(s))
    {
        cout<<"Bellman Ford final length"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<d[i]<<" ";
        }
        cout<<endl;
        int destination=3;
        printPath(destination);
    }
    else cout<<"negative path exist"<<endl;
    return 0;
}

