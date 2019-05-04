#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<stack>
using namespace std;
vector<pair<int,int> >graph[100005];
int visited[100005];
int parents[100005];
int dis[100005];
int node;
stack<int>sta;
map<int,int>m;
void bfs(int s)
{
    queue<int>q;

    q.push(s);
    m[s]=0;
    sta.push(m[s]);
    visited[s]=1;
    while(!q.empty()){
        int hold=q.front();
        q.pop();
        for(int i=0;i<graph[hold].size();i++){
                int x=graph[hold][i].first;
            if(visited[graph[hold][i].first]==-1){
                    m[x]=m[hold]+1;
                    sta.push(m[x]);
                visited[graph[hold][i].first]=1;
                dis[graph[hold][i].first]=dis[hold]+graph[hold][i].second;
                parents[graph[hold][i].first]=hold;
                q.push(graph[hold][i].first);
            }

        }
    }


}
int main()
{

    int t;
    cin>>t;
    for(int i=0;i<t;i++){
    cin>>node;
    int u,v,w;
    for(int i=1;i<=node-1;i++){
        cin>>u>>v>>w;
        graph[u].push_back(make_pair(v,w));


    }
    for(int i=1;i<=node;i++){
        visited[i]=-1;
        parents[i]=-1;
        dis[i]=0;
    }
    int start=1;
    bfs(start);

    int a=sta.top();
int count=0;
	for (std::map<int,int>::iterator it=m.begin(); it!=m.end(); ++it){
    if(it->second==a){
        if(dis[it->first]%2==1){
            count++;
        }

    }
	}
cout<<count<<endl;
    }

}
