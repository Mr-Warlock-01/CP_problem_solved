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
#define int ll

const int N=1e5+9;

int arr[N];
int sum_treee[4*N];
int mx_tree[4*N];

void build(int node, int st, int en){
    if(st==en){  
        sum_treee[node] = arr[st]; 
        mx_tree[node] = arr[st];
        return;
    }
    int mid=((en-st)/2)+st;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    sum_treee[node]=sum_treee[2*node]+sum_treee[2*node+1];
    mx_tree[node]=max(mx_tree[2*node],mx_tree[2*node+1]);
    return;
}

int query(int node, int st, int en, int l, int r){
    if(st>r || en<l){return 0;}
    else if(st>=l && en<=r){return sum_treee[node];}
    int mid=((en-st)/2)+st;
    int q1= query(2*node, st, mid, l, r);
    int q2= query(2*node+1, mid+ 1, en, l, r);
    return q1+q2;
}

void update(int node, int st, int en, int ind, int val){
    if(st==en){  
        sum_treee[node] = val; 
        mx_tree[node] = val;
        return;
    }
    int mid=((en-st)/2)+st;
    if(st<=ind && mid>=ind){update(2*node,st, mid, ind, val);}
    else{update(2*node+1, mid+1, en, ind, val);}
    sum_treee[node]=sum_treee[2*node]+sum_treee[2*node+1];
    mx_tree[node]=max(mx_tree[2*node],mx_tree[2*node+1]);
    return;
}

void update_mod(int node, int st, int en, int l, int r, int mod){
    if(st==en){  
        sum_treee[node]%=mod; 
        mx_tree[node]%=mod;
        return;
    }
    int mid=((en-st)/2)+st;
    if(mx_tree[2*node]>=mod){
        bool z=0;
        if(st<=l && l<=mid){z=1;}
        else if(st<=r && r<=mid){z=1;}
        else if(l<=st && mid<=r){z=1;}
        
        if(z==1){update_mod(2*node, st, mid, l, r, mod);}
    }
    if(mx_tree[2*node+1]>=mod){
        bool z=0;
        if((mid+1)<=l && l<=en){z=1;}
        else if((mid+1)<=r && r<=en){z=1;}
        else if(l<=(mid+1) && en<=r){z=1;}

        if(z==1){update_mod(2*node+1, mid+1, en, l, r, mod);}
    }
    sum_treee[node]=sum_treee[2*node]+sum_treee[2*node+1];
    mx_tree[node]=max(mx_tree[2*node],mx_tree[2*node+1]);
    return;
}


void solve(int T){
    int n,q;    cin>>n>>q;
    for(int i=1; i<=n; i++){cin>>arr[i];}

    build(1, 1, n);

    while(q--){
        int type;   cin>>type;
        if(type==1){
            int l,r;    cin>>l>>r;
            cout<<query(1, 1, n, l ,r)<<endl; 
        }
        else if(type==2){
            int l,r,mod;    cin>>l>>r>>mod;
            update_mod(1, 1, n, l, r, mod);
        }
        else{
            int idx, val;   cin>>idx>>val;
            update(1, 1, n, idx, val);
        }
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