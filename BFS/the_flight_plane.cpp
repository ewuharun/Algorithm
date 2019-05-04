#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
int graph[1005][1005];
int visited[1005];
int dis[1005];
int parents[1005];
int count=0;
queue<int>arr;
 void printpath(int x,int y,int node)
{

    if(parents[y]==-1){
        return ;
    }

    printpath(x,parents[y],node);
    arr.push(parents[y]);
    count++;


}
int main()
{

    int node,edge;
    cin>>node>>edge;
    int m,c;
    cin>>m>>c;
    int u,v;
    for(int i=1;i<=edge;i++){
        cin>>u>>v;
        graph[u][v]=c;
        graph[v][u]=c;
    }
    for(int i=1;i<=node;i++){
        visited[i]=-1;
        dis[i]=0;
        parents[i]=-1;
    }

    int start;
    cin>>start;
    queue<int>q;
    q.push(start);
    visited[start]=1;


    int hold;
    while(!q.empty()){
        hold=q.front();
        q.pop();
        //visited[hold]=1;

        for(int i=1;i<=node;i++){

            if(graph[hold][i]==c){

                if(visited[i]==-1){

                    dis[i]=dis[hold]+c;
                    parents[i]=hold;
                    visited[i]=1;
                q.push(i);
                }
            }

        }



    }

int x,y;
cin>>y;
printpath(start,y,node);


 cout<<count+1<<endl;
 while(!arr.empty()){
    int a=arr.front();
 cout<<a<<" ";
        arr.pop();
 }
 cout<<y<<endl;



}
