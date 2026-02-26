#include<bits/stdc++.h>

//#define int long long
//#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;


signed main(){
    string s;   cin>>s;
    int z=s.length();
    int o_bra=0;
    //int len_bra;
    int ans=0;
    for(int i=0; i<z; i++){
        if(s[i]=='('){o_bra++;}
        else{
            if(o_bra==0){continue;}
            else{
                o_bra--;
                ans++;
            }
        }
    }
    cout<<2*ans;
return 0;
}