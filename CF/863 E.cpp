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

#define int ll

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


const int N=1e6;

int treee[4*N];
int lazy[4*N];
gp_hash_table<int, int,custom_hash>mp;

int lazy_query(int node, int st, int en, int l, int r){
    if(lazy[node]!=0){
        treee[node]+=lazy[node];
        if(st!=en){ lazy[2*node]+=lazy[node];   lazy[2*node+1]+=lazy[node];}
        lazy[node]=0;
    }
    if(st>r || en<l){return LLMax;}
    else if(st>=l && en<=r){return treee[node];}
    int mid=((en-st)/2)+st;
    int q1= lazy_query(2*node, st, mid, l, r);
    int q2= lazy_query(2*node+1, mid+ 1, en, l, r);
    return min(q1,q2);
}

void lazy_update(int node, int st, int en, int l, int r, int val){
    if(lazy[node]!=0){
        treee[node]+=lazy[node];
        if(st!=en){ lazy[2*node]+=lazy[node];   lazy[2*node+1]+=lazy[node];}
        lazy[node]=0;
    }
    if(st>r || en<l){return;}
    else if(st>=l && en<=r){
        treee[node]+=val;
        if(st!=en){ lazy[2*node]+=val;   lazy[2*node+1]+=val;}
        return;
    }
    int mid=((en-st)/2)+st;
    lazy_update(2*node, st, mid, l, r, val);
    lazy_update(2*node+1, mid+1, en, l, r, val);
    treee[node]=min(treee[2*node], treee[2*node+1]);
    return;
}



void solve(int T){
    int n;      cin>>n;
    pair<int,int>v[n];
    vector<int>z;

    for(int i=0; i<n; i++){
        cin>>v[i].ff>>v[i].ss;
    }

    for(int i=0; i<n; i++){
        z.pb(v[i].ff); 
        z.pb(v[i].ss);  
    }

    sort(all(z));

    mp[z[0]]=1;
    int x=1;
    for(int i=1; i<z.size(); i++){
        if(z[i]==z[i-1]){continue;}
        if(z[i]!=z[i-1]+1){x++;}
        x++;
        mp[z[i]]=x;
    }

    for(int i=0; i<n; i++){
        v[i].ff=mp[v[i].ff];
        v[i].ss=mp[v[i].ss];
        lazy_update(1,1,N, v[i].ff, v[i].ss, 1);
    }
    for(int i=0; i<n; i++){
        int z=lazy_query(1, 1, N, v[i].ff, v[i].ss);
        if(z>1){cout<<i+1; return;}
    }

    IMP;
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