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

ll powMod(ll x, ll n, ll M){ll res=1; while(n){if(n&1){res=(res*x)%M;} x=(x*x)%M; n>>=1;} return res;}

#define int ll
const int N=2e5+7;


vector<int>graph[N];
pair<int,int> child_sz[N];

bool pos=1;
int  child_pair_ase=0;


int dfs(int x, int par, int lev){
    child_sz[x]={0,0};

    for(auto u:graph[x]){
        if(u==par){continue;}
        if(child_sz[x].ff==0){
            child_sz[x].ff=dfs(u,x,lev+1)+1;
        }
        else if(child_sz[x].ss==0 && child_pair_ase==0){
            child_pair_ase=x;
            child_sz[x].ss=dfs(u,x,lev+1)+1;
        }
        else{pos=0;}
    }
    return child_sz[x].ff + child_sz[x].ss;
}


void clr(int n){
    for(int i=0; i<=n; i++){
        graph[i].clear();
    }
    pos=1;
    child_pair_ase=0;
}

void solve(int T){
    int n;  cin>>n;
    clr(n+4);

    for(int i=1; i<n; i++){
        int u,v;    cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1,-1, 0);
    
    int ans;

    if(!pos){ans=0;}
    else if(child_pair_ase==0){ans=powMod(2,n,MOD);}
    else{
        if(child_sz[child_pair_ase].ff == child_sz[child_pair_ase].ss){
            int z=child_sz[child_pair_ase].ff+child_sz[child_pair_ase].ss;
            ans=powMod(2,n-z+1,MOD);
        }
        else{
            int mn=min(child_sz[child_pair_ase].ff,child_sz[child_pair_ase].ss);
            ans=(powMod(2,n-(2*mn),MOD)+ powMod(2,n-(2*mn)-1,MOD))%MOD;
        }
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