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

//#define int ll

const int N=2e5+7;

vector<int>graph[N];
pair<int,pair<int,int>>edge[N];
bool vis[N];
int vis_cycle[N];
int in[N];
stack<int>st;
int timer=1;
bool cycle=0;


void cycle_check(int x){
    vis_cycle[x]=1;
    for(int u:graph[x]){
        if(vis_cycle[u]==1){cycle=1;}
        if(vis_cycle[u]==0){
            cycle_check(u);
        }
    }
    vis_cycle[x]=2;
}


void dfs(int x){
    vis[x]=1;
    for(auto u:graph[x]){
        if(!vis[u]){
            dfs(u);
        }
    }
    st.push(x);
}

void topological_sort(int n){
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
}


void dfs_in_order(int x){
    in[x]=-1;
    for(auto u:graph[x]){
        if(in[u]!=0){continue;}
        dfs_in_order(u);
    }
    in[x]=(timer++);
}


void clr(int n){
    for(int i=0; i<n; i++){
        graph[i].clear();
        vis_cycle[i]=vis[i]=in[i]=0;
    }
    while(!st.empty()){st.pop();}
    timer=1;
    cycle=0;
}


void solve(int T){
    int n;  cin>>n;
    int m;  cin>>m;
    clr(n+5);

    for(int i=0; i<m; i++){
        cin>>edge[i].ff>>edge[i].ss.ff>>edge[i].ss.ss;
    }

    for(int i=0; i<m; i++){
        auto [ty, uv] = edge[i];
        auto [u, v] = uv;
        if(ty==1){
            graph[u].pb(v);
        }
    }

    for(int i=1; i<=n; i++){
        if(vis_cycle[i]==0){
            cycle_check(i);
        }
    }

    if(cycle){NO; return;}

    topological_sort(n);

    while(!st.empty()){
        if(in[st.top()]==0){
            dfs_in_order(st.top());
        }
        st.pop();
    }
    
    YES;
    for(int i=0; i<m; i++){
        if(edge[i].ff==0){
            if(in[edge[i].ss.ff]<in[edge[i].ss.ss]){
                swap(edge[i].ss.ff,edge[i].ss.ss);
            }
        }
        cout<<edge[i].ss.ff<<" "<<edge[i].ss.ss<<endl;
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