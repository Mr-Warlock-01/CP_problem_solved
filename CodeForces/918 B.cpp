#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;


signed main(){
    war();
    int n,m;  cin>>n>>m;
    map<string,string> ok;

    for(int i=0; i<n; i++){
        string name,ip;
        cin>>name>>ip;
        ok[ip]=name;
    }

    for(int i=0; i<m; i++){
        string name,ip;
        cin>>name>>ip;
        ip.pop_back();
        cout<<name<<" "<<ip<<"; #"<<ok[ip]<<"\n";
    }


return 0;
}