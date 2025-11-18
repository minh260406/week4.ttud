#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k1,k2;
    cin>>n>>k1>>k2;
    vector<int> s0(n+1,0);// day i off, day i-1 work
    vector<int> s1(n+1,0);// day i work   
    s1[k1]=1;
    s0[1]=1;
    s0[0]=1;
    for(int i=k1+1;i<=n;i++){
        s0[i]=s1[i-1];
        for(int j=k1;j<=k2;j++) if(i-j>=0) s1[i]+=s0[i-j];
    }
    cout<<s0[n]+s1[n];
}  