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
const int N=3007;

vector<int>graph_up[N];
vector<int>graph_down[N];
int sz_up[N],sz_down[N];
bool vis_up[N],vis_down[N];

void clr(int n){
    for(int i=0; i<n; i++){
        graph_up[i].clear();
        graph_down[i].clear();
        sz_up[i]=sz_down[i]=0;
        vis_up[i]=vis_down[i]=0;
    }
}


bool check_intersect(tuple<int,int,int,int>&v1, tuple<int,int,int,int>&v2){
    auto [a1,b1,c1,i]=v1;
    auto [a2,b2,c2,j]=v2;
    int A=a1-a2;
    int B=b1-b2;
    int C=c1-c2;

    if(A==0 && B==0){
        return (C==0);
    }
    int D=(B*B)-(4*A*C);
    return (D>=0);
}

bool cmd(tuple<int,int,int,int>&v1, tuple<int,int,int,int>&v2){
    auto [a1,b1,c1,i]=v1;
    auto [a2,b2,c2,j]=v2;
    if(a1>0 && a2<0){return 1;}
    if(a2>0 && a1<0){return 0;}
    double y1=(4*a1*c1-(b1*b1))/(4*a1*1.0);
    double y2=(4*a2*c2-(b2*b2))/(4*a2*1.0);
    return (y1>y2);
}

void dfs_up(int x){
    int sz=1;
    vis_up[x]=1;
    for(int u: graph_up[x]){
        if(!vis_up[u]){
            dfs_up(u);
        }
        sz=max(sz,sz_up[u]+1);    
    }
    sz_up[x]=sz;
}

void dfs_down(int x){
    int sz=1;
    vis_down[x]=1;
    for(int u: graph_down[x]){
        if(!vis_down[u]){
            dfs_down(u);
        }
        sz=max(sz,sz_down[u]+1);    
    }
    sz_down[x]=sz;
}

void solve(int T){
    int n;  cin>>n;
    clr(n+4);
    vector<tuple<int,int,int,int>>v;

    for(int i=0; i<n; i++){
        int a,b,c;  cin>>a>>b>>c;
        v.pb({a,b,c,i+1});
    }

    sort(all(v),cmd);

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(!check_intersect(v[i],v[j])){
                graph_up[get<3>(v[j])].pb(get<3>(v[i]));
                graph_down[get<3>(v[i])].pb(get<3>(v[j]));
            }
        }
    }

    for(int i=1; i<=n; i++){
        if(!vis_up[i]){dfs_up(i);}
        if(!vis_down[i]){dfs_down(i);}
    }
    for(int i=1; i<=n; i++){
        cout<<sz_up[i]+sz_down[i]-1<<" ";
    }cout<<endl;
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