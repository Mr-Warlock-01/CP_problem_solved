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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x){
        x+=0x9e3779b97f4a7c15;  x=(x^(x>>30))*0xbf58476d1ce4e5b9;   x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    size_t operator()(uint64_t x) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};



const int N=2e5+6;
const int block_sz=3400; 
const int log_N=20;

int arr[N];
vector<int>graph[N];
map<int,int>mp;

int euler[N];
int in_time[N];
int out_time[N];
int euler_timer=0;

int LCA[log_N][N];
int level[N];

bool node_exist[N];
int cnt[N];
int ans[N];
int extra[N]; //parent distinct need to handle if ex[i]!=-1;
int res=0;
int n;
int L=0,R=-1;



struct query{
    int l,r,t,idx;
    query(){}
    query(int l, int r, int t, int idx):l(l),r(r),t(t),idx(idx){}
    bool operator<(const query &q)const{
        int curl=l/block_sz, otherl = q.l/block_sz;
        int curr=r/block_sz, otherr = q.r/block_sz;
        if(curl^otherl){return curl<otherl;}
        if(curr^otherr){return curr<otherr;}
        return t<q.t;
    }
}queries[N];

struct update{
    int ind;
    int prev,nxt; 
    update(){}
    update(int ind,int prev,int nxt):ind(ind),prev(prev),nxt(nxt){}
}updates[N];

void dfs(int node, int par, int lev){
    level[node]=lev;
    LCA[0][node]=par;
    euler[euler_timer]=node;
    in_time[node]=(euler_timer++);
    for(auto u:graph[node]){
        if(u!=par){
            dfs(u, node, lev+1);
        }
    }
    euler[euler_timer]=node; 
    out_time[node]=(euler_timer++);
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

inline int find_lac(int a, int b){
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

inline void add_remove(int idx){
    int node=euler[idx];
    int val=arr[node];
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

inline void adjust(int node, int val){
    int idx_1=in_time[node];
    int idx_2=out_time[node];

    if((L<=idx_1) && (idx_1<=R)){
        add_remove(idx_1);
    }
    if((L<=idx_2) && (idx_2<=R)){
        add_remove(idx_2);
    }

    arr[node]=val;

    if((L<=idx_1) && (idx_1<=R)){
        add_remove(idx_1);
    }
    if((L<=idx_2) && (idx_2<=R)){
        add_remove(idx_2);
    }
}


void solve(int T){
    int q;
    cin>>n>>q; 
    int z=1;
    for(int i=1; i<=n; i++){
        cin>>arr[i];
        if(mp[arr[i]]==0){mp[arr[i]]=z; z++;}
        arr[i]=mp[arr[i]];
    }

    for(int i=1; i<n; i++){
        int u,v;    cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    memset(LCA, -1, sizeof(LCA));
    dfs(1,-1, 0);
    lca_generate();

    int updateCnt=0;
    int queryCnt=0;

    for(int i=0;i<q;i++){
        int type;
        cin>>type;
        if(type==1){
            int u,v; cin>>u>>v;
            if(in_time[u]>in_time[v]){swap(u,v);}
            int p=find_lac(u,v);
            if(u==p){
                queries[queryCnt]=query(in_time[u],in_time[v],updateCnt,queryCnt);
                extra[queryCnt]=-1;
            }
            else{
                queries[queryCnt]=query(out_time[u],in_time[v],updateCnt,queryCnt);
                extra[queryCnt]=arr[p];
            }
            queryCnt++;
        }
        else{//update
            int node,val;    cin>>node>>val;
            if(mp[val]==0){mp[val]=z; z++;}
            val=mp[val];
            updates[updateCnt++]=update(node,arr[node],val);
            arr[node]=val;
        }
    }
    if(queryCnt==0){return;}

    sort(queries,queries+queryCnt);
    for(int i=0;i<queryCnt;i++){
        while(L>queries[i].l){add_remove(--L);}
        while(R<queries[i].r){add_remove(++R);}
        while(L<queries[i].l){add_remove(L++);}
        while(R>queries[i].r){add_remove(R--);}

        while(updateCnt<queries[i].t){
            adjust(updates[updateCnt].ind,updates[updateCnt].nxt);
            updateCnt++;
        }
        while(updateCnt>queries[i].t){
            updateCnt--;
            adjust(updates[updateCnt].ind,updates[updateCnt].prev);
        }
        ans[queries[i].idx]=res;
        if(extra[queries[i].idx]!=-1 && cnt[extra[queries[i].idx]]==0){
            ans[queries[i].idx]++;
        }
    }

    for(int i=0; i<queryCnt; i++){cout<<ans[i]<<endl;}
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