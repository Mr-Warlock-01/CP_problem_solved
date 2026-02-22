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

const int LLMax = 1e9;
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


typedef long long T1;//for cost
typedef long long T2;//for flow
const int maxn = 20100;
const T1 INF = 1e12;
const T2 inf = 1e12;
const T1 eps = 0;
struct Edge {
    int from, to;
    T2 cap, flow;
    T1 cost;
};
struct MCMF {//0-indexed
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int p[maxn],inq[maxn];
    T1 d[maxn];
    T2 a[maxn];
    
    void init(int n) {
        this->n = n;
        for(int i=0; i<n; i++){G[i].clear();}
        edges.clear();
    }

    void AddEdge(int from,int to,T2 cap,T1 cost){
        edges.push_back((Edge){from, to, cap, 0, cost});
        edges.push_back((Edge){to, from, 0, 0, -cost});
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    pair<T1,T2> Mincost(int s,int t){//SPFA
        T1 tot_cost = 0;
        T2 tot_flow = 0;
        while(true){
            for(int i=0; i<n; i++){d[i] = INF;}
            memset(inq, 0, sizeof(inq));
            d[s] = 0;
            inq[s] = 1;
            p[s] = 0;
            a[s] = inf;
            queue<int> Q;
            srand(time(NULL));
            Q.push(s);
            while(!Q.empty()){
                int u = Q.front();
                Q.pop();
                inq[u] = 0;
                for(int i =0; i<G[u].size(); i++){
                    Edge& e = edges[G[u][i]];
                    if(e.cap > e.flow && d[e.to] > d[u] + e.cost+eps){
                        d[e.to] = d[u] + e.cost;
                        p[e.to] = G[u][i];
                        a[e.to] = min(a[u], e.cap - e.flow);
                        if(!inq[e.to]){
                            Q.push(e.to);
                            inq[e.to] = 1;
                        }
                    }
                }
            }
            if(abs(d[t]-INF)<=eps){break;}
            tot_cost += (T1)d[t] * a[t];
            tot_flow += a[t];
            int u = t;
            while(u != s){
                edges[p[u]].flow += a[t];
                edges[p[u]^1].flow -= a[t];
                u = edges[p[u]].from;
            }
        }
        return {tot_cost,tot_flow};
    }
} mcmf;


//#define int ll
const int N=33;

pair<int,int>knight[27];
pair<int,int>mills[102];
char arr[N][N];
int knight_cap[27];

int cost[N][N];
int n;

void dijkastra(int xx, int yy){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cost[i][j]=LLMax;
        }
    }

    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>> , greater<tuple<int,int,int>>>pq;
    pq.push({0,xx,yy});
    cost[xx][yy]=0;
    while(!pq.empty()){
        auto [w, x, y]=pq.top();
        pq.pop();
        if(cost[x][y]!=w){continue;}
        for(int zz=0; zz<4; zz++){
            int _X=x+dx[zz];
            int _Y=y+dy[zz];
            if(_X<=0 || _X>n){continue;}
            if(_Y<=0 || _Y>n){continue;}
            if(arr[_X][_Y]=='#'){continue;}
            if(w+1<cost[_X][_Y]){
                cost[_X][_Y]=w+1;
                pq.push({w+1, _X, _Y});
            }
        }
    }
}

void solve(int T){
    int k,m;  cin>>n>>k>>m;
    int food=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            char c; cin>>c;
            arr[i][j]=c;
            if(c>='A' && c<='Z'){
                knight[c-'A'+1]={i,j};
            }
            else if(c=='m'){
                food++;
                mills[food]={i,j};
            }
        }
    }

    for(int i=1; i<=k; i++){
        cin>>knight_cap[i];
    }

    int source=0, sink=k+m+1;
    mcmf.init(sink+1);

    for(int i=1; i<=k; i++){
        mcmf.AddEdge(source,i,knight_cap[i],0);
    }
    for(int i=1; i<=m; i++){
        mcmf.AddEdge(k+i,sink,1,0);
    }

    for(int i=1; i<=k; i++){
        dijkastra(knight[i].ff, knight[i].ss);
        for(int j=1; j<=m; j++){
            int x=mills[j].ff;
            int y=mills[j].ss;
            if(cost[x][y]!=LLMax){
                mcmf.AddEdge(i,k+j,1,cost[x][y]);
            }
        }
    }

    cout<<"Case "<<T<<": ";
    int ANS=mcmf.Mincost(source, sink).ff; //{cost,flow};
    cout<<ANS<<endl;
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