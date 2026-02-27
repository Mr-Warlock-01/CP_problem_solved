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

vector<int>graph[N];
int node_clr[N];

int euler[2*N];
int in_time[N];
int out_time[N];
int timer=0;

const int block_sz=450;
pair<pair<int,int>,int>v[N]; 
int query_k[N];

int cnt[N];
int freq[2*N];  // need block_sz^2 which is greater than 2N here
int freq_boss[block_sz];
int ans[N];
int n;


void dfs(int node, int par){
    euler[timer]=node_clr[node];
    in_time[node]=(timer++);
    for(auto u:graph[node]){
        if(u!=par){
            dfs(u, node);
        }
    }
    euler[timer]=node_clr[node];
    out_time[node]=timer++;
}


bool mo_sort(pair<pair<int,int>,int>&a, pair<pair<int,int>,int>&b){
    if((a.ff.ff/block_sz)!=(b.ff.ff/block_sz)){return (a.ff.ff < b.ff.ff);}
    else{
        if((a.ff.ff/block_sz) & 1){return (a.ff.ss > b.ff.ss);}
        return (a.ff.ss < b.ff.ss);
    }
}


void add(int idx){
    int val=euler[idx];
    if(cnt[val]!=0){
        freq[cnt[val]]--;
        freq_boss[cnt[val]/block_sz]--;
    }
    cnt[val]++;
    if(cnt[val]!=0){
        freq[cnt[val]]++;
        freq_boss[cnt[val]/block_sz]++;
    }
}

void remove(int idx){
    int val=euler[idx];
    if(cnt[val]!=0){
        freq[cnt[val]]--;
        freq_boss[cnt[val]/block_sz]--;
    }
    cnt[val]--;
    if(cnt[val]!=0){
        freq[cnt[val]]++;
        freq_boss[cnt[val]/block_sz]++;
    }
}


void solve(int T){
    cin>>n;
    int q;  cin>>q;

    for(int i=1; i<=n; i++){cin>>node_clr[i];}

    for(int i=1; i<n; i++){
        int u,v;    cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(1,-1);

    for(int i=0; i<q; i++){
        int node,k; cin>>node>>k;
        v[i]={{in_time[node],out_time[node]},i};
        query_k[i]=k;
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
            add(cur_l);
        }
        while(cur_r<need_r){
            cur_r++;
            add(cur_r);
        }
        while(cur_l<need_l){
            remove(cur_l);
            cur_l++;
        }
        while(cur_r>need_r){
            remove(cur_r);
            cur_r--;
        }

        int k=query_k[indx];
        k*=2;

        int res=0;
        int freq_cnt_indx=((k/block_sz)+1)*block_sz;
        freq_cnt_indx=min(freq_cnt_indx,2*N);
        for(int i=k; i<freq_cnt_indx ;i++){res+=freq[i];}
        for(int i=(k/block_sz)+1; i<block_sz; i++){
            res+=freq_boss[i];
        }
        ans[indx]=res;
    }
    for(int i=0; i<q; i++){
        cout<<ans[i]<<endl;
    }
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