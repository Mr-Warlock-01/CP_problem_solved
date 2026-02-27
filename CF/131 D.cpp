#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
//using u128 = __uint128_t;
 
#define read()          freopen("folding.in","r",stdin)
#define write()         freopen("folding.out","w",stdout)
 
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
// *    .find_by_order(x)
//substr
//cin.ignore();
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

#define int ll

const int N=3005;
vector<int>graph[N];
vector<int>new_graph[N];
int parent[N];
bool vis[N];
int ans[N];
int n;

int connected_node_par=0;

int dfs(int x, int p){
    vis[x]=1;
    bool ok=0;

    for(auto u:graph[x]){
        if(u==p){continue;}
        if(!vis[u]){
            ok|=dfs(u,x);
        }
        else if(connected_node_par==0){
            ok=1;   connected_node_par=u;
        }
    }

    if(ok!=0){parent[x]=connected_node_par;}
    if(x==connected_node_par){ok=0;}
    return ok;
}

void dfs_ans_cal(int x, int p, int lev){
    ans[x]=lev;
    for(auto u:new_graph[x]){
        if(u==p){continue;}
        dfs_ans_cal(u,x,lev+1);
    }
}

void solve(int T){
    cin>>n;
    vector<pair<int,int>>v(n);
    for(int i=0; i<n; i++){cin>>v[i].ff>>v[i].ss;}

    for(int i=0; i<n; i++){
        graph[v[i].ff].pb(v[i].ss);
        graph[v[i].ss].pb(v[i].ff);
    }

    for(int i=0; i<=n; i++){
        parent[i]=i;   vis[i]=0;
    }

    dfs(1,-1);

    for(int i=0; i<n; i++){
        if(parent[v[i].ff]!=parent[v[i].ss]){
            new_graph[parent[v[i].ff]].pb(parent[v[i].ss]);
            new_graph[parent[v[i].ss]].pb(parent[v[i].ff]);
        }
    }
    dfs_ans_cal(connected_node_par, -1, 0);

    for(int i=1; i<=n; i++){cout<<ans[i]<<" ";}
}




//DRINK WATER
int32_t main(){
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