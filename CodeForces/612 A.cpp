#include<bits/stdc++.h>                                 //DRINK WATER

//#define int long long
//#define double long double

#define war() ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);

using namespace std;



signed main(){
    int n,p,q;  string s;  cin>>n>>p>>q>>s;
    int z;
    for( z=0; z<=n; z++){
        if((z%p==0) & ((n-z)%q==0)){break;}
        else if(z==n){z=-1; break;}
    }

    if(z==-1){cout<<"-1\n";     return 0;}
    cout<<(z/p)+((n-z)/q)<<"\n";

    int pm=0,qm=0;
    for(int i=0; i<n; i++){
        if(i<z){
            cout<<s[i];     pm++;
            if(pm%p==0){cout<<"\n";}
        }
        else{
            cout<<s[i];     qm++;
            if(qm%q==0){cout<<"\n";}
        }
    }
return 0;
}