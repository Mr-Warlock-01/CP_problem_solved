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


const int N=5e5+7;

struct HopcroftKarp{ //O( E*sqrt(V) )
    static const int MAX = 2*40008;
    const int INF = 1<<30;
    vector<int> G[MAX];
    int n, m, match[MAX], dist[MAX];
    // n: number of nodes on left side, nodes are numbered 1 to n
    // m: number of nodes on right side, nodes are numbered n+1 to n+m
    // G = NIL[0] ? G1[G[1---n]] : G2[G[n+1---n+m]]

    void init(int N,int M){
        memset(match,0,sizeof match);
        n=N,m=M;
        for(int i=0;i<=m+n;i++)G[i].clear();
    }
    inline void addEdge(int u,int v){
        G[u].pb(v);
    }
    bool bfs() {
        queue<int> Q;
        for(int i=1; i<=n; i++) {
            if(match[i]==0) {
                dist[i] = 0;
                Q.push(i);
            }
            else dist[i] = INF;
        }
        dist[0] = INF;
        while(!Q.empty()) {
            int u = Q.front(); Q.pop();
            if(u!=0) {
                for(int v:G[u]) {
                    if(dist[match[v]]==INF) {
                        dist[match[v]] = dist[u] + 1;
                        Q.push(match[v]);
                    }
                }
            }
        }
        return (dist[0]!=INF);
    }
    bool dfs(int u) {
        if(u!=0) {
            for(int v:G[u]) {
                if(dist[match[v]]==dist[u]+1) {
                    if(dfs(match[v])) {
                        match[v] = u;
                        match[u] = v;
                        return true;
                    }
                }
            }
            dist[u] = INF;
            return false;
        }
        return true;
    }
    int bpm() {
        int matching = 0;
        while(bfs())
            for(int i=1;i<=n;i++)
                if(match[i]==0 && dfs(i))
                    matching++;
        return matching;
    }
} HK;

vector<int>p[N];
bool div_cnt[N];

void pre_cal(){
    vector<int>v(N);
    for(int i=0; i<N; i++){v[i]=i;}

    for(int i=2; i<N; i+=2){
        while(v[i]%2==0){v[i]/=2; div_cnt[i]^=1;}
        p[i].pb(2);
    }


    for(int i=3; i<N; i+=2){
        if(v[i]==i){
            for(int j=i; j<N; j+=i){
                while(v[j]%i==0){v[j]/=i; div_cnt[j]^=1;}
                p[j].pb(i);
            }
        }
    }
}



void solve(int T){
    int n;  cin>>n;
    vector<int>v(n);    cin>>v;
    
    map<int,bool>mp;
    map<int,int>mp0,mp1;
    int mod_0=0;
    int mod_1=0;

    sort(all(v));
    for(int i=0; i<n; i++){
        if(div_cnt[v[i]]){
            mp1[v[i]]=(++mod_1);
        }
        else{
            mp0[v[i]]=(++mod_0);
        }
        mp[v[i]]=1;
    }
    HK.init(mod_0, mod_1);

    for(int x:v){
        for(int z:p[x]){
            if(mp.find(x/z)==mp.end()){continue;}
            
            if(div_cnt[x]==0 && div_cnt[x/z]==1){
                HK.addEdge(mp0[x], mp1[x/z]+mod_0);
            }
            else if(div_cnt[x]==1 && div_cnt[x/z]==0){
                HK.addEdge(mp0[x/z], mp1[x]+mod_0);
            }
        }
    }

    int maxMatching = HK.bpm();
    int ans=n - maxMatching;
    cout<<"Case "<<T<<": ";
    cout<<ans<<endl;
} 



    

int32_t main(){             //DRINK WATER
    war();
    //read();   write();
    /////////////////////////////////////
    pre_cal();
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