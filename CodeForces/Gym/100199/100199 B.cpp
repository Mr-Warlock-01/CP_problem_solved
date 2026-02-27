/*CODE !*/
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


const int INF = 2000000000;
struct Edge{
    int from, to, cap, flow, index, idx;
    Edge(int from, int to, int cap, int flow, int index, int idx):
        from(from), to(to), cap(cap), flow(flow), index(index), idx(idx){}
};

struct Dinic{
    int N;
    vector<vector<Edge>>G;
    vector<Edge*>dad;
    vector<int>Q;
    Dinic(int N) : N(N), G(N), dad(N), Q(N){}
    
    void AddEdge(int from, int to, int cap, int idx){
        G[from].emplace_back(from, to, cap, 0, G[to].size(), idx);
        if(from==to){G[from].back().index++;}
        G[to].emplace_back(to, from, 0, 0, G[from].size()-1, 0);
    }

    long long BlockingFlow(int s, int t) {
        fill(dad.begin(), dad.end(), (Edge*) NULL);
        dad[s] = &G[0][0] - 1;
        int head=0, tail=0;
        Q[tail++]=s;
        while(head<tail){
            int x=Q[head++];
            for(int i=0; i<G[x].size(); i++){
                Edge &e = G[x][i];
                if((!dad[e.to]) && ((e.cap-e.flow)>0)){
                    dad[e.to] = &G[x][i];
                    Q[tail++] = e.to;
                }
            }
        }
        if(!dad[t]){return 0;}
        long long totflow=0;
        for(int i=0; i<G[t].size(); i++){
            Edge *start = &G[G[t][i].to][G[t][i].index];
            int amt = INF;
            for(Edge *e=start; amt && (e!=dad[s]); e=dad[e->from]){
                if(!e){amt=0; break;}
                amt=min(amt, e->cap - e->flow);
            }
            if(amt==0){continue;}
            for(Edge *e=start; amt && (e!=dad[s]); e=dad[e->from]){
                e->flow += amt;
                G[e->to][e->index].flow -= amt;
            }
            totflow+=amt;
        }
        return totflow;
    }

    long long GetMaxFlow(int s, int t) {
        long long totflow = 0;
        while(long long flow = BlockingFlow(s, t)){
            totflow += flow;
        }
        return totflow;
    }
};




int ans[50000];

void cal_ans(const Dinic &dinic) {
    for (int u = 0; u < dinic.N; ++u) {
        for (const Edge &e : dinic.G[u]) {
            if(e.idx!=0){
                ans[e.idx]+=e.flow;
            }
        }
    }
}


void solve(int T){
    int n,m;  cin>>n>>m;
    int dummy_source=0;
    int dummy_sink=n+1;
    Dinic *mr_warlock=new Dinic(n+2);

    int sum=0;
    for(int i=1; i<=m; i++){
        int u,v,l,h;    cin>>u>>v>>l>>h;
        sum+=l;
        ans[i]=l;
        mr_warlock->AddEdge(u,v,h-l,i);
        mr_warlock->AddEdge(u,dummy_sink,l,0);
        mr_warlock->AddEdge(dummy_source,v,l,0);
    }
    
    int z=mr_warlock->GetMaxFlow(dummy_source,dummy_sink);
    
    if(sum!=z){NO; return;}
    cal_ans(*mr_warlock);
    
    YES;
    for(int i=1; i<=m; i++){
        cout<<ans[i]<<endl;
    }

}       
  
 
 
 
//DRINK WATER
int32_t main(){
    war();
    read();   write();
    /////////////////////////////////////
 
    /////////////////////////////////////
    int tc=1;
    //cin>>tc;
    for(int T=1; T<=tc; T++){
        solve(T);
    }
return 0;
}















/*CODE 2*/
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


