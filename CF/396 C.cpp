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

const int N=3e5+7;
const int M=1000000007; 

vector<int>graph[N];
int euler[N];
int in[N], out[N];
int level[N];
int timer=0;

int tree[4*N];
pair<int,int>lazy[4*N];   //{x+extra,k}


void DFS(int node, int lev){
    level[node]=lev;
    in[node]=(++timer);
    euler[timer]=node;
    for(auto u:graph[node]){
        DFS(u, lev+1);
    }
    out[node]=timer;
}


void relax(int node, int st, int en){
    if(st!=en){
        int L=2*node;
        int R=L+1;
        lazy[L].ff=(lazy[L].ff+lazy[node].ff+M)%M;
        lazy[R].ff=(lazy[R].ff+lazy[node].ff+M)%M;
        lazy[L].ss=(lazy[L].ss+lazy[node].ss+M)%M;
        lazy[R].ss=(lazy[R].ss+lazy[node].ss+M)%M;
    }
    else{
        int val_1=lazy[node].ff;
        int val_2=(level[euler[st]]*lazy[node].ss)%M;
        val_2= (M-val_2)%M;
        int val=(val_1+val_2)%M;
        tree[node]=(tree[node]+val)%M;
    }
    lazy[node]={0,0};
}


int query(int node, int st, int en, int idx){
    relax(node, st, en);
    if(st==en){return tree[node];}
    int mid=((en-st)/2)+st;
    if(idx<=mid){
        return query(2*node, st, mid, idx);
    }
    return query(2*node+1, mid+1, en, idx);
}

void update(int node, int st, int en, int l, int r, int val, int k ){
    relax(node, st, en);
    if(st>r || en<l){return;}
    else if(st>=l && en<=r){
        lazy[node].ff=val;
        lazy[node].ss=k;
        return;
    }
    int mid=((en-st)/2)+st;
    update(2*node, st, mid, l, r, val, k);
    update(2*node+1, mid+1, en, l, r, val, k);
    return;
}


void solve(int T){
    int n;  cin>>n;
    for(int i=2; i<=n; i++){
        int a;  cin>>a;
        graph[a].pb(i);
    }

    DFS(1, 0);
    int q;  cin>>q;
    while(q--){
        int type;   cin>>type;
        if(type==1){
            int v,x,k; cin>>v>>x>>k;
            update(1, 1, timer, in[v], out[v], (x+(k*level[v])%M)%M, k);
        }
        else{
            int v;  cin>>v;
            cout<<query(1, 1, timer, in[v])<<endl;
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