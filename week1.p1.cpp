#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int time1(string a){
    int h,m,s;
    char c;
    stringstream ss(a);
    ss>>h>>c>>m>>c>>s;
    return h*3600+m*60+s;
}
int sdt(string a){
    if(a.size()!=10) return 0;
    for(int i=0;i<a.size();i++){
        if(a[i]<'0' && a[i]>'9') return 0;
    }
    return 1;
}
int main()
{
    int dem=0;
    unordered_map<string,int> time;
    unordered_map<string,int> num;
    int check=1;
    string a;
    string b,c,d,e,f;
    while(1){
        cin>>a;
        if(a=="#") break;
        cin>>b>>c>>d>>e>>f;
        dem++;
        if(sdt(b)==0 || sdt(c)==0) check=0;
        time[b]+=time1(f)-time1(e);
        num[b]++;
    }
    while(1){
        cin>>b;
        if(b=="#") break;
        if(b=="?check_phone_number") cout<<check<<endl;
        else if(b=="?number_calls_from"){
            cin>>c;
            cout<<num[c]<<endl;
        }
        else if(b=="?number_total_calls") cout<<dem<<endl;
        else if(b=="?count_time_calls_from"){
            cin>>c;
            cout<<time[c]<<endl;
        }
    }
}

