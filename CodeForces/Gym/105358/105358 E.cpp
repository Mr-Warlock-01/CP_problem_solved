#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;
//using u128 = __uint128_t;
//using i128 = __int128_t;

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
const int N=2e5+9;

vector<int>graph[N];
int dead_time[N][2];
int reach_time[N][2];
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>ppppq;

void clr(int n){
    for(int i=0; i<n; i++){
        graph[i].clear();
        dead_time[i][0]=LLMax;
        dead_time[i][1]=LLMax+1;
        reach_time[i][0]=LLMax;
        reach_time[i][1]=LLMax+1;
    }
    while(!ppppq.empty()){ppppq.pop();}
}

int n,d;
void cal_dead_time(){
    while(!ppppq.empty()){
        int time=ppppq.top().ff;
        int node=ppppq.top().ss;
        ppppq.pop();
        if(time>=d){continue;}
        bool side=time%2;
        if(dead_time[node][side]<time){continue;}
        bool next_side=side^1;
        for(int u:graph[node]){
            if(dead_time[u][next_side]>time+1){
                dead_time[u][next_side]=time+1;
                ppppq.push({time+1, u});
            }
        }
    }
}

int cal_ans(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    reach_time[1][0]=0;
    pq.push({0,1});
    while(!pq.empty()){
        int time=pq.top().ff;
        int node=pq.top().ss;
        pq.pop();
        bool side=time%2;
        if(reach_time[node][side]<time){continue;}
        bool next_side=side^1;
        for(int u:graph[node]){
            if(time+1<dead_time[u][next_side]){
                assert((time+1)%2 == dead_time[u][next_side]%2);
                if(reach_time[u][next_side]>time+1){
                    reach_time[u][next_side]=time+1;
                    pq.push({time+1,u});
                }
            }
        }
    }
    return min(reach_time[n][0],reach_time[n][1]);
}



void solve(int T){
    int m;  cin>>n>>m>>d;
    clr(n+5);
    for(int i=0; i<m; i++){
        int u,v;    cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    int k;  cin>>k;
    for(int i=0; i<k; i++){
        int a;  cin>>a;
        dead_time[a][0]=0;
        ppppq.push({0,a});
    }

    cal_dead_time();

    // db(reach_time)
    
    int time=cal_ans();
    if(time==LLMax){IMP; return;}
    int node=n;
    stack<int>st;
    st.push(n);
    while(time!=0){
        int pre_time=time-1;
        bool pre_side=pre_time%2;
        for(int u: graph[node]){
            if(reach_time[u][pre_side]==pre_time){
                st.push(u);
                node=u;
                time=pre_time;
                break;
            }
        }
    }

    // db(dead_time)


    cout<<min(reach_time[n][0],reach_time[n][1])<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
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