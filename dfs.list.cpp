#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
vector<vector<int>>a;
int n,m;  // n dinh va m canh
vector<int> vis,ans,pre,f,d,id;
int tg=0;
int cnt=0;
void dfs(int s){
        ans.push_back(s);
        id[s]=cnt;
        vis[s]=1;
        tg++;
        d[s]=tg;
        for(int i=0;i<a[s].size();i++){
            int v=a[s][i];
            if(vis[v]==0){
                pre[v]=s;
                dfs(v);
        }
    }
       tg++;
       f[s]=tg;
}
int main(){
    cin>>n>>m;
    a.resize(n+1);
    vis.resize(n+1,0);
    f.resize(n+1);
    d.resize(n+1);
    id.resize(n+1);
    pre.resize(n+1,-1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        sort(a[i].begin(),a[i].end());
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            cnt++;
            pre[i]=-1;
            dfs(i);
        }
    }
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    cout<<endl;
    for(int i=1;i<=cnt;i++){
        cout<<i<<endl;
        for(int j=1;j<=n;j++){
            if(id[j]==i) cout<<j<<" ";
        }
        cout<<endl;
    }
}
/*
in ra path:
for(int i=1;i<=n;i++){
        if(i!=u){
            vector<int>path;
            int t=i;
            while(t!=-1){
                path.push_back(t);
                t=pre[t];
            }
            for(int j=path.size()-1;j>=0;j--){
               cout<<path[j]<<" ";
            }
            cout<<endl;
        }
    }
*/