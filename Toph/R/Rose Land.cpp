// https://toph.co/arena?practice=6862589705d65920ad4de491#!/p/65d0c57258146dae37edb8b2

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
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

const int N=2e5+7;

int arr[N]; 
vector<int>graph[N];
int par[N];
vector<int>lev[20];
int sub_tree[40][N];
int treee[40][N];


void dfs1(int x, int p, int level){
    par[x]=p;
    lev[level].pb(x);
    for(auto u:graph[x]){
        if(u==p){continue;}
        dfs1(u,x,level+1);
    }
}

int dfs2(int x, int p, int time){
    if(time==0){return sub_tree[time][x]=0;}
    if(sub_tree[time][x]!=-1){return sub_tree[time][x];}
    int ans=arr[x]*time;
    for(auto u:graph[x]){
        if(u==p){continue;}
        ans+=dfs2(u, x, time-1);
    }
    return sub_tree[time][x]=ans;
}

int dfs3(int x, int p, int time){
    if(p==-1){return treee[time][x]=sub_tree[time][x];}
    if(time==0){return treee[time][x]=0;}
    if(time==1){return treee[time][x]=arr[x];}
    return treee[time][x]=sub_tree[time][x]+treee[time-1][p]-sub_tree[time-2][x];
}

void solve(int T){
    int n;  cin>>n;
    for(int i=1; i<=n; i++){cin>>arr[i];}
    for(int i=1; i<n; i++){
        int u,v;    cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    memset(sub_tree, -1, sizeof(sub_tree));
    dfs1(1, -1, 0);

    int sum=0;
    for(int i=1; i<=n; i++){
        sum+=arr[i];
        for(int j=0; j<40; j++){
            dfs2(i, par[i], j);
        }
    }
    for(int i=0; i<20; i++){
        for(auto u:lev[i]){
            for(int j=0; j<40; j++){
                dfs3(u, par[u], j);
            }
        }
    }

    int q;  cin>>q;
    while(q--){
        int u,t;    cin>>u>>t;
        int ans=0;
        if(t>=40){
            ans=treee[39][u]+((t-39)*sum);
        }
        else{
            ans=treee[t][u];
        }
        cout<<ans<<endl;
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