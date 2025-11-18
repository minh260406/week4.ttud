#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<queue>
const long long INF = 1e18;
using namespace std;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector<int>a(n+1);
    vector<long long>s(n+1);
    vector<vector<long long>>f(n+1,vector<long long>(2));
    for(int i=1;i<=n;i++) cin>>a[i];
    s[1]=a[1];
    for(int i=2;i<=n;i++) s[i]=a[i]+s[i-1];
    f[0][0]=0;
    f[0][1]=INF;
    for(int i=1;i<=n;i++){
        if(s[i]%2==0){
            f[i][0]=min(s[i],f[i-1][0]);
            f[i][1]=f[i-1][1];
        }
        else{
            f[i][1]=min(s[i],f[i-1][1]);
            f[i][0]=f[i-1][0];
        }
    }
    long long ans=-INF;
    for(int i=0;i<=n;i++){
        if(s[i]%2==0) ans=max(ans,s[i]-f[i][0]);
        else ans=max(ans,s[i]-f[i][1]);
    }
    cout<<ans;
}  