#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
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
template<typename T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
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

const int N=2e5+7;
const int log_N=log(N)+2;

vector<int>graph[N];
int cost[N];
int LCA[log_N+1][N];
int level[N];
int euler_arr[2*N];
int in[N];
int out[N];
int treee[8*N];

int timer=1;

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

void dfs(int x, int p, int lev){
    LCA[0][x]=p;
    level[x]=lev;
    euler_arr[timer]=cost[x];
    in[x]=(timer++);

    for(int u:graph[x]){
        if(u==p){continue;}
        dfs(u, x, lev+1);
    }
    euler_arr[timer]=-cost[x];
    out[x]=(timer++);
}

void build(int node, int st, int en){
    if(st==en){  treee[node] = euler_arr[st]; return;}
    int mid=((en-st)/2)+st;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    treee[node]=treee[2*node]+treee[2*node+1];
    return;
}

int query(int node, int st, int en, int l, int r){
    if(st>r || en<l){return 0;}
    else if(st>=l && en<=r){return treee[node];}
    int mid=((en-st)/2)+st;
    int q1= query(2*node, st, mid, l, r);
    int q2= query(2*node+1, mid+ 1, en, l, r);
    return q1+q2;
}

void update(int node, int st, int en, int ind, int val){
    if(st==en){treee[node]=val;   return;}
    int mid=((en-st)/2)+st;
    if(st<=ind && mid>=ind){update(2*node,st, mid, ind, val);}
    else{update(2*node+1, mid+1, en, ind, val);}
    treee[node]=treee[2*node] + treee[2*node+1];
    return;
}

void solve(int T){
    int n,q;    cin>>n>>q;
    for(int i=1; i<=n; i++){
        cin>>cost[i];
    }
    for(int i=1; i<n; i++){
        int u,v;    cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    memset(LCA, -1, sizeof(LCA));
    dfs(1, -1, 0);
    lca_generate();
    build(1, 1, timer);

    while(q--){
        int ty; cin>>ty;
        if(ty==1){  
            int node, val;  cin>>node>>val;
            update(1, 1, timer, in[node], val);
            update(1, 1, timer, out[node], -val);

        }
        else{
            int u; cin>>u;
            int ans=query(1, 1, timer, 1, in[u]);
            cout<<ans<<endl;
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