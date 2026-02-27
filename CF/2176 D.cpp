#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
// using u128 = __uint128_t;

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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x){
        x+=0x9e3779b97f4a7c15;  x=(x^(x>>30))*0xbf58476d1ce4e5b9;   x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    size_t operator()(uint64_t x) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(pair<uint64_t, uint64_t>x) const { 
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); 
        return splitmix64(x.first+FIXED_RANDOM)^(splitmix64(x.second+FIXED_RANDOM)>>1); 
    } 
    size_t operator()(const pair<uint64_t, pair<uint64_t,uint64_t>>& x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        uint64_t h1 = splitmix64(x.first + FIXED_RANDOM);
        uint64_t h2 = splitmix64(x.second.first + FIXED_RANDOM);
        uint64_t h3 = splitmix64(x.second.second + FIXED_RANDOM);
        return h1 ^ (h2 >> 1) ^ (h3 << 1);
    }
};



#define int ll
const int N=2e5+7;
vector<int>graph[N];
ull arr[N];
int M=998244353;

// map<pair<int,pair<int,int>>,int>mp;
gp_hash_table<pair<int,pair<int,int>>, int,custom_hash>mp;

void clr(int n){
    for(int i=0; i<n; i++){
        graph[i].clear();
        arr[i]=0;
    }
    mp.clear();
}

int dfs(int node, ull x_1, ull x_2){
    if(mp.find({node,{x_1, x_2}})!=mp.end()){
        return mp[{node, {x_1, x_2}}];
    }

    int ANS=0;
    if(x_1==0){/**/}
    else if(x_2==0){ANS++;}
    else{
        if((x_1+x_2)==arr[node]){
            ANS++;
        }
        else{
            return ANS;
        }
    }
    for(int x: graph[node]){
        ANS=(ANS+dfs(x, arr[node], x_1))%M;
    }
    return mp[{node, {x_1, x_2}}]=ANS;
}



void solve(int T){
    int n,m;    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }

    for(int i=0; i<m; i++){
        int u,v;    cin>>u>>v;
        graph[u].pb(v);
    }
    int ans=0;
    for(int i=1; i<=n; i++){
        ans=(ans+dfs(i, 0, 0))%M;
    }
    cout<<ans<<endl;
    clr(n+4);
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