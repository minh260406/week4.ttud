#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int x[1000],y[1000],z[1000]={0},dem=0,mint=1e9,c=1e9,f=0; 
int n,m;
int a[1000][1000];
void ptr(){
    for(int i=1;i<n;i++){
        mint+=a[i][i+1];
    }
    mint+=a[n][1];
}
void de(int i){
    for(int j=2;j<=n;j++){
        if(z[j]==0){
            x[i]=j;z[j]=1;
            f+=a[x[i-1]][x[i]];
            if(i==n){
                int tmp=f+a[x[n]][x[1]];
                if(tmp<mint) mint=tmp;
            }
            else{
                int g=f+c*(n-i+1);
                if(g<mint) de(i+1);
            }
            f-=a[x[i-1]][x[i]];
            z[j]=0;
        }
    }
}

int main(){
     cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]>0 && a[i][j]<c) c=a[i][j];
        }
    }
    x[1]=1;
    de(2);
    cout<<mint;
}
