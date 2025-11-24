#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
vector<vector<int>>a;
int n,m;  // n dinh va m canh
vector<int> vis,ans,pre,f,d;
int tg=0;
void dfs(int s){
        ans.push_back(s);
        vis[s]=1;
        tg++;
        d[s]=tg;
        for(int i=1;i<=n;i++){
            if(a[s][i]==1 && vis[i]==0){
                pre[i]=s;
                dfs(i);
        }
    }
       tg++;
       f[s]=tg;
}
int main(){
    cin>>n>>m;
    a.resize(n+1,vector<int>(n+1,0));
    vis.resize(n+1,0);
    f.resize(n+1);
    d.resize(n+1);
    pre.resize(n+1,-1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            pre[i]=-1;
            dfs(i);
        }
    }
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
}