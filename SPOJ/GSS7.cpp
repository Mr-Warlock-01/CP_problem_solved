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
const int log_N=20;

int arr[N];
vector<int>graph[N];

int LCA[log_N][N];
int level[N];

int head[N];
int sub_child_sz[N];
int in[N];
int out[N];
int euler_arr[N];

pair<pair<int,int>,pair<int,int>>treee[4*N];    //{ans,sum},{left,right}
pair<int,bool>lazy[4*N]; //val, flag

int timer=0;

void build(int node, int st, int en){
    if(st==en){
        treee[node].ff.ff=max(euler_arr[st],0ll);
        treee[node].ff.ss=euler_arr[st];
        treee[node].ss.ff=max(euler_arr[st],0ll);
        treee[node].ss.ss=max(euler_arr[st],0ll);
        return;
    }
    int mid=((en-st)/2)+st;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    treee[node].ff.ff=max({treee[2*node].ff.ff, treee[2*node+1].ff.ff, treee[2*node].ss.ss+ treee[2*node+1].ss.ff});
    treee[node].ff.ss=treee[2*node].ff.ss+treee[2*node+1].ff.ss;
    treee[node].ss.ff=max(treee[2*node].ss.ff, treee[2*node].ff.ss+treee[2*node+1].ss.ff);
    treee[node].ss.ss=max(treee[2*node+1].ss.ss, treee[2*node+1].ff.ss+treee[2*node].ss.ss);
}

void relax(int node, int st, int en){
    if(lazy[node].ss==1){
        treee[node].ff.ff=max(0ll, (en-st+1)*lazy[node].ff);
        treee[node].ff.ss=(en-st+1)*lazy[node].ff;
        treee[node].ss.ff=max(0ll, (en-st+1)*lazy[node].ff);
        treee[node].ss.ss=max(0ll, (en-st+1)*lazy[node].ff);
        lazy[2*node]=lazy[node];
        lazy[2*node+1]=lazy[node];
        lazy[node]={0,0};
    }
}

pair<pair<int,int>,pair<int,int>> lazy_query(int node, int st, int en, int l, int r){
    relax(node, st, en);
    if(st>r || en<l){return {{LLMin,0},{LLMin,LLMin}};}
    else if(st>=l && en<=r){return treee[node];}
    int mid=((en-st)/2)+st;
    pair<pair<int,int>,pair<int,int>> q1= lazy_query(2*node, st, mid, l, r);
    pair<pair<int,int>,pair<int,int>> q2= lazy_query(2*node+1, mid+ 1, en, l, r);

    int ans=max({q1.ff.ff, q2.ff.ff, q1.ss.ss+q2.ss.ff});
    int sum=q1.ff.ss+q2.ff.ss;
    int left=max(q1.ss.ff, q1.ff.ss+q2.ss.ff);
    int right=max(q2.ss.ss, q2.ff.ss+q1.ss.ss);
    return {{ans,sum},{left,right}};
}

void lazy_update(int node, int st, int en, int l, int r, int val){
    relax(node, st, en);
    if(st>r || en<l){return;}
    else if(st>=l && en<=r){
        treee[node].ff.ff=max(0ll, (en-st+1)*val);
        treee[node].ff.ss=(en-st+1)*val;
        treee[node].ss.ff=max(0ll, (en-st+1)*val);
        treee[node].ss.ss=max(0ll, (en-st+1)*val);
        if(st!=en){
            lazy[2*node]={val,1};
            lazy[2*node+1]={val,1};
        }
        return;
    }
    int mid=((en-st)/2)+st;
    lazy_update(2*node,st, mid, l, r, val);
    lazy_update(2*node+1, mid+1, en, l, r, val);
    treee[node].ff.ff=max({treee[2*node].ff.ff, treee[2*node+1].ff.ff, treee[2*node].ss.ss+ treee[2*node+1].ss.ff});
    treee[node].ff.ss=treee[2*node].ff.ss+treee[2*node+1].ff.ss;
    treee[node].ss.ff=max(treee[2*node].ss.ff, treee[2*node].ff.ss+treee[2*node+1].ss.ff);
    treee[node].ss.ss=max(treee[2*node+1].ss.ss, treee[2*node+1].ff.ss+treee[2*node].ss.ss);
    return;
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
        if(u==par){continue;}
        dfs(u, x, lev+1);
        sub_child_sz[x]+=sub_child_sz[u];
        if(sub_child_sz[u]>sub_child_sz[graph[x][0]]){
            swap(u, graph[x][0]);
        }
    }
}

void HLD_dfs(int x, int par){
    if(par==-1){head[x]=x;}
    in[x]=(++timer);
    euler_arr[timer]=arr[x];
    for(auto u:graph[x]){
        if(u==par){continue;}
        if(u==graph[x][0]){head[u]=head[x];} 
        else{head[u]=u;}
        HLD_dfs(u,x);
    }
    out[x]=timer;
}

pair<pair<int,int>,pair<int,int>>MERGE_LR( pair<pair<int,int>,pair<int,int>>q1, pair<pair<int,int>,pair<int,int>>q2){
    int ans=max({q1.ff.ff, q2.ff.ff, q1.ss.ss+q2.ss.ff});
    int sum=q1.ff.ss+q2.ff.ss;
    int left=max(q1.ss.ff, q1.ff.ss+q2.ss.ff);
    int right=max(q2.ss.ss, q2.ff.ss+q1.ss.ss);
    return {{ans,sum},{left,right}};
}

pair<pair<int,int>,pair<int,int>>query_chain(int par,int u){
    pair<pair<int,int>,pair<int,int>>res={{0,0},{0,0}};
    int h=-1;
    while(h!=par){
        h=head[u];
        if(level[h]<level[par]){h=par;}
        res=MERGE_LR(lazy_query(1,1,timer,in[h],in[u]),res);
        u=LCA[0][h];
    }
    return res;
}

void update_chain(int par,int u,int val){
    int h=-1;
    while(h!=par){
        h=head[u];
        if(level[h]<level[par]){h=par;}
        lazy_update(1,1,timer,in[h],in[u],val);
        u=LCA[0][h];
    }
}

void update_path(int u,int v, int val){
    int par=find_lac(u,v);
    update_chain(par,u,val);
    update_chain(par,v,val);
}


void solve(int T){
    int n;  cin>>n;
    for(int i=1; i<=n; i++){cin>>arr[i];}
    for(int i=1; i<n; i++){
        int u,v;    cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    memset(LCA, -1, sizeof(LCA));
    dfs(1,-1, 0);
    HLD_dfs(1, -1);
    lca_generate();
    build(1,1,timer);
    
    int q;  cin>>q;
    while(q--){
        int t,u,v;  cin>>t>>u>>v;
        if(level[u]>level[v]){swap(u,v);}
        if(t==1){
            int par=find_lac(u,v);
            if(par==u){
                cout<<query_chain(u,v).ff.ff<<endl;
            }
            else{
                if(in[u]>in[v]){swap(u,v);}
                pair<pair<int,int>,pair<int,int>>q1=query_chain(par,u);
                swap(q1.ss.ff,q1.ss.ss);
                pair<pair<int,int>,pair<int,int>>q2=query_chain(find_nth_parent(v,level[v]-level[par]-1),v);
                cout<<MERGE_LR(q1,q2).ff.ff<<endl;
            } 
        }
        else{//update
            int val;    cin>>val; 
            update_path(u,v,val);
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
    //cin>>tc;
    for(int T=1; T<=tc; T++){
        solve(T);
    }
return 0;
}