#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int mi=0;
void lar(vector<int>&h){
    stack<int> a;
    stack<int> ab;
    int n=h.size();
    vector<int>r(n,n);
    vector<int>l(n,-1);
    for(int j=0;j<n;j++){
        while(!a.empty() && h[j]<h[a.top()]){
            int i=a.top();a.pop();
            r[i]=j;
        }
        a.push(j);
    }
    for(int j=n-1;j>=0;j--){
        while(!ab.empty() && h[j]<h[ab.top()]){
            int i=ab.top();ab.pop();
            l[i]=j;
        }
        ab.push(j);
    }
    for(int i=0;i<n;i++){
        mi=max(mi,h[i]*(r[i]-l[i]-1));
    }
}
int main()
{
    ios ::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<vector<int>>a(n,vector<int>(m));
    vector<vector<int>>h(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<m;i++){
            if( a[0][i]==1) h[0][i]=1;
            else h[0][i]=0;
    }
    for(int j=0;j<m;j++){
        for(int i=1;i<n;i++){
            if(a[i][j]==1) h[i][j]=h[i-1][j]+1;
            else  h[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        lar(h[i]);
    }
    cout<<mi;
}

