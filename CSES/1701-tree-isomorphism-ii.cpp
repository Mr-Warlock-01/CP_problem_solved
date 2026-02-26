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

#define int ll
const int N=1e5+7;
const ll b1= 1949313259;  
const ll b2= 1997293877;  
const ll m1= 2091573227;
const ll m2= 2117566807;

ll base[2][N];

void pre_cal(){
    base[0][0]=base[1][0]=1;
    for(int i=1; i<N; i++){
        base[0][i]=(base[0][i-1]*b1)%m1;
        base[1][i]=(base[1][i-1]*b2)%m2;
    }
}


struct TreeHash{
    int n;
    vector<vector<int>>graph;
    vector<pair<ll,ll>>hash;
    vector<int>sub_tree_sz;
    vector<int>centroid;

    TreeHash(int _n):n(_n){
        graph.assign(n+1, {});
        hash.assign(n+1, {0, 0});
        sub_tree_sz.assign(n+1, 0);
    }

    pair<ll,ll>hash_dfs(int x, int par, int lev){
        ll ans1=0, ans2=0, sz=1;
        for(int u:graph[x]){
            if(u==par){continue;}
            pair<int,int>child=hash_dfs(u,x,lev+1);
            ans1=(ans1+child.ff)%m1;
            ans2=(ans2+child.ss)%m2;
            sz+=sub_tree_sz[u];
        }
        sub_tree_sz[x]=sz;
        ll z1=(sz*base[0][lev])%m1;
        ll z2=(sz*base[1][lev])%m2;
        ans1=powMod(z1,ans1,m1);
        ans2=powMod(z2,ans2,m2);
        return hash[x]={ans1,ans2};
    }

    void addEdge(int u, int v){
        graph[u].push_back(v);
        graph[v].push_back(u);
    }


    int centroid_find(int x, int p){
        int sz=1;
        bool is_centroid=true;
        for(int u:graph[x]){
            if(u==p){continue;}
            int child_sz=centroid_find(u,x);
            if(child_sz > (n/2)){is_centroid=false;}
            sz+=child_sz;
        }
        if((n-sz)>(n/2)){is_centroid=false;}
        if(is_centroid){centroid.push_back(x);}
        return sz;
    }
};






void solve(int T){
    pre_cal();
    int n;  cin>>n;
    
    TreeHash t1(n), t2(n);

    for(int i=1; i<n; i++){
        int u, v;   cin>>u>>v;
        t1.addEdge(u, v);
    }
    for(int i=1; i<n; i++){
        int u, v;   cin>>u>>v;
        t2.addEdge(u, v);
    }

    t1.centroid_find(1,-1);
    t2.centroid_find(1,-1);

    vector<int>c1=t1.centroid;
    vector<int>c2=t2.centroid;

    for(auto u: c1){
        pair<int,int>h1=t1.hash_dfs(u, -1, 1);
        for(auto v:c2){
            pair<int,int>h2=t2.hash_dfs(v, -1, 1);
            if(h1==h2){YES; return;}
        }
    }
    NO;
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