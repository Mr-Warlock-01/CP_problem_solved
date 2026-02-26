#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

bool cmd(const pair<int,int> &p1, const pair<int,int> &p2){
    if(p1.second > p2.second){return 1;}
    else if (p1.second < p2.second){ return 0;}
    else{
        if(p1.first>p2.first){return 1; }
        else{return 0;}
    }
}

signed main(){
    war();
    int t;  cin>>t;
    while(t--){
        int n;  cin>>n;
        vector<pair<int, int>> ab;

        for(int i=0; i<n; i++){int z;   cin>>z;     pair<int,int>zz={z,0};    ab.push_back(zz);}
        for(int i=0; i<n; i++){int z;   cin>>z;     ab[i].second=z;}

        sort(ab.begin(),ab.end(),cmd);
        bool haha=false;
        if(ab[0].second==-1){haha=1;}

        if(haha==1){
            int ans=INT_MAX;
            for(auto u:ab){ ans=min(ans,u.first);}
            cout<<"-"<<ans<<"\n";
            continue;
        }

        int a=0,b=0;
        int ans=-INT_MAX;
        for(auto u:ab){
            a+=u.first;
            b+=u.second;
            int zz=a*b;
            if(zz>=ans){ans=zz;}        // this
            else{break;}                // this
            //ans=max(ans,zz);          //ager 2 line er bodole ai tao use kora jay...but ai code kom loop use kore due to BREAK command
        }
        cout<<ans<<"\n";
    }
return 0;
}