const long long inf = 1LL << 61;
struct Dinic {
    struct edge {int to, rev; long long flow, w; int id;};
    int n, s, t, mxid;
    vector<int> d, flow_through; vector<int> done;
    vector<vector<edge>>g;
    Dinic() {}
    Dinic(int _n) {
        n = _n + 10; mxid = 0;
        g.resize(n);
    }
    void AddEdge(int u, int v, long long w, int id = -1) {
        edge a = {v, (int)g[v].size(), 0, w, id};
        edge b = {u, (int)g[u].size(), 0, 0, -1};//for bidirectional edges cap(b) = w
        g[u].emplace_back(a);
        g[v].emplace_back(b);
        mxid = max(mxid, id);
    }
    bool bfs() {
        d.assign(n, -1); d[s] = 0;
        queue<int> q; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &e: g[u]) {
                int v = e.to;
                if (d[v] == -1 && e.flow < e.w) d[v] = d[u] + 1, q.push(v);
            }
        }
        return d[t] != -1;
    }
    long long dfs(int u, long long flow) {
        if (u == t) return flow;
        for (int &i = done[u]; i < (int)g[u].size(); i++) {
            edge &e = g[u][i];
            if (e.w <= e.flow) continue;
            int v = e.to;
            if (d[v] == d[u] + 1) {
                long long nw = dfs(v, min(flow, e.w - e.flow));
                if (nw > 0) {
                    e.flow += nw;
                    g[v][e.rev].flow -= nw;
                    return nw;
                }
            }
        }
        return 0;
    }
    long long max_flow(int _s, int _t) {
        s = _s; t = _t;
        long long flow = 0;
        while (bfs()) {
            done.assign(n, 0);
            while (long long nw = dfs(s, inf)) flow += nw;
        }
        flow_through.assign(mxid + 10, 0);
        for(int i = 0; i < n; i++) for(auto e: g[i]) if(e.id >= 0) flow_through[e.id] = e.flow;
        return flow;
    }
};

struct LR_Flow {
    Dinic F;
    int n, s, t;
    struct edge {int u, v, l, r, id;};
    vector<edge> edges;
    LR_Flow() {}
    LR_Flow(int _n) {
        n = _n + 10; s = n - 2, t = n - 1;;
        edges.clear();
    }
    void AddEdge(int u, int v, int l, int r, int id = -1) {
        assert(0 <= l && l <= r);
        edges.push_back({u, v, l, r, id});
    }
    bool feasible(int _s = -1, int _t = -1, int L = -1, int R = -1) {
        if (L != -1) edges.push_back({_t, _s, L, R, -1});
        F = Dinic(n);
        long long target = 0;
        for (auto e: edges) {
            int u = e.u, v = e.v, l = e.l, r = e.r, id = e.id;
            if (l != 0) {
                F.AddEdge(s, v, l);
                F.AddEdge(u, t, l);
                target += l;
            }
            F.AddEdge(u, v, r - l, id);
        }
        auto ans = F.max_flow(s, t);
        if (L != -1) edges.pop_back();
        if (ans < target) return 0; //not feasible
        return 1;
   }
   int max_flow(int _s, int _t) { //-1 means flow is not feasible
        int mx = 1e9;
        int ans = -1, l = 0, r = mx;
        while (l <= r) {
            int mid = l + r >> 1;
            if (feasible(_s, _t, mid, mx)) ans = mid, l = mid + 1;
            else r = mid - 1;
        }
        return ans;
   }   
   int min_flow(int _s, int _t) { //-1 means flow is not feasible
        int mx = 1e9;
        int ans = -1, l = 0, r = mx;
        while (l <= r) {
            int mid = l + r >> 1;
            if (feasible(_s, _t, 0, mid)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        return ans;
   }
};

int ans[50000];

void solve(int T){
    int n,m;    cin>>n>>m;
    LR_Flow mr_warlock(n+1);
    for(int i=1; i<=m; i++){
        int u,v,l,h;    cin>>u>>v>>l>>h;
        ans[i]=l;
        mr_warlock.AddEdge(u,v,l,h,i);
    }

    bool ok = mr_warlock.feasible();
    if (!ok){NO; return;}
    for(int i=1; i<=m; i++){
        ans[i]+=mr_warlock.F.flow_through[i];
    }
    YES;
    for(int i=1; i<=m; i++){
        cout<<ans[i]<<endl;
    }
}       
  
 
 
 
//DRINK WATER
int32_t main(){
    war();
    read();   write();
    /////////////////////////////////////
 
    /////////////////////////////////////
    int tc=1;
    //cin>>tc;
    for(int T=1; T<=tc; T++){
        solve(T);
    }
return 0;
}
