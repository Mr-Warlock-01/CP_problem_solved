#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
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

#define int ll
const int N=2e5+7;

gp_hash_table<int, int,custom_hash>mp;
int arr[N];
int pre_sum[N];
vector<int>graph[N];
int treee[4*N];
int n;

void clr(int k){
    for(int i=0; i<=k; i++){
        graph[i].clear();
    }
    mp.clear();
}


void build(int node, int st, int en){
    if(st==en){  treee[node] = arr[st]; return;}
    int mid=((en-st)/2)+st;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    treee[node]=max(treee[2*node],treee[2*node+1]);
    return;
}

int query(int node, int st, int en, int l, int r){
    if(st>r || en<l){return LLMin;}
    else if(st>=l && en<=r){return treee[node];}
    int mid=((en-st)/2)+st;
    int q1= query(2*node, st, mid, l, r);
    int q2= query(2*node+1, mid+ 1, en, l, r);
    return max(q1,q2);
}


int left_side(int node, int val, int mx){
    int ans=-1;
    int l=0, r=graph[node].size()-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(graph[node][mid]<=val){l=mid+1; continue;}
        int q=query(1,1,n, val+1, graph[node][mid]);
        if(q<mx){l=mid+1;}
        else if(q>mx){r=mid-1;}
        else{
            ans=mid;
            r=mid-1;
        }
    }
    return ans;
}


int right_side(int node, int val, int mx){
    int ans=-1;
    int l=0, r=graph[node].size()-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(graph[node][mid]<=val){l=mid+1; continue;}
        int q=query(1,1,n, val+1, graph[node][mid]);
        if(q<mx){l=mid+1;}
        else if(q>mx){r=mid-1;}
        else{
            ans=mid;
            l=mid+1;
        }
    }
    return ans;
}

void solve(int T){
    int s,m; cin>>n>>s>>m;
    for(int i=1; i<=n; i++){cin>>arr[i];}
    clr(n+3);
    for(int i=1; i<=n; i++){pre_sum[i]=pre_sum[i-1]+arr[i];}
    build(1,1,n);
    
    int z=1;
    for(int i=1; i<=n; i++){
        if(mp[pre_sum[i]]==0){
            mp[pre_sum[i]]=z; z++;
        }
        graph[mp[pre_sum[i]]].pb(i);
    }

    int ans=0;
    for(int i=0; i<n; i++){
        int need=pre_sum[i]+s;
        int node=mp[need];
        int l=left_side(node, i, m);
        if(l!=-1){
            int r=right_side(node, i, m);
            ans+=(r-l+1);
        }
    }
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