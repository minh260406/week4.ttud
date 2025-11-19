#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n,x,y;
	cin>>n;
	vector<pair<int,int>> a(n);
	for(int i=0;i<n;i++){
		cin>>x>>y;
		a[i].first=y;
		a[i].second=x;
	}
	sort(a.begin(),a.end());
	int cnt=1;
	int last=a[0].second;
	for(int i=1;i<n;i++){
		if(a[i].second>last){
			cnt++;
			last=a[i].first;
		}
	}
	cout<<cnt;
}

