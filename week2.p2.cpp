#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
vector<int> vis;
vector<vector<int>> a;
int n;
int load=0;
int k0;
int f=0;
int m1=1e9;
int c=1e9;
void try1(int k){
	for(int i=1;i<=2*n;i++){
		if(vis[i]==1) continue;
		if((i<=n && k0>load)|| (i>n && load>0 && vis[i-n]==1)){
			ans[k]=i;
			vis[i]=1;
			if(i<=n) load++;
			else load--;
			f+=a[ans[k-1]][i];
			if(k==2*n){
				m1=min(m1,f+a[ans[2*n]][0]);
			}
			else{
				if(f+(2*n-k+1)*c<m1) try1(k+1);
			}
			if(i<=n) load--;
			else load++;
			vis[i]=0;
			f-=a[ans[k-1]][i];
		}		
	}
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
	cin>>n>>k0;
	a.resize(2*n+1,vector<int>(2*n+1));
	vis.resize(2*n+1,0);
	ans.resize(2*n+1);
	ans[0]=0;
	for(int i=0;i<=2*n;i++){
		for(int j=0;j<=2*n;j++){
			cin>>a[i][j];
			if(a[i][j]>0) c=min(c,a[i][j]);
		}
	}
	try1(1);
	cout<<m1;
}

