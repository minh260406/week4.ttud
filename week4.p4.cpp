#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
    int n,d,T;
   vector<int> a;
   vector<int> t;
   vector<vector<int>> dp;
   int dfs(int i,int k){
      if(k<t[i]) return 0;
      if (dp[i][k]!=-1) return dp[i][k];
      int maxt=a[i];
      for(int j=i-d;j<i;j++){
          if(j>=0) maxt=max(dfs(j,k-t[i])+a[i],maxt);
      }
      dp[i][k]=maxt;
      return dp[i][k];
   }
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   cin>>n>>T>>d;
   a.resize(n);
   dp.resize(n,vector<int>(T+1,-1));
   t.resize(n);
   for(int i=0;i<n;i++) cin>>a[i];
   for(int i=0;i<n;i++) cin>>t[i];
   int ans=0;
   for(int i=0;i<n;i++){
      for(int j=1;j<=T;j++){
         ans=max(ans,dfs(i,j));
      }
   }
   cout<<ans;
}  