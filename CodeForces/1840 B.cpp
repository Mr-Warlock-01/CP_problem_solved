#include<bits/stdc++.h>

#define int long long
#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);


using namespace std;


signed main(){
    //war();
    int t;  cin>>t;
    while(t--){
        int n,k;    cin>>n>>k;
        int kk=2;
        for(int i=1; i<k; i++){
            kk*=2;
            if(kk>10000000000){
                break;
            }
        }
        cout<<min(n+1,kk)<<"\n";
    }

return 0;
}