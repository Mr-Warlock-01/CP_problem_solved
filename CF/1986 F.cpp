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
//const ll MOD   = 1e9+7;
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

#define int ll

const int N=1e5+7;

vector<int>graph[N];
bool vis[N];
int in[N];
int low[N];
int timer;
set<pair<int,int>>bridge;

int parent[N];
int node_cnt[N];
pair<int,int>edge[N];


void bridge_find(int x, int p){
    vis[x]=1;
    in[x]=low[x]=(timer++);
    for(int i=0; i<graph[x].size(); i++){
        if(graph[x][i]==p){continue;}
        else if(vis[graph[x][i]]){
            low[x]=min(low[x], in[graph[x][i]]);
        }
        else{
            bridge_find(graph[x][i], x);
            low[x]=min(low[x], low[graph[x][i]]);
            if(low[graph[x][i]]>in[x]){
                int u=x;
                int v=graph[x][i];
                if(u>v){swap(u,v);}
                bridge.insert({u,v});
            }
        }
    }
return;
}

int dfs(int x,int p){
    parent[x]=p;
    int sz=1;
    for(int u:graph[x]){
        if(parent[u]!=-1){continue;}
        sz+=dfs(u,x);
    }
    return node_cnt[x]=sz;
}

int pair_possible(int n){
    int ans=n*(n-1);
    return (ans>>1);
}

void clr(int n){
    for(int i=0; i<n; i++){
        graph[i].clear();
        vis[i]=0;
        parent[i]=-1;
    }
    bridge.clear();
    timer=0;
}
 
void solve(int T){
    int n,m;  cin>>n>>m;
    clr(n+3);
    for(int i=0; i<m; i++){
        int u,v;    cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
        if(u>v){swap(u,v);}
        edge[i]={u,v};
    }
    bridge_find(1,-1);
    dfs(1,0);

    int ans=pair_possible(n);
    for(int i=0; i<m; i++){
        if(bridge.find(edge[i])!=bridge.end()){
            auto [u,v]=edge[i];
            if(parent[u]==v){
                ans=min(ans, pair_possible(node_cnt[u])+pair_possible(n-node_cnt[u]));
            }
            else{
                ans=min(ans, pair_possible(node_cnt[v])+pair_possible(n-node_cnt[v]));
            }
        }
    }
    cout<<ans<<endl;
}




//DRINK WATER
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
/*
     /\_/\
    (= ._.)
    / >  \> Mr_Warlock
   /      \
*/  