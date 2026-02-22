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
vector<int>rev_graph[N];
bool vis[N];
int parent[N];
stack<int>st;
int n;
bool ans=1;

int node(int x){
    if(x>0){return x+n;}
    return -x;
}

void clr(int nn){
    for(int i=0; i<=nn; i++){
        graph[i].clear();
        rev_graph[i].clear();
        vis[i]=0;
        parent[i]=i;
    }
    while(!st.empty()){st.pop();}
    ans=1;
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

void topological_sort(){  
    for(int i=1; i<=(2*n); i++){
        if(!vis[i]){
            dfs(i);
        }
    }
}

void ssc_dfs(int x, int p){
    vis[x]=1;
    parent[x]=p;
    for(auto u:rev_graph[x]){
        if(!vis[u]){
            ssc_dfs(u,p);
        }
    }
}

void SSC(){
    while(!st.empty()){
        int p=st.top();
        st.pop();
        if(!vis[p]){
            ssc_dfs(p, p);
        }
    }
}

void solve(int T){
    int m;  cin>>n>>m;
    clr(2*n+3);
    for(int i=0; i<m; i++){
        int u,v;    cin>>u>>v;
        int uu=node(-u);
        int vv=node(-v);
        u=node(u);
        v=node(v);
        graph[u].pb(vv);
        graph[v].pb(uu);
        rev_graph[vv].pb(u);
        rev_graph[uu].pb(v);
    }

    topological_sort();
    for(int i=0; i<=(2*n+3); i++){vis[i]=0;}
    SSC();

    for(int i=1; i<=n; i++){
        int x=node(i);
        if(parent[i]==parent[x]){ans=0;}
    }


    cout<<"Case "<<T<<": ";
    if(ans){YES;}
    else{NO;}
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