#include<bits/stdc++.h>
using namespace std;
void solve(string s,string d)
{
        map<string,int>m;
        m[s]=1;
        queue<string>q;
        q.push(s);
        while(!q.empty()){
            string hold=q.front();
            q.pop();
            for(int i=1;i<hold.size();i++){
                    string x=hold;
                reverse(x.begin(),x.begin()+i+1);
                if(m[x]==0){

                    q.push(x);
                    m[x]=m[hold]+1;

                }
                if(x==d){
                    cout<<m[x]-1<<endl;
                    return;
                }
            }


        }

}
int main()
{
    int n;
    cin>>n;
    string s="";
    char c;
    for(int i=0;i<n;i++){
        cin>>c;
        s=s+c;
    }
    string d=s;
    sort(d.begin(),d.end());
    if(d==s){
        cout<<0;
        return 0;
    }
    else{
        solve(s,d);
    }




}
