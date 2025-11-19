#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
   int n,m;
vector<int> sol;
vector<vector<int>>sub;
vector<vector<int>> teacher;
int q;
int c[100][100]={0};
int ansmin=1e9;
int minc=1e9;
int check1(int k,int j){
   for(int i=0;i<teacher[k].size();i++){
       if(c[teacher[k][i]][j] || c[j][teacher[k][i]]) return 0;
   }
   return 1;
}
void try1(int k,int cur){
   for(int i=0;i<sub[k].size();i++){
       if(check1(sub[k][i],k)){
           sol[k]=sub[k][i];
           teacher[sub[k][i]].push_back(k);
           int z=teacher[sub[k][i]].size();
           int t=cur;
           cur=max(cur,z);
           if(k==m){
               ansmin=min(cur,ansmin);
           }
           else{
               if(cur<ansmin) try1(k+1,cur);
           }
           teacher[sub[k][i]].pop_back();
           cur=t;
       }
   }
}
int main(){
  cin>>n>>m;
  sub.resize(m+1);
  sol.resize(m+1);
  teacher.resize(n+1);
  for(int i=1;i<=n;i++){
      int a;
      cin>>a;
      int b;
      for(int j=0;j<a;j++){
            cin>>b;
            sub[b].push_back(i);
      }
  }
  cin>>q;
  while(q--){
   int a,b;
   cin>> a>>b;
   c[a][b]=1;
   c[b][a]=1;
  }
  try1(1,0);
  if(ansmin==1e9) cout<<-1;
  else
  cout<<ansmin;
}

