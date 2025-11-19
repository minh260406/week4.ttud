#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> sum;
vector<int> a;
int f=0;
int dem=0;
void try1(int k){
	for(int i=1;i<=(m-f-sum[k+1])/a[k];i++){
		if(f+i*a[k]<=m){
			f+=i*a[k];
			if(k==n) {
			    if(f==m)dem++;
			}
			else{
				try1(k+1);
			}
			f-=i*a[k];
		}
	}
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
	cin>>n>>m;
	a.resize(n+1);
	sum.resize(n+2);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sum[n]=a[n];
	sum[n+1]=0;
	for(int i=n-1;i>=1;i--){
		sum[i]=sum[i+1]+a[i];
	}
	try1(1);
	cout<<dem;
}

