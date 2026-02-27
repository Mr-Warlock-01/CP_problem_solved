#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;



signed main(){
    int n;  cin>>n;
    set<int> see;
    int p;  cin>>p;
    while(p--){ int a;  cin>>a;    see.insert(a);}

    int q;  cin>>q;
    while(q--){ int a;  cin>>a;    see.insert(a);}

    int z=see.size();
    if(z==n){cout<<"I become the guy.";}
    else{cout<<"Oh, my keyboard!";}

return 0;
}