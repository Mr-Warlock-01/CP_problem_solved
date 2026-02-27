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
const ll MOD   = 1e9+7;
const double PI = acos(-1);       //3.1415926535897932384626

int dx[] = {-1, 1,  0, 0, -1, -1,  1, 1};
int dy[] = { 0, 0, -1, 1, -1,  1, -1, 1};

//pbds
template<typename T>using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
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
const int N=1e5+7;

vector<pair<int,int>>graph[N];
vector<int>police;
bool boster[N];

int cost_police[2][N];
int cost_thief[N];
int source,destination; 


void dijkastra_police(){
    for(int i=0; i<N; i++){cost_police[1][i]=cost_police[0][i]=LLMax;}
    priority_queue<tuple<int,int,bool>, vector<tuple<int,int,bool>>, greater<tuple<int,int,bool>>>pq;
    //cost,node, bost

    for(int u: police){
        cost_police[boster[u]][u]=0;
        pq.push({0,u,boster[u]});
    }

    while(!pq.empty()){
        auto [cost, node, fast]=pq.top();
        pq.pop();
        if(cost>cost_police[fast][node]){continue;}
        for(auto [u,w]: graph[node]){
            int new_cost=cost;
            new_cost+=w/2;
            if(!fast){new_cost+=w/2;}
            if(cost_police[fast][u]>new_cost){
                cost_police[fast][u]=new_cost;
                pq.push({new_cost,u,fast|boster[u]});
            }
        }
    }
}

void dijkastra_theif(){
    for(int i=0; i<N; i++){cost_thief[i]=LLMax;}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    //cost,node

    cost_thief[source]=0;
    pq.push({0,source});

    while(!pq.empty()){
        auto [cost, node]=pq.top();
        pq.pop();
        if(cost!=cost_thief[node]){continue;}
        for(auto [u,w]: graph[node]){
            int new_cost=cost+w;
            if(cost_thief[u]>new_cost){
                cost_thief[u]=new_cost;
                pq.push({new_cost,u});
            }
        }
    }
}




void solve(int T){
    int n,m;    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v,w;    cin>>u>>v>>w;
        w*=2;
        graph[u].pb({v,w});
        graph[v].pb({u,w});
    }
    int k;  cin>>k;
    for(int i=0; i<k; i++){
        int a;  cin>>a;
        police.pb(a);
    }
    cin>>k;
    for(int i=0; i<k; i++){
        int a;  cin>>a;
        boster[a]=1;
    }

    cin>>source>>destination;

    dijkastra_police();
    dijkastra_theif();
    //cout<<cost_police[1][destination]/2<<endl;
    //cout<<cost_thief[destination]/2<<endl;
    if(min(cost_police[0][destination], cost_police[1][destination])<=cost_thief[destination]){IMP;}
    else{
        cout<<cost_thief[destination]/2<<endl;
    }
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