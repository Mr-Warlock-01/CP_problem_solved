#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;
//using u128 = __uint128_t;

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
ll powMod(ll x, ll n, ll M){ll res=1; while(n){if(n&1){res=(res*x)%M;} x=(x*x)%M; n>>=1;} return res;}
ll invMod(ll x, ll M){return powMod(x, M-2, M);}
#define int ll
const int N=1e6+7;

int shot_need[N];
int fact[N];
int inv_fact[N];
vector<int>khujo;

void pre_cal(){
    //1st part
    for(int i=2; i<N; i++){
        shot_need[i]=i-1;
    }

    for(int i=2; i<N; i++){
        for(int j=2*i; j<N; j+=i){
            shot_need[j]-=shot_need[i];
        }
    }
    for(int i=1; i<N; i++){
        shot_need[i]+=shot_need[i-1];
    }
    for(int i=1; i<N; i++){
        shot_need[i]*=6;
    }
    for(int i=1; i<N; i++){
        shot_need[i]+=6;
    }

    //2nd part
    fact[0]=1;
    for(int i=1; i<N; i++){
        fact[i]=(fact[i-1]*i)%MOD;
    }
    inv_fact[N-1]=invMod(fact[N-1],MOD);
    for(int i=N-2; i>=0; i--){
        inv_fact[i]=(inv_fact[i+1]*(i+1))%MOD;
    }

    int x=0;
    int sum=0;
    ull ok=3*N;
    ok*=N;
    while(sum<=(3*N*N)){
        khujo.pb(sum);
        x+=6;
        sum+=x;
    }
}

int ncr(int n, int r){
    int ans=(inv_fact[r]*inv_fact[n-r])%MOD;
    ans=(ans*fact[n])%MOD;
    return ans;
}

int BS(int val){
    int l=0, r=khujo.size()-1;
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        if(val<=khujo[mid]){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;
}

void solve(int T){
    int n,k;  cin>>n>>k;
    cout<<shot_need[n]%MOD<<" ";
    int z=BS(k);
    int need=k-khujo[z-1]-1;
    while(need>=z){
        need-=z;
    }
    cout<<ncr(z,need)<<endl;
} 



    

int32_t main(){             //DRINK WATER
    war();
    //read();   write();
    /////////////////////////////////////
    pre_cal();
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