#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
//using u128 = __uint128_t;
//using i128 = __int128_t;

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
};


#define int ll
const int N=1e6+7;

int p1=137,  M1=14457881;
int p2=455,  M2=11457857;

int ans=0;
vector<int>graph[N];
vector<int>re_graph[N];
int dp[N][2];


int xxx(int x, int f){
    if(~dp[x][f]){return dp[x][f];}
    int ans=f;

    for(int u: graph[x]){
        if(f==0){
            ans+=max(xxx(u,0),xxx(u,1));
        }
        else{
            ans+=xxx(u,0);
        }
    }
    return dp[x][f]=ans;
}



void solve(int T){
    int n;  cin>>n;
    gp_hash_table<pair<int,int>,bool,custom_hash>st;
    set<tuple<int,int,int>>ss;
    gp_hash_table<pair<int,int>,int,custom_hash>mp;

    for(int z=0; z<n; z++){
        string s;   cin>>s;
        int h1=0,h2=0;
        int z1=0,z2=0;
        for(int i=0; i<(int)s.size(); i++){
            h1= ((h1*p1) + s[i]) % M1;
            h2= ((h2*p2) + s[i]) % M2;
            if(i!=0){
                z1= ((z1*p1) + s[i]) % M1;
                z2= ((z2*p2) + s[i]) % M2;
            }

            int with=(h1<<32)^h2;
            int with_out=(z1<<32)^z2;
            st[{i+1, with}]=1;
            ss.insert({i+1, with, with_out});
        }
    }

    int x=1;
    for(auto [sz, with, with_out]: ss){
        if((mp.find({sz,with}))==mp.end()){
            mp[{sz,with}]=x;
            x++;
        }

        if(st.find({sz-1,with_out})!=st.end()){
            graph[mp[{sz-1,with_out}]].pb(mp[{sz,with}]);
        }
    }


    int ans=0;
    for(int i=1; i<x; i++){
        if(dp[i][0]==-1){;
            ans+=max(xxx(i, 0), xxx(i, 1));
        }
    }

    cout<<ans<<endl;

    for(int i=1; i<x; i++){
        graph[i].clear();
        dp[i][0]=dp[i][1]=-1;
    }
} 



    

int32_t main(){             //DRINK WATER
    war();
    //read();   write();
    /////////////////////////////////////
    memset(dp, -1, sizeof(dp));
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