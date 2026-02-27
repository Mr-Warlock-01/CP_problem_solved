#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
//using namespace __gnu_pbds;
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
// *    .find_by_order(x)
//substr
//cin.ignore();
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
const int N=1e4+7;
const int log_N=16;

vector<pair<int,int>>graph[N];
pair<int,int>edge[N];
//LCS
int LCA[log_N][N];
int level[N];
int treee[4*N];
//hld
int head[N];
int sub_child_sz[N];
int in[N];
int euler_arr[N];

int timer=0;
int n;

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


void lca_generate(){  
    for(int i=1; i<log_N; i++){
        for(int j=1; j<=n; j++){  //change here
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

int find_nth_parent(int x, int n){
    while(n){
        int z=log2(n);
        n-=(1<<z);
        x=LCA[z][x];
        if(x==-1){break;}
    }
    return x;
}

void dfs(int x, int par, int lev){
    level[x]=lev;
    LCA[0][x]=par;
    sub_child_sz[x]=1;
    for(auto &u: graph[x]){
        if(u.ff==par){continue;}
        dfs(u.ff, x, lev+1);
        sub_child_sz[x]+=sub_child_sz[u.ff];
        if(sub_child_sz[u.ff]>sub_child_sz[graph[x][0].ff]){
            swap(u, graph[x][0]);
        }
    }
}

void HLD_dfs(int x, int par, int cost){
    if(par==-1){head[x]=x;}
    in[x]=(++timer);
    euler_arr[timer]=cost;
    for(auto u:graph[x]){
        if(u.ff==par){continue;}
        if(u.ff==graph[x][0].ff){head[u.ff]=head[x];} 
        else{head[u.ff]=u.ff;}
        HLD_dfs(u.ff,x,u.ss);
    }
}

int query_chain(int par,int u){
    int h=-1,res=0;
    while(h!=par){
        h=head[u];
        if(level[h]<level[par]){h=par;}
        res+=query(1,1,timer,in[h],in[u]);
        u=LCA[0][h];
    }
    return res;
}

int query_path(int u,int v){
    int par=find_lac(u,v);
    int res=query_chain(par,u)+query_chain(par,v);
    res-=2*query_chain(par,par);
    return res;
}

void clr(){
    timer=0;
    for(int i=0; i<=n; i++){graph[i].clear();}
    
    for(int i=0; i<log_N; i++){
        for(int j=0; j<=n; j++){
            LCA[i][j]=-1;
        }
    }
}

void solve(int T){
    cin>>n;
    clr();
    for(int i=1; i<n; i++){
        int u,v,w;  cin>>u>>v>>w;
        graph[u].pb({v,w});
        graph[v].pb({u,w});
        edge[i]={u,v};
    }
    dfs(1,-1, 0);
    HLD_dfs(1, -1, 0);
    lca_generate();
    build(1,1,timer);
    while(1){
        string s;   cin>>s;
        if(s=="DONE"){break;}
        else if(s=="DIST"){
            int u,v;    cin>>u>>v;
            int ans=query_path(u,v);
            cout<<ans<<endl;
        }
        else{
            int u,v,k;    cin>>u>>v>>k;
            int par=find_lac(u,v);
            int ans;
            if((level[u]-level[par]+1)>=k){
                ans=find_nth_parent(u,k-1);
            }
            else{
                k-=level[u]-level[par]+1;
                ans=find_nth_parent(v,level[v]-level[par]-k);
            }
            cout<<ans<<endl;
        }
    }
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