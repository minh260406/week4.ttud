#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
vector<vector<int>>a;
int n,m;  // n dinh va m canh
vector<int> vis;
vector<int> ans;
vector<int> pre;
deque<int>q;
void bfs(int s){
    vis[s]=1;
    pre[s] = -1;          // node bắt đầu
    ans.push_back(s);
    q.push_back(s);
    while(!q.empty()){
        int t = q.front();
        q.pop_front();
        for(int i=0;i<a[t].size();i++){
            int v = a[t][i];
            if(vis[v]==0){
                q.push_back(v);
                ans.push_back(v);
                pre[v] = t;       
                vis[v] = 1;
            }
        }
    }
}
int main(){
    cin >> n >> m;
    a.resize(n+1);
    vis.resize(n+1,0);
    pre.resize(n+1,-1);
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int z, l;
    cin >> z >> l;
    for(int i=1;i<=n;i++){
        sort(a[i].begin(),a[i].end());
    }
    bfs(z);
    if(vis[l] == 0){          
        cout << "-1";
        return 0;
    }
    vector<int> path;
    int t = l;
    while(t != -1){
        path.push_back(t);
        t = pre[t];
    }
    for(int j = path.size()-1; j >= 0; j--){
        cout << path[j] << " ";
    }
}
