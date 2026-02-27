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

vector<pair<int,int>>graph[N];
pair<int,pair<int,int>>edge[N];

int parent[N];
int dsu_size[N];
int cost_1[N];
int cost_2[N];

int mn=LLMax, mx=0;
int n,m;    


int find_set(int x){
    if(x==parent[x]){return x;}
    return parent[x]= find_set(parent[x]);
}

void union_sets(int a, int b){
    a=find_set(a);
    b=find_set(b);
    if(dsu_size[a]<dsu_size[b]){swap(a,b);}
    parent[b]=a;
    dsu_size[a]+=dsu_size[b];
}

void min_spanning_tree(){
    sort(edge, edge+m);
    for(int i=0; i<m; i++){
        if(find_set(edge[i].ss.ff)!= find_set(edge[i].ss.ss)){
            union_sets(edge[i].ss.ff,edge[i].ss.ss);
            graph[edge[i].ss.ff].pb({edge[i].ss.ss, edge[i].ff});
            graph[edge[i].ss.ss].pb({edge[i].ss.ff, edge[i].ff});
        }
    }
}


void dfs_1(int x, int par, int cost){
    cost_1[x]=cost;
    for(auto u:graph[x]){
        if(u.ff==par){continue;}
         dfs_1(u.ff, x , max(cost, u.ss));
    }
}

void dfs_n(int x, int par, int cost){
    cost_2[x]=cost;
    for(auto u:graph[x]){
        if(u.ff==par){continue;}
         dfs_n(u.ff, x , max(cost, u.ss));
    }
}



void clr(){
    for(int i=0; i<=(n+3); i++){
        graph[i].clear();
        parent[i]=i;
        dsu_size[i]=1;
    }
    mn=LLMax, mx=0;
}

void solve(int T){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>edge[i].ss.ff>>edge[i].ss.ss>>edge[i].ff;
    }

    clr();
    min_spanning_tree();
    dfs_1(1,-1, 0);
    dfs_n(n,-1, 0);

    int ans=LLMax;
    for(int i=0; i<m; i++){
        int temp=edge[i].ff+ max({edge[i].ff, cost_1[edge[i].ss.ff], cost_2[edge[i].ss.ss]});
        temp=max(temp, edge[i].ff+ max({edge[i].ff, cost_2[edge[i].ss.ff], cost_1[edge[i].ss.ss]}));
        ans=min(ans, temp);
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