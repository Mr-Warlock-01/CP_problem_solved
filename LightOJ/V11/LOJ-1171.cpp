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
// const int N=1e6+7;

struct HopcroftKarp{ //O( E*sqrt(V) )
    static const int MAX = 40007;
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
        if(u>v){G[v].pb(u);}
        else{G[u].pb(v);}
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

const int NN=203;

int n,m;
int arr[NN][NN];
int blocked[NN][NN];

int kinght_x[] = {-2, -2, -1, -1,  1,  1,  2,  2};
int kinght_y[] = {-1,  1, -2,  2, -2,  2, -1,  1};


int node(int x, int y){
    if(x<0 | y<0){return 0;}
    if(x>=n || y>=m){return 0;}
    if(blocked[x][y]){return 0;}
    return arr[x][y];
}

void solve(int T){
    int k;    cin>>n>>m>>k;
    int white=0,black=((n*m)+1)/2;
    for(int i=0;i<n; i++){
        for(int j=0; j<m; j++){
            if((i+j)%2==0){
                arr[i][j]=(++white);
            }
            else{
                arr[i][j]=(++black);
            }
            blocked[i][j]=0;
        }
    }

    HK.init(white, black-white);

    for(int i=0; i<k; i++){
        int x,y;    cin>>x>>y;
        blocked[x-1][y-1]=1;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int u=node(i,j);
            if(u==0){continue;}
            for(int z=0; z<8; z++){
                int v=node(i+kinght_x[z], j+kinght_y[z]);
                if(v!=0){
                    HK.addEdge(u, v);
                }
            }
        }
    }

    int maxMatching = HK.bpm();
    int total=n*m;

    cout<<"Case "<<T<<": ";
    cout<<total-k-maxMatching<<endl;
} 



    

int32_t main(){             //DRINK WATER
    //war();
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