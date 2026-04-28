// https://toph.co/p/trivial-summation

#include<bits/stdc++.h>                                         //DRINK WATER
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using u128 = __uint128_t;


//#define read()          freopen("folding.in","r",stdin)
//#define write()         freopen("folding.out","w",stdout)

#define ff              first
#define ss              second
#define pb              push_back
#define endl            "\n"
#define ll              long long
#define double          long double
#define ull             unsigned long long
#define all(x)          x.begin(), x.end()
#define rall(x)         x.rbegin(), x.rend()
#define uniq(x)         unique(x.begin(), x.end()) - x.begin()
#define deci(x)         cout << fixed << setprecision(x);
#define war()           ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);




ll M;


u128 sum_1_n(u128 n){
    ll ans=((((u128)n)*(u128)(n+1))/2)%M;
    return ans;
}

ll gcd (u128 a, u128 b){if(b==0){return a;} else{return gcd(b,a%b);}}

u128 lcm (ll a, ll b){
    return (((u128)a/gcd(a,b))*b);
}

ll need_to_minus(ll a, ll b, ll r){
    u128 rr=lcm(a,b);
    u128 z3=r/rr;
    ll ans= (sum_1_n(z3)*rr)%M;
    return ans;
}


//----------NO DRINK WATER----------(RAMADAN)
void solve(int T){
    ll r,a,b;
    cin>>r>>a>>b>>M;

    ll z1=r/a;
    ll z2=r/b;

    ll ans= (((sum_1_n(z1)*a)%M) +  ((sum_1_n(z2)*b)%M))%M;

    ans-=need_to_minus(a,b,r);
    ans%=M;
    ans=(ans+M)%M;
    cout<<ans<<endl;


    
}




int32_t main(){
    war();
    //read();   write();
    /////////////////////////////////////

    /////////////////////////////////////
    int tc=1;
    cin>>tc;
    for(int T=1; T<=tc; T++){
        solve(T);
    }
return 0;
}

