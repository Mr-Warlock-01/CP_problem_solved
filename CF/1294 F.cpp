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

#define int ll
const int N=2e5+7;

vector<int>graph[N];
bool on_diameter[N];
int node_lev=-1,node;
stack<int>st;
int paisi=0;

void dfs(int x, int par, int lev){
    if(node_lev<lev){
        node_lev=lev;
        node=x;
    }
    for(int u:graph[x]){
        if(u==par){continue;}
        dfs(u,x,lev+1);
    }
}

void dfs_stack(int x, int par){
    st.push(x);
    if(x==node){paisi=1;}
    for(int u:graph[x]){
        if(paisi==1){return;}
        if(u==par){continue;}
        dfs_stack(u,x);
    }
    if(paisi==1){return;}
    else{st.pop();}
}

void dfs_find_3(int x, int par, int lev){
    if(node_lev<lev){
        node_lev=lev;
        node=x;
    }
    for(int u:graph[x]){
        if(u==par || on_diameter[u]){continue;}
        dfs_find_3(u,x,lev+1);
    }
}

void solve(int T){
    int n;  cin>>n;
    for(int i=1; i<n; i++){
        int u,v;    cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }   

    node_lev=-1;
    dfs(1,-1,0);
    
    node_lev=-1;
    dfs(node,-1,0);
    int ans_1=node;
    
    node_lev=-1;
    dfs(node,-1,0);
    int ans_2=node;

    int ANS=node_lev;
    node_lev=-1;
    dfs_stack(ans_1,-1);
    
    while(!st.empty()){
        on_diameter[st.top()]=1;
        st.pop();
    }

    node_lev=0, node;

    for(int i=1; i<=n; i++){
        if(on_diameter[i]){
            dfs_find_3(i, -1, 0);
        }
    }
    int ans_3;
    if(node_lev==0){
        if(1!=ans_1 && 1!=ans_2){ans_3=1;}
        else if(2!=ans_1 && 2!=ans_2){ans_3=2;}
        else{ans_3=3;}
    }
    else{
        ans_3=node;
        ANS+=node_lev;
    }
    cout<<ANS<<endl;
    cout<<ans_1<<" "<<ans_2<<" "<<ans_3;
} 



    

int32_t main(){             //DRINK WATER
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

/*

     /\_/\
    (= ._.)
    / >  \> Mr_Warlock
   /      \

*/ 