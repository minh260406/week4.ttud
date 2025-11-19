#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<int>> sp(n,vector<int>(__lg(n)+1));
    for(int i=0;i<n;i++) sp[i][0]=i;
    for(int j=1;1<<j<=n;j++){
        for(int i=0;i<n+1-(1<<j);i++){
            if(a[sp[i][j-1]]<a[sp[i+(1<<(j-1))][j-1]]) sp[i][j]=sp[i][j-1];
            else sp[i][j]=sp[i+(1<<(j-1))][j-1];
            }
        }

    int q;
    cin>>q;
    int sum=0;
    while(q--){
        int b,c;
        cin>>b>>c;
        int k=__lg(c-b+1);
        sum+=min(a[sp[b][k]],a[sp[c+1-(1<<k)][k]]);
    }
    cout<<sum;
}

