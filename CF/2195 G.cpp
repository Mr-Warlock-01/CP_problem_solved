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
const int N=3e5+7;
const int log_N=21;

vector<int>graph[N];
int LCA[log_N][N];
pair<int,int>cost[log_N][N];
int all_time[3*N];
int in_time[N];
int timer=0;

void lca_generate(int n){  
    for(int i=1; i<log_N; i++){
        for(int j=0; j<=n; j++){
            int x=LCA[i-1][j];
            if(x==-1){continue;}
            auto C=cost[i-1][j];
            C.ff+=cost[i-1][x].ff;
            C.ss+=cost[i-1][x].ss;
            x=LCA[i-1][x];
            LCA[i][j]=x;
            cost[i][j]=C;
        }
    }
return;
}

void clr(int n){
    for(int i=0; i<n; i++){
        graph[i].clear();
    }
    for(int i=0; i<log_N; i++){
        for(int j=0; j<=n; j++){ 
            LCA[i][j]=-1;
            cost[i][j]={MOD-1,N};
        }
    }
    timer=0;
}

int dfs(int x, int par, int lev){
    timer++;
    all_time[timer]=x;
    in_time[x]=timer;
    int cnt=0;
    LCA[0][x]=par;
    for(int u:graph[x]){
        cnt+=dfs(u,x,lev+1);
        timer++;
        all_time[timer]=x;
    }
    cost[0][x]={cnt+1,0};
    return cnt+2;
}

int find_ans(int node, int k){
    for(int i=log_N-1; i>=0; i--){
        if(LCA[i][node]==-1){continue;}
        int par=LCA[i][node];
        int C=cost[i][node].ff;
        if(cost[i][node].ss!=0){continue;}
        if(C<=k){
            k-=C;
            node=par;
        }
    }
    int idx=in_time[node]+k;
    return all_time[idx];
}

void solve(int T){
    int n,q;  cin>>n>>q;
    clr(n+3);
    for(int i=1; i<=n; i++){
        int a,b;    cin>>a>>b;
        if(a==0 && b==0){continue;}
        graph[i].pb(a);
        graph[i].pb(b);
        LCA[0][a]=i;
        LCA[0][b]=i;
    }

    dfs(1,-1,0);
    lca_generate(n); 
    while(q--){
        int node, k;    cin>>node>>k;
        cout<<find_ans(node,k)<<" ";
    }
    cout<<endl;
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