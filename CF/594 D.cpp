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

#define YES {cout<<"Yes"<<endl;}
#define NO  {cout<<"No"<<endl;}
#define IMP {cout<<"-1"<<endl;}


///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE

ll powMod(ll x, ll n, ll M){ll res=1; while(n){if(n&1){res=(res*x)%M;} x=(x*x)%M; n>>=1;} return res;}
ll inv(ll x, ll M=MOD){return powMod(x, M-2, M);}

#define int ll
const int N=2e5+7;
const int NN=1e6+7;

int arr[N];
int pre[N];
int treee[4*N];
vector<int>prime[NN];
vector<pair<int,int>>QQ[N];
map<int,int>mp;

int ans[N];

void factors_find(){
    for(int i=2; i<NN; i++){
        if(prime[i].size()==0){
            for(int j=i; j<NN; j+=i){
                prime[j].pb(i);
            }
        }
    }
}

void build(int node, int st, int en){
    if(st==en){treee[node]=1; return;}
    int mid=((en-st)/2)+st;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    treee[node]=1;
    return;
}

int query(int node, int st, int en, int l, int r){
    if(st>r || en<l){return 1;}
    else if(st>=l && en<=r){return treee[node];}
    int mid=((en-st)/2)+st;
    int q1= query(2*node, st, mid, l, r);
    int q2= query(2*node+1, mid+ 1, en, l, r);
    return (q1*q2)%MOD;
}

void update(int node, int st, int en, int ind, int val){
    if(st==en){treee[node]=(treee[node]*val)%MOD; return;}
    int mid=((en-st)/2)+st;
    if(st<=ind && mid>=ind){update(2*node,st, mid, ind, val);}
    else{update(2*node+1, mid+1, en, ind, val);}
    treee[node]=(treee[2*node] * treee[2*node+1])%MOD;
    return;
}

void solve(int T){
    int n;  cin>>n;
    for(int i=1; i<=n; i++){cin>>arr[i];}
    int q;  cin>>q;
    for(int i=0; i<q; i++){
        int l,r;    cin>>l>>r;
        QQ[r].pb({l,i});
    }
    
    factors_find();
    build(1,1,n);
    pre[0]=1;

    for(int i=1; i<=n; i++){
        pre[i]=(pre[i-1]*arr[i])%MOD;
    }

    for(int i=1; i<=n; i++){
        for(auto u:prime[arr[i]]){
            if(mp.find(u)!=mp.end()){
                update(1, 1, n, mp[u], (u*inv(u-1))%MOD);
            }
            update(1, 1, n, i, ((u-1)*inv(u))%MOD);
            mp[u]=i;
        }
        for(auto [l,idx]:QQ[i]){
            int z=query(1, 1, n, l, i);
            int ANS=( pre[i]* inv(pre[l-1]) )%MOD;
            ANS=(ANS*z)%MOD;
            ans[idx]= ANS;
        }
    }

    for(int i=0; i<q; i++){cout<<ans[i]<<endl;}
}   


    

int32_t main(){             //DRINK WATER
    war();
    //read();   write();
    /////////////////////////////////////
   
    /////////////////////////////////////
    int tc=1;
    //cin>>tc;
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