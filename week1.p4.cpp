#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int q1[1000000],q2[1000000];
int a[1001][1001];
int vis[1001][1001]={0};
int f=0,r=0;
int n,m;
int check(int i,int j){
    if(i>n || j>m || i<1 || j<1 ) return 1;
    return 0;
}
void push(int x,int y){
    q1[r]=x;q2[r++]=y;
}
int main()
{
    int x,y;
    cin>>n>>m>>x>>y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    push(x,y);
    vis[x][y]=1;
    int ans=-1;
    int lv=0;
    while(f<r){
        int z=r-f;
        if(ans>0) break;
        for(int i=0;i<z;i++){
            x=q1[f];y=q2[f++];
            if(check(x+1,y)){ans=lv+1;break;}
            else{
                if(vis[x+1][y]==0 && a[x+1][y]==0){
                    push(x+1,y);vis[x+1][y]=1;
                }
            }
            if(check(x-1,y)){ans=lv+1;break;}
            else{
                if(vis[x-1][y]==0 && a[x-1][y]==0){
                    push(x-1,y);vis[x-1][y]=1;
                }
            }
            if(check(x,y+1)){ans=lv+1;break;}
            else{
                if(vis[x][y+1]==0 && a[x][y+1]==0){
                    push(x,y+1);vis[x][y+1]=1;
                }
            }
            if(check(x,y-1)){ans=lv+1;break;}
            else{
                if(vis[x][y-1]==0 && a[x][y-1]==0){
                    push(x,y-1);vis[x][y-1]=1;
                }
            }
        }
        lv++;
    }
    cout<<ans;
}

