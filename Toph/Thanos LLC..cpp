// https://toph.co/p/thanos-llc

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

const int N=2e5+7;
vector<int>graph[N];
vector<int>rev_graph[N];
bool vis[N];
int parent[N];
stack<int>st;
vector<int>new_graph[N];
int timer=0;

int income_arr[N];

ordered_set<pair<int,int>>os[N];

int component_add[N];
pair<int,int>component_info[N]; //max,cnt;
pair<int,int>treee[4*N];

void dfs(int x){
    vis[x]=1;
    for(auto u:graph[x]){
        if(!vis[u]){
            dfs(u);
        }
    }
    st.push(x);
}

void topological_sort(int n){
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
}

void ssc_dfs(int x, int p){
    vis[x]=1;
    parent[x]=p;
    for(auto u:rev_graph[x]){
        if(!vis[u]){
            ssc_dfs(u,p);
        }
    }
}

void SSC(int n){
    topological_sort(n);
    memset(vis, 0, sizeof(vis));
    while(!st.empty()){
        int p=st.top();
        st.pop();
        if(!vis[p]){
            timer++;
            ssc_dfs(p, timer);
        }
    }
}

void build(int node, int st, int en){
    if(st==en){  treee[node] = component_info[st]; return;}
    int mid=((en-st)/2)+st;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    treee[node]=max(treee[2*node],treee[2*node+1]);
    return;
}

void update(int node, int st, int en, int ind){
    if(st==en){
        treee[node].ff = component_info[st].ff+component_add[st];
        treee[node].ss = component_info[st].ss;
        return;
    }
    int mid=((en-st)/2)+st;
    if(st<=ind && mid>=ind){update(2*node,st, mid, ind);}
    else{update(2*node+1, mid+1, en, ind);}
    treee[node]=max(treee[2*node],treee[2*node+1]);
    return;
}


void solve(int T){
    int n,m,q;  cin>>n>>m>>q;
    for(int i=0; i<m; i++){
        int u,v;    cin>>u>>v;
        graph[u].pb(v);
        rev_graph[v].pb(u);
    }

    for(int i=1; i<=n; i++){cin>>income_arr[i];}

    SSC(n); 

    for(int i=0; i<=timer; i++){
        component_info[i]={LLMin,LLMin};
    }

    for(int i=1; i<=n; i++){
        int income=income_arr[i];
        int p=parent[i];
        if(component_info[p].ff<income){
            component_info[p]={income,1};
        }
        else if(component_info[p].ff==income){
            component_info[p].ss++;
        }
        os[p].insert({income, i});
    }

    build(1, 1, timer);

    while(q--){
        string  type; cin>>type;
        int val, x;
        if(type=="AC"){
            cin>>val>>x;
            int p=parent[x];
            component_add[p]+=val;
            update(1, 1,timer, p);
        }
        else if(type=="AS"){
            cin>>val>>x;
            int p=parent[x];
            os[p].erase({income_arr[x],x});
            income_arr[x]+=val;
            os[p].insert({income_arr[x],x});
            auto haha=*os[p].find_by_order(os[p].size()-1);
            int ok=os[p].size() - os[p].order_of_key({haha.ff,-1e18});
            component_info[p]={haha.ff, ok};
            update(1, 1,timer, p);
        }
        else{
            auto ans=treee[1];
            db(ans);
            if(ans.ff<=0){
                cout<<"0"<<endl;
            } 
            else{
                cout<<ans.ff<<" "<<ans.ss<<endl;
            }
        }

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