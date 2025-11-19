#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#include <utility>

int tong(vector<string>&b,string c,string d){
    int dem=0;
    for(int i=0;i<b.size();i++){
        if(b[i]>=c && b[i]<=d) dem++;
    }
    return dem;
}
int main()
{
    int dem=0;
    int err=0;
    unordered_map<string,int> loi;
    map<pair<string,string>,int> diem;
    map<string,int> tongdiem;

    string a;
    string b,c,d;
    int e;
    vector <string> t;
    while(1){
        cin>>a;
        if(a=="#") break;
        cin>>b>>c>>d>>e;
        dem++;
        if(d=="ERR") {err++;
        loi[a]++;
        }
        if(diem.find({a,b})!=diem.end()){
            int z=diem[{a,b}];
            diem[{a,b}]=max(z,e);
            tongdiem[a]=tongdiem[a]-z+max(z,e);
        }
        else {
                diem[{a,b}]=e;
                tongdiem[a]+=e;
        }
        t.push_back(c);
    }
    while(1){
        cin>>b;
        if(b=="#") break;
        else if(b=="?total_number_submissions") cout<<dem<<endl;
        else if(b=="?number_error_submision"){
            cout<<err<<endl;
        }
        else if(b=="?number_error_submision_of_user"){
                cin>>c;
                cout<<loi[c]<<endl;
        }
        else if(b=="?total_point_of_user"){
            cin>>c;
            cout<<tongdiem[c]<<endl;
        }
        else {
            cin>>c>>d;
            cout<<tong(t,c,d)<<endl;
        }
    }
}

