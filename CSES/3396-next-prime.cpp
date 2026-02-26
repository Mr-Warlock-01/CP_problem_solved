#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
using u128 = __int128_t;
 
#define read()          freopen("cooling.in","r",stdin)
#define write()         freopen("cooling.out","w",stdout)
 
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
#define war()           ios::sync_with_stdio(0); cin.tie(0);
 
const ll LLMax = 1e18;
const ll LLMin = -1e18;
const ll MOD   = 1e9+7;
const double PI = acos(-1);       //3.1415926535897932384626
 
int dx[] = {-1, 1,  0, 0, -1, -1,  1, 1};
int dy[] = { 0, 0, -1, 1, -1,  1, -1, 1};
 
//pbds
//template<typename T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//template<typename T>using ordered_multiset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
//debug
#ifndef ONLINE_JUDGE
#include "debug.h"
#else
#define db(x)
#endif
 
//sc
template<typename T1> istream &operator>>(istream &cin, vector<T1> &a) { for (auto &x : a) cin >> x; return cin; }
 
// nCr = n! / r! * (n-r)!
// nPr = n! / (n-r)!
// .order_of_key(x)
// *.find_by_order(x)
//substr
//cin.ignore();
//get<idx>(z) //tuple
//__builtin_popcount()
//memset(dp, -1, sizeof(dp));
//cout<<"Case "<<T<<": ";
 
#define YES {cout<<"YES"<<endl;}
#define NO  {cout<<"NO"<<endl;}
#define IMP {cout<<"-1"<<endl;}
 
 
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
 
#define int ll
const int N=1e6+7;
 
u128 powMod(u128 x, u128 n, u128 M){u128 res=1; while(n){if(n&1){res=(res*x)%M;} x=(x*x)%M; n>>=1;} return res;}
 
bool is_composite(u128 x, u128 a, u128 d, u128 s){
    u128 z=powMod(a, d, x);
    if(z==1 || z==(x-1)){return 0;}
    for(int i=0; i<s; i++){
        z=(z*z)%x;
        if(z==(x-1)){return 0;}
    }
    return 1;
}
bool prime_check(u128 x){
    if(x<4){return 1;}
    u128 s=0;    //2^s;
    u128 d=x-1;
    while((d & 1)==0){d/=2; s++;}
    for(int i=0; i<5; i++){
        u128 a=2+(rand()%(x-3));
        if(is_composite(x, a, d, s)){return 0;}
    }
    return 1;
}
void solve(int T){
    int n;  cin>>n;
    if(n==1){cout<<2<<endl; return;}
    n++;
    if(n%2==0){n++;}
    while(!prime_check(n)){
        n+=2;
    }
    cout<<n<<endl;
} 
 
 
 
    
 
int32_t main(){             //DRINK WATER
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
 
/*
 
     /\_/\
    (= ._.)
    / >  \> Mr_Warlock
   /      \
 
*/