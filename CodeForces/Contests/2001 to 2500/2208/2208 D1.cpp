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
const int N=510;

bool graph[N][N];

vector<int>gra[N];
int vis_cycle[N];
bool cycle=0;

int vis[N];
 
void cycle_check(int x, int p){
    vis_cycle[x]=1;
    for(int u:gra[x]){
        if(u==p){continue;}
        if(vis_cycle[u]==1){cycle=1;}
        if(vis_cycle[u]==0){
            cycle_check(u,x);
        }
    }
    vis_cycle[x]=2;
}

void dfs(int x){
    vis[x]=1;
    for(int u:gra[x]){
        dfs(u);
    }
}


void solve(int T){
    int n;  cin>>n;
    for(int i=0; i<=n+3; i++){
        gra[i].clear();
        vis_cycle[i]=0;
        cycle=0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char a; cin>>a;
            graph[i][j]=(a=='1');
        }
    }

    vector<pair<int,int>>ans;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j){continue;}
            if(!graph[i][j]){continue;}
            
            bool f=1;
            for(int k=1; k<=n; k++){
                if((k==i) || (k==j)){continue;}
                if(graph[i][k] && graph[k][j]){
                    f=0; break;
                }
            }
            if(f){
                ans.pb({i,j});
            }
        }
    }

    int sz=ans.size();
    
    if(sz!=(n-1)){NO; return;}

    for(auto [u,v]:ans){
        gra[u].pb(v);
        gra[v].pb(u);
    }
    cycle_check(1,-1);

    if(cycle){NO; return;}

    for(int i=1; i<=n; i++){
        if(vis_cycle[i]!=2){NO; return;}
    }

    // db(vis_cycle)
    for(int i=0; i<=n+3; i++){
        gra[i].clear();
        vis_cycle[i]=0;
        cycle=0;
    }

    for(auto [u,v]:ans){
        gra[u].pb(v);
    }

    // db(gra)
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            vis[j]=0;
        }
        dfs(i);
        // db(vis)
        for(int j=1; j<=n; j++){
            if(graph[i][j]!= vis[j]){NO; return;}
        }
    }

    // db(ans)

    YES;


    for(auto [u,v]:ans){
        cout<<u<<" "<<v<<endl;
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