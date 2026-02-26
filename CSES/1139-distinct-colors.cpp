#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
using u128 = __uint128_t;
 
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
 
 
#define YES {cout<<"Yes"<<endl;}
#define NO  {cout<<"No"<<endl;}
#define IMP {cout<<"-1"<<endl;}
 
 
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE
///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE            ///MAIN CODE

//#define int ll

const int N=2e5+9;
vector<int>graph[N];
int arr[N];
int euler[N];
int in[N];
int out[N];
int n;
int timer=0;
vector<int>m_tree[4*N];
map<int,int>mp;

void dfs(int node, int par){
    timer++;
    in[node]=timer;
    euler[timer]=arr[node];
    for(auto u:graph[node]){
        if(u!=par){
            dfs(u, node);
        }
    }
    out[node]=timer;
}



void m_build(int node, int st, int en){
    if(st==en){m_tree[node].push_back(euler[st]); return;}
    int mid=((en-st)/2)+st;
    m_build(2*node, st, mid);
    m_build(2*node+1, mid+1, en);
    int i=0,j=0;
    while(i<m_tree[2*node].size() && j<m_tree[2*node+1].size()){
        if(m_tree[2*node][i] <= m_tree[2*node+1][j]){
            m_tree[node].push_back(m_tree[2*node][i]);      i++;
        }
        else{
            m_tree[node].push_back(m_tree[2*node+1][j]);    j++;
        }
    }
    while(i<m_tree[2*node].size()){
        m_tree[node].push_back(m_tree[2*node][i]);      i++;
    }
    while(j<m_tree[2*node+1].size()){
        m_tree[node].push_back(m_tree[2*node+1][j]);    j++;
    }
    return;
}

int m_query(int node, int st, int en, int l, int r, int val){
    if(st>r || en<l){return 0;}
    else if(st>=l && en<=r){
        int res= lower_bound( m_tree[node].begin(), m_tree[node].end(), val) - m_tree[node].begin();
        return res;
    }
    int mid=((en-st)/2)+st;
    int q1= m_query(2*node, st, mid, l, r, val);
    int q2= m_query(2*node+1, mid+ 1, en, l, r, val);
    return q1+q2;
}

void solve(int T){
    cin>>n;
    for(int i=1; i<=n; i++){cin>>arr[i];}
    for(int i=1; i<n; i++){
        int u,v;    cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1,-1);

    for(int i=1; i<=n; i++){
        int a=euler[i];
        euler[i]=mp[a];
        mp[a]=i;
    }

    m_build(1, 1, n);

    for(int i=1; i<=n; i++){
        int ans=m_query(1, 1, n, in[i], out[i], in[i]);
        cout<<ans<<" ";
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
