#include<bits/stdc++.h>                                 //DRINK WATER

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;

signed main(){      //a coins of  n, b coins of 1
    war();
    int t;  cin>>t;
    while(t--){
        int a,b,n,s;        cin>>a>>b>>n>>s;
        int z=min(s/n,a);
        z*=n;
        if(s-z<=b){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
return 0;
}