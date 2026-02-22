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
// *    .find_by_order(x)
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
//const int N=107;


const int INF = 2000000000;
struct Edge{
    int from, to, cap, flow, index;
    Edge(int from, int to, int cap, int flow, int index):
        from(from), to(to), cap(cap), flow(flow), index(index){}
};

struct Dinic{
    int N;
    vector<vector<Edge>>G;
    vector<Edge*>dad;
    vector<int>Q;
    Dinic(int N) : N(N), G(N), dad(N), Q(N){}
    
    void AddEdge(int from, int to, int cap){
        G[from].emplace_back(from, to, cap, 0, G[to].size());
        if(from==to){G[from].back().index++;}
        G[to].emplace_back(to, from, 0, 0, G[from].size()-1);
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


const int N=202;
int t[N],b[N],t_b[N];
int con_A[N*N];
int con_B[N*N];
int con_cost[N*N];

void solve(int T){
    int n,m;  cin>>n>>m;
   
    for(int i=1; i<=n; i++){cin>>t[i];}
    for(int i=1; i<=n; i++){cin>>b[i];}
    for(int i=1; i<=n; i++){cin>>t_b[i];}

    for(int i=1; i<=m; i++){
        cin>>con_A[i]>>con_B[i]>>con_cost[i];
    }

    int source=0, sink=n+1;
    Dinic *mr_warlock=new Dinic(sink+1);

    for(int i=1; i<=n; i++){
        mr_warlock->AddEdge(source,i,  t_b[i]!=-1? t[i]:INF);
        mr_warlock->AddEdge(i,sink,t_b[i]!=1? b[i]:INF);
    }

    for(int i=1; i<=m; i++){
        mr_warlock->AddEdge(con_A[i],con_B[i], con_cost[i]);
        mr_warlock->AddEdge(con_B[i],con_A[i], con_cost[i]);
    }

    int ans=mr_warlock->GetMaxFlow(source,sink);
    delete(mr_warlock);
    cout<<"Case "<<T<<": ";
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