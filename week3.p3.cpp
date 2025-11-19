#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
int n,c;
vector<int>a;
int distance(int l,int r){
	if(l>r) return 0;
	int mid=(l+r)/2;
	int check=0;
	int t=1;
	int last=a[0];
	for(int i=1;i<n;i++){
		if(a[i]-last>=mid){
			t++;
			last=a[i];
		}
		if(t==c){
			check=1;
			break;
		}
	}
	if(check){
		int z=distance(mid+1,r);
		return max(z,mid);
	}
	else return distance(l,mid-1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
	int q;
	cin>>q;
	while(q--){
		cin>>n>>c;
		a.resize(n);
		for(int i=0;i<n;i++) cin>>a[i];
		sort(a.begin(),a.end());
			int v=(a[n-1]-a[0])/(c-1);
			cout<<distance(0,v)<<endl;
	}
	
}

