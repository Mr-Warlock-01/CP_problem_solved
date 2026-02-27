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

const int N=2e5+7;
vector<int>graph[N];
int diameter[N];
int node=1;
int lev=0;
int node_1, node_2=0;
bool find_des=0;


void dfs(int x, int par, int depth){
    if(depth>lev){
        lev=depth;
        node=x;
    }
    for(auto u:graph[x]){
        if(u==par){continue;}
        dfs(u,x,depth+1);
    }
}

void dfs_diameter(int x, int par){
    if(x==node_2){
        find_des=1;
        diameter[x]=1;
    }

    for(auto u:graph[x]){
        if(u==par){continue;}
        if(find_des==1){break;}
        dfs_diameter(u,x);
    }
    if(find_des==1){
        diameter[x]=1;
    }
}

void clr(int n){
    for(int i=0; i<=n; i++){
        graph[i].clear();
        diameter[i]=0;
    }
    lev=0; node=1;
    node_1=node_2=0;
    find_des=0;  
}

void solve(int T){
    int n;  cin>>n;
    clr(n+3);
    for(int i=1; i<n; i++){
        int u,v;    cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1,-1,1);
    lev=0;
    dfs(node,-1,1);
    node_1=node;
    lev=0;
    dfs(node,-1,1);
    node_2=node;
    if(lev==n){IMP; return;}

    dfs_diameter(node_1,-1);
    
    int a=0,b=0,c=0;
    for(int i=1; i<=n; i++){
        if(!diameter[i]){continue;}
        int aaa=0,ccc=0;
        for(auto u:graph[i]){
            if(diameter[u]){aaa=u;}
            else{ccc=u;}
        }
        if(aaa!=0 && ccc!=0){
            a=aaa; b=i; c=ccc; break;
        }
    }

    cout<<a<<" "<<b<<" "<<c<<endl;
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