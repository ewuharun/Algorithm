#include<bits/stdc++.h>
using namespace std;
int graph[10000][10000];
int discover_time[10000];
int color[10000];
int finish_time[10000];
int level[10000];
int times=0;
int girls[10000];
void dfs(int start_node,int node)
{
    color[start_node]=1;
    times++;
    discover_time[start_node]=times;
    for(int i=1;i<=node;i++){
        if(graph[start_node][i]==1){
            if(color[i]==-1){
                color[i]=1;
                level[i]=level[start_node]+1;
                dfs(i,node);
            }
        }
    }
    color[start_node]=2;
    times=times+1;
    finish_time[start_node]=times;
}
int main()
{
    memset(color,-1,sizeof(color));
    memset(level,0,sizeof(level));
    memset(girls,0,sizeof(girls));
    int node,edge;
    cin>>node;
    int u,v;
    for(int i=1;i<=node-1;i++){
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    int start_node=1;


    dfs(start_node,node);
    int n;
    cin>>n;
    int a;
    for(int i=1;i<=n;i++){
        cin>>a;
        girls[a]=-1;
    }
    for(int i=1;i<=node;i++){
            if(girls[i]==-1){
                cout<<i<<endl;
                break;
            }
    }
}

