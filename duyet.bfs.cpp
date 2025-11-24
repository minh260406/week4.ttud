#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
vector<vector<int>>a;
int n,m;  // n dinh va m canh
vector<int> vis;
vector<int> ans;
vector<int> prev;
deque<int>q;
void bfs(int s){
    vis[s]=1;
    ans.push_back(s);
    q.push_back(s);
    while(!q.empty()){
        int t=q.front();
        q.pop_front();
        for(int i=1;i<=n;i++){
            if(a[t][i]==1 && vis[i]==0){
                q.push_back(i);
                ans.push_back(i);
                vis[i]=1;
            }
        }
    }
}
int main(){
    cin>>n>>m;
    a.resize(n+1,vector<int>(n+1,0));
    vis.resize(n+1,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        a[x][y]=1;
        a[y][x]=1;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            bfs(i);
        }
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<" ";
}