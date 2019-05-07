#include<bits/stdc++.h>
using namespace std;
int graph[10000][10000];
int discover_time[10000];
int color[10000];
int finish_time[10000];
int times=0;
void dfs(int start_node,int node)
{
    color[start_node]=1;
    times++;
    discover_time[start_node]=times;
    for(int i=0;i<node;i++){
        if(graph[start_node][i]==1){
            if(color[i]==-1){
                color[i]=1;
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
    int node,edge;
    cin>>node>>edge;
    int u,v;
    for(int i=0;i<edge;i++){
        cin>>u>>v;
        graph[u][v]=1;
        graph[v][u]=1;
    }
    int start_node;
    cin>>start_node;

    dfs(start_node,node);
    for(int i=0;i<node;i++){
        cout<<discover_time[i]<<" ";
    }
}
