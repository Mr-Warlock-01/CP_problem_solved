#include<bits/stdc++.h>                                 //DRINK WATER

#define int long long
#define double long double
#define endl "\n"

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;


signed main(){
    war();
    int t;  cin>>t;
    while(t--){
        int  k, p,n;
        cin>>k>>p>>n;
        if(k<p){
            cout<<"0"<<endl;
        }
        else{
            int x=k-p;
            int ans=x*n;
            cout<<ans<<endl;
        }

    }
return 0;
}