#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int n,m;
int cnt=0;
vector<int> vis;
void try1(int i){
    if(i==n+1){
        cnt++;
        return;
    }
    for(int j=1;j<=n;j++){
        if(vis[j]==0){
            if(j%i==0 || i%j==0){
                vis[j]=1;
                try1(i+1);
                vis[j]=0;
            }
        }
    }
}
int main(){
    cin>>n;
    vis.resize(n+1,0);
    try1(1);
    cout<<cnt;
}