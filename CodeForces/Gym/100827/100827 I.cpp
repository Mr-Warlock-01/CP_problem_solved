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
const int N=1e6+7;

vector<int>graph[N];
int in[N],out[N];
int salary[N];
int arr[N];

int timer=0;

void clr(int n){
    for(int i=0; i<n; i++){
        graph[i].clear();
    } 
    timer=0;
}

void dfs(int x){
    timer++;
    in[x]=timer;
    arr[timer]=salary[x];
    for(int u:graph[x]){
        dfs(u);
    }
    out[x]=timer;
}

int mn_tree[4*N];
int mx_tree[4*N];
int lazy[4*N];

void lazy_build(int node, int st, int en){   //same as normal segment tree
    if(st==en){  mx_tree[node]=mn_tree[node]=arr[st]; lazy[node]=0;return;}
    int mid=((en-st)/2)+st;
    lazy_build(2*node, st, mid);
    lazy_build(2*node+1, mid+1, en);
    mn_tree[node]=min(mn_tree[2*node],mn_tree[2*node+1]);
    mx_tree[node]=max(mx_tree[2*node],mx_tree[2*node+1]);
    lazy[node]=0;
    return;
}

void relax(int node, int st, int en){
    if(lazy[node]!=0){
        mn_tree[node]+=lazy[node];
        mx_tree[node]+=lazy[node];
        if(st!=en){ lazy[2*node]+=lazy[node];   lazy[2*node+1]+=lazy[node];}
        lazy[node]=0;
    }
}

pair<int,int> lazy_query(int node, int st, int en, int l, int r){  //mx,mn
    relax(node, st, en);
    if(st>r || en<l){return {LLMin,LLMax};}
    else if(st>=l && en<=r){return {mx_tree[node],mn_tree[node]};}
    int mid=((en-st)/2)+st;
    auto q1= lazy_query(2*node, st, mid, l, r);
    auto q2= lazy_query(2*node+1, mid+ 1, en, l, r);
    return {max(q1.ff,q2.ff),min(q1.ss,q2.ss)};
}

void lazy_update(int node, int st, int en, int l, int r, int val){
    relax(node, st, en);
    if(st>r || en<l){return;}
    else if(st>=l && en<=r){
        mn_tree[node]+=val;
        mx_tree[node]+=val;
        if(st!=en){ lazy[2*node]+=val;   lazy[2*node+1]+=val;}
        return;
    }
    int mid=((en-st)/2)+st;
    lazy_update(2*node, st, mid, l, r, val);
    lazy_update(2*node+1, mid+1, en, l, r, val);
    mn_tree[node]=min(mn_tree[2*node],mn_tree[2*node+1]);
    mx_tree[node]=max(mx_tree[2*node],mx_tree[2*node+1]);
    return;
}

void solve(int T){
    int n;  cin>>n;
    clr(n+5);
    for(int i=2; i<=n; i++){
        int a;  cin>>a;
        graph[a].pb(i);
    }

    for(int i=1; i<=n; i++){cin>>salary[i];}

    dfs(1);
    lazy_build(1, 1, timer);

    int q;  cin>>q;
    while(q--){
        char c; cin>>c;
        if(c=='Q'){
            int node;   cin>>node;
            auto zzz=lazy_query(1, 1, timer, in[node],out[node]);
            cout<<zzz.ff-zzz.ss<<endl;
        }
        else{
            int node,val;   cin>>node>>val;
            lazy_update(1, 1, timer, in[node] ,out[node], val);
        }

    }

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