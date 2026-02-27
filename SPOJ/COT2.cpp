#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
using u128 = __uint128_t;
 
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
#define war()           ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL);
 
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

const int N=1e5+6;
const int log_N=20;

int arr[N];
vector<int>graph[N];
map<int,int>mp;

const int block_sz=420; 
pair<pair<int,int>,int>v[N];


int euler[2*N];
int euler_val[2*N];
int in_time[N];
int out_time[N];
int timer=0;

int LCA[log_N][N];
int level[N];

bool node_exist[N];
int cnt[N];
int ans[N];
int extra[N];
int res=0;
int n;

bool mo_sort(pair<pair<int,int>,int>&a, pair<pair<int,int>,int>&b){
    if((a.ff.ff/block_sz)!=(b.ff.ff/block_sz)){return (a.ff.ff < b.ff.ff);}
    else{
        if((a.ff.ff/block_sz) & 1){return (a.ff.ss > b.ff.ss);}
        return (a.ff.ss < b.ff.ss);
    }
}


void dfs(int node, int par, int lev){
    level[node]=lev;
    LCA[0][node]=par;
    euler[timer]=node;
    euler_val[timer]=arr[node];
    in_time[node]=(timer++);
    for(auto u:graph[node]){
        if(u!=par){
            dfs(u, node, lev+1);
        }
    }
    euler[timer]=node;
    euler_val[timer]=arr[node];
    out_time[node]=(timer++);
}

void lca_generate(){
    for(int i=1; i<log_N; i++){
        for(int j=0; j<N; j++){
            int x=LCA[i-1][j];
            if(x==-1){continue;}
            x=LCA[i-1][x];
            LCA[i][j]=x;
        }
    }
return;
}

int find_lac(int a, int b){
    if(level[a]>level[b]){swap(a,b);}
    int d=level[b]-level[a];
    while(d>0){
        int i=log2(d);
        b=LCA[i][b];
        d-=(1<<i);
    }
    if(a==b){return a;}
    for(int i=log_N-1; i>=0; i--){
        if((LCA[i][a]!=-1) && (LCA[i][a]!=LCA[i][b])){
            a=LCA[i][a];    b=LCA[i][b];
        }
    }
    return LCA[0][a];
}

void add_remove(int idx){
    int node=euler[idx];
    int val=euler_val[idx];
    node_exist[node]^=1;
    if(node_exist[node]==0){
        cnt[val]--;
        if(cnt[val]==0){res--;}
    }
    else{
        cnt[val]++;
        if(cnt[val]==1){res++;}
    }
}



void solve(int T){
    int q;
    cin>>n>>q; 
    int z=1;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        if(mp.find(arr[i])==mp.end()){mp[arr[i]]=z; z++;}
        arr[i]=mp[arr[i]];
    }

    for(int i=1; i<n; i++){
        int uu,vv;    cin>>uu>>vv;
        graph[uu].pb(vv);
        graph[vv].pb(uu);
    }

    memset(LCA, -1, sizeof(LCA));
    dfs(1,-1, 0);

    lca_generate();

    for(int i=0; i<q; i++){
        int uu,vv;    cin>>uu>>vv;
        if(in_time[uu]>in_time[vv]){swap(uu,vv);}
        int p=find_lac(uu,vv);
        if(uu==vv){
            v[i]={{in_time[uu],in_time[vv]},i};
            extra[i]=-1;
        }
        else if(p==uu){
            
            v[i]={{in_time[uu],in_time[vv]},i};
            extra[i]=-1;
        }
        else{
            v[i]={{out_time[uu],in_time[vv]},i};
            extra[i]=euler_val[in_time[p]];
        }

    }

    sort(v, v+q, mo_sort);

    int cur_l = 0;
    int cur_r = -1;

    for(int i=0; i<q; i++){
        int need_l = v[i].ff.ff;
        int need_r = v[i].ff.ss;
        int indx   = v[i].ss;

        while(cur_l>need_l){
            cur_l--;
            add_remove(cur_l);
        }
        while(cur_r<need_r){
            cur_r++;
            add_remove(cur_r);
        }
        while(cur_l<need_l){
            add_remove(cur_l);
            cur_l++;
        }
        while(cur_r>need_r){
            add_remove(cur_r);
            cur_r--;
        }


        ans[indx]=res;
        if(extra[indx]!=-1 && cnt[extra[indx]]==0){
            ans[indx]++;
        }
        
    }

    for(int i=0; i<q; i++){cout<<ans[i]<<endl;}
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