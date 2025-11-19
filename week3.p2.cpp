#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
	vector<int> a;
	vector<int>tem;
	int n;
	int z=1e9+7;
	long long merge(int l,int r){
		if(l>=r) return 0;
		long long cnt=0;
		int mid=(l+r)/2;
		cnt+=merge(l,mid);
		cnt+=merge(mid+1,r);
		int i=l,j=mid+1,k=l;
		while(i<=mid && j<=r){
			if(a[i]<=a[j]){
				tem[k++]=a[i++];
			}
			else{
				cnt=(cnt+mid-i+1)%z;
				tem[k++]=a[j++];
			}
		}
		while(i<=mid) tem[k++]=a[i++];
		while(j<=r) tem[k++]=a[j++];
		for(int i=l;i<=r;i++){
			a[i]=tem[i];
		}
		return cnt;
	}
int main() {
	ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
	cin>>n;
	a.resize(n);
	tem.resize(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	long long t=merge(0,n-1)%z;
	cout<<t;
	
}

