#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include<queue>
using namespace std;
deque<int>q;
int n;
int l1,l2;

int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>l1>>l2;
    vector<int> f(n);
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    int ans=-1e9;
    for(int i=0;i<n;i++){
        while(!q.empty() && q.front()<i-l2) q.pop_front();
        if(i-l1>=0){
            while(!q.empty() && f[q.back()]<f[i-l1]) q.pop_back();
            q.push_back(i-l1);
        }
        if(!q.empty()) f[i]=a[i]+f[q.front()];
        else f[i]=a[i];
        ans=max(ans,f[i]);
    }
    cout<<ans;
}  