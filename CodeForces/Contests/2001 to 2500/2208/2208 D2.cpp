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

// #define int ll
const int N=8009;

string s[N]; 
int cnt[N];
vector<int>graph[N];
bool vis[N];

bool cmd(int a, int b){
    return (cnt[a]<cnt[b]);
}


struct DSU{
    vector<int>par,sz;
    int c;

    DSU(){}
    DSU(int n) : par(n+1), sz(n+1,1), c(n){
        for(int i=1; i<=n; ++i){
            par[i]=i;
        }
    }

    void re_size(int n){
        for(int i=1; i<=n; ++i){
            par[i]=i;
            sz[i]=1;
        }
        c=n;
    }

    int find(int i){
        return (par[i]==i ? i : (par[i]=find(par[i])));
    }

    bool same(int i,int j){
        return find(i)==find(j);
    }

    int get_size(int i){
        return sz[find(i)];
    }

    int count(){return c;}

    int merge(int i,int j){
        if((i=find(i))==(j=find(j))){return 0;}
        else --c;
        if(sz[i]<sz[j]){swap(i,j);}
        par[j]=i;
        sz[i]+=sz[j];
        return i;
    }
}dsu(N);

vector<pair<int,int>>ans;

void clr(int n){
    ans.clear();
    for(int i=0; i<=n; i++){
        graph[i].clear();
        cnt[i]=0;
    }
}

void dfs(int x){
    while(graph[x].size()!=0){
        int sz=graph[x].size()-1;
        int last=graph[x][sz];
        graph[x].pop_back();
        if(!dsu.same(x,last)){
            dsu.merge(x,last);
            ans.pb({x,last});
            dfs(last);
        }   
    }
}

void dfs_check(int x){
    vis[x]=1;
    for(int u:graph[x]){
        dfs_check(u);
    }
}



void solve(int T){
    int n;  cin>>n;
    clr(n+2);
    dsu.re_size(n);

    for(int i=1; i<=n; i++){
        cin>>s[i];
        for(int j=0; j<n; j++){
            if(s[i][j]=='1'){
                cnt[i]++;
                graph[i].pb(j+1);
            }
        }
    }

    for(int i=1; i<=n; i++){
        sort(all(graph[i]),cmd);
    }

    for(int i=1; i<=n; i++){
        dfs(i);
    }
 
    for(auto [u,v]:ans){
        graph[u].pb(v);
    }

    if(dsu.count()!=1){NO; return;}

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            vis[j]=0;
        }
        dfs_check(i);
        for(int j=1; j<=n; j++){
            if((s[i][j-1]-'0')!= vis[j]){NO; return;}
        }
    }



    YES;
    for(auto [u,v]: ans){
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