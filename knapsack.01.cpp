#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int n,W;
vector<int>c;
vector<int>w;
int re;// remain
int f=0;
int value=0;

void try1(int i){
    if(i==n){
        f=max(f,value);
        return;
    }
    for(int j=re/w[i];j>=0;j--){
        value+=j*c[i];
        re-=j*w[i];
        double bound = value;
        if(i + 1 < n)
            bound += re*(double(c[i+1]) / w[i+1]);
        if(bound > f)
            try1(i + 1);
        value-=j*c[i];
        re+=j*w[i];
    }
}
int main(){
    cin>>n>>W;
    c.resize(n);
    w.resize(n);
    for(int i=0;i<n;i++) cin>>c[i];
    for(int i=0;i<n;i++) cin>>w[i];
    vector<pair<double,pair<int,int>>>b(n);
    for(int i=0;i<n;i++){
        b[i].first=1.0*c[i]/w[i];
        b[i].second.first=c[i];
        b[i].second.second=w[i];
    }
    sort(b.begin(),b.end(),[](auto &a, auto &d){
        return a.first>d.first;
    });
    for(int i=0;i<n;i++){
        c[i]=b[i].second.first;
        w[i]=b[i].second.second;
    }
    re=W;
    try1(0);
    cout<<f;
}
