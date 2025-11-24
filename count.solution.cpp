#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>a;
int cnt=0;
void try1(int i,int sum){
    if(i==n){
        if((m-sum)%a[i]==0 && (m-sum)/a[i]>=1) cnt++;
        return;
    }
    for(int j=1;j<=m-sum;j++){
        try1(i+1,sum+a[i]*j);
    }
}
int main(){
    cin>>n>>m;
    a.resize(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    try1(1,0);
    cout<<cnt;
}