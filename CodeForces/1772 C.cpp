#include<bits/stdc++.h>                                 //DRINK WATER

//#define int long long
//#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;



signed main(){
    int t;  cin>>t;
    while(t--){
        int k,n;    cin>>k>>n;
        vector<int>v;
        int a=1,b=0;

        for(int i=0; i<k; i++){
            if(a>n){ break;}
            v.push_back(a);
            b++;    a+=b;
        }
        int si_ze=v.size();

        int remain = k - si_ze;
        int ok=n;
        for(int i=0; i<remain; ){
            bool che=true;
            for(auto u:v){
                if(ok==u){
                    che=false;
                }
            }
            if(che==true){
                v.push_back(ok);
                ok--;   i++;
            }
            else{
                ok--;   continue;
            }
        }
        sort(v.begin(),v.end());
        for(auto u:v){cout<<u<<" ";}
        cout<<endl;
    }
return 0;
}