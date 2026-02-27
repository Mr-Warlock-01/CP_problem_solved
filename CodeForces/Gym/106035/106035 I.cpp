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
const int N=1e5+11;

vector<int>graph[N];
bool vis[N];
pair<int,int>head={-1,-1};
int tail=-1;
int h1_h2=1e9;
int h1_to_tail=1e9, h2_to_tail=1e9;

int head_sz=-1, body_sz=-1, tail_sz=-1;

void tail_dfs(int x, int p, int lev){
    for(int u:graph[x]){
        if(u==head.ff || u==head.ss || u==p){continue;}
        if(u==tail){tail_sz=lev; return;}
        tail_dfs(u, x, lev+1);
    }
}

void distance_cal_1(int x, int p, int lev){
    vis[x]=1;
    for(int u:graph[x]){
        if(u==p){continue;}
        if(u==tail){
            h1_to_tail=min(h1_to_tail, lev+1);  continue;
        }
        if(u==head.ss){
            h1_h2=min(h1_h2,lev+1);
            continue;
        }
        if(!vis[u]){
            distance_cal_1(u,x,lev+1);
        }
    }
}


void distance_cal_2(int x, int p, int lev){
    vis[x]=1;
    for(int u:graph[x]){
        if(u==p){continue;}
        if(u==tail){
            h2_to_tail=min(h2_to_tail, lev+1);  continue;
        }
        if(u==head.ss){
            h1_h2=min(h1_h2,lev+1);
            continue;
        }
        if(!vis[u]){
            distance_cal_2(u,x,lev+1);
        }
    }
}

void head_dfs(int x ,int p, int lev){
    for(int u:graph[x]){
        if(u==p || u==tail){continue;}
        if(u==head.ss){
            if(lev==1){continue;}
            else{head_sz=lev+1; return;}
        }
        head_dfs(u,x,lev+1);
    }
}




void solve(int T){
    int n;  cin>>n;
    for(int i=0; i<n+2; i++){
        int u,v;    cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }    

    for(int i=1; i<=n; i++){
        if(graph[i].size()==3){
            if(head.ff==-1){head.ff=i;}
            else{head.ss=i;}
        }
        else if(graph[i].size()==4){
            tail=i;
        }
    }

    tail_dfs(tail, -1, 1);
    assert(tail!=-1);
    distance_cal_1(head.ff,-1, 1);
    //memset(vis, 0, sizeof(vis));
    distance_cal_2(head.ss,-1, 1);

    head_dfs(head.ff, -1, 1);

    body_sz=h1_to_tail+h2_to_tail-1;
    //head_sz=n+3- body_sz - tail_sz;
    db(tail_sz)
    db(h1_h2)
    // db(h1_to_tail)
    // db(h2_to_tail)
    // db(body_sz)
    // db(head_sz)
    assert(h1_h2==2);

    cout<<head_sz<<" "<<body_sz<<" "<<tail_sz<<endl;
}       



//DRINK WATER
int32_t main(){
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