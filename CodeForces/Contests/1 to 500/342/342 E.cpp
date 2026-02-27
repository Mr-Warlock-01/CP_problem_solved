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

#define int ll
const int N=1e5+7;
const int log_N=20;

set<int>graph[N];
int par[N];
int sz[N];
int ans[N];
int nn=0;

int LCA[log_N+1][N];
int level[N];

void dfs_LCA(int x, int p, int lev){
    LCA[0][x]=p;
    level[x]=lev;
    for(auto u:graph[x]){
        if(u==p){continue;}
        else{
            dfs_LCA(u,x,lev+1);
        }
    }
}

void lca_generate(){  
    for(int i=1; i<log_N; i++){
        for(int j=0; j<N; j++){
            int x=LCA[i-1][j];
            if(x==-1){continue;}
            x=LCA[i-1][x];
            LCA[i][j]=x;
        }
    }
return;
}

int find_lac(int a, int b){
    if(level[a]>level[b]){swap(a,b);}
    int d=level[b]-level[a];
    while(d>0){
        int i=log2(d);
        b=LCA[i][b];
        d-=(1<<i);
    }
    if(a==b){return a;}
    for(int i=log_N-1; i>=0; i--){
        if((LCA[i][a]!=-1) && (LCA[i][a]!=LCA[i][b])){
            a=LCA[i][a];    b=LCA[i][b];
        }
    }
    return LCA[0][a];
}


int find_dis(int a, int b){
    int p=find_lac(a,b);
    return level[a]+level[b]-(2*level[p]);
}

void dfs_sz(int x,int p){
    sz[x]=1;
    nn++;
    for(auto u:graph[x]){
        if(u!=p){
            dfs_sz(u,x);
            sz[x]+=sz[u];
        }
    }
}

int dfs_centroid(int x,int p){
    for(auto u:graph[x]){
        if(u!=p && sz[u]>nn/2){
            return dfs_centroid(u,x);
        }
    }
    return x;
}

void decompose(int x,int p){
    nn=0;
    dfs_sz(x,x);
    int centroid = dfs_centroid(x,x);
    if(p==-1){p=centroid;}
    par[centroid]=p;
    for(auto u:graph[centroid]){
        graph[u].erase(centroid);
        decompose(u,centroid);
    }
    graph[centroid].clear();
}

int query(int node){
    int x=node;
    int res=LLMax;
    while(1){
        res=min(res, find_dis(node,x)+ans[x]);
        if(x==par[x]){break;}
        x=par[x];
    }
    return res;
}

void update(int node){
    int x=node;
    while(1){
        ans[x]=min(ans[x], find_dis(node,x));
        if(x==par[x]){break;}
        x=par[x];
    }
}


void solve(int T){
    int n,q;  cin>>n>>q;
    for(int i=1; i<n; i++){
        int u,v;    cin>>u>>v;
        graph[u].insert(v);
        graph[v].insert(u);
    }


    memset(LCA, -1, sizeof(LCA));
    dfs_LCA(1,-1, 0);
    lca_generate();
    decompose(1,-1);


    for(int i=1; i<=n; i++){ans[i]=LLMax;}

    update(1);
    while(q--){
        int ty;     cin>>ty;
        int node;   cin>>node;
        if(ty==1){
            update(node);
        }
        else{
            cout<<query(node)<<endl;
        }
    }    
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