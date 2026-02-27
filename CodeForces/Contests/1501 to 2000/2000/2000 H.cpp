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
 
//#define int ll

const int N=4e6+3;

int arr[N];

int tree[4*N];
int lazy[4*N];

set<int>s;


void build(int node, int st, int en){
    lazy[node]=-1;
    if(st==en){tree[node]=st;return;}
    int mid=((en-st)/2)+st;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    tree[node]=en;
    return;
}

void relax(int node, int st, int en){
    if(lazy[node]!=-1){
        tree[node]=en-lazy[node];
        if(st!=en){ lazy[2*node]=lazy[node];   lazy[2*node+1]=lazy[node];}
    }
    lazy[node]=-1;
}

int lazy_query(int node, int st, int en, int val){
    if(st==en){return st;}
    int mid=((en-st)/2)+st;
    relax(2*node, st, mid);
    relax(2*node+1, mid+ 1, en);
    if(tree[2*node]>=val){
        return lazy_query(2*node, st, mid, val);
    }
    return lazy_query(2*node+1, mid+ 1, en, val);
}

void lazy_update(int node, int st, int en, int l, int r, int val){
    relax(node, st, en);
    if(st>r || en<l){return;}
    else if(st>=l && en<=r){
        tree[node]=en-val;
        if(st!=en){ lazy[2*node]=val;   lazy[2*node+1]=val;}
        return;
    }
    int mid=((en-st)/2)+st;
    lazy_update(2*node, st, mid, l, r, val);
    lazy_update(2*node+1, mid+1, en, l, r, val);
    tree[node]=max(tree[2*node],tree[2*node+1]);
    return;
}




void solve(int T){
    int n;  cin>>n;
    s.insert(0);
    s.insert(N);
    
    for(int i=0; i<n; i++){
        int a;  cin>>a;
        auto r=s.upper_bound(a);
        s.insert(a);
        lazy_update(1, 1, N, a, *r-1, a);
    }

    int q;  cin>>q;
    while(q--){
        char c; int x;  cin>>c;
        cin>>x;
        if(c=='+'){
            auto r=s.upper_bound(x);
            s.insert(x);
            lazy_update(1, 1, N, x, *r-1, x);
        }
        else if(c=='-'){
            auto l=s.lower_bound(x); l--; 
            auto r=s.upper_bound(x);
            s.erase(x);
            lazy_update(1, 1, N, *l, *r-1, *l);
        }
        else{
            relax(1, 1, N);
            int z=lazy_query(1 ,1, N, x);
            cout<<z-x+1<<" ";
        }
    }
    cout<<endl;

    stack<int>st;
    for(auto z:s){
        if(z==0 || z==N){}
        else{
            st.push(z);
        }
    }
    while(!st.empty()){
        int x=st.top(); st.pop();
        auto l=s.lower_bound(x); l--; 
        auto r=s.upper_bound(x);
        s.erase(x);
        lazy_update(1, 1, N, *l, *r-1, *l);
    }
    s.clear();;
}
  
 
 
 
//DRINK WATER
int32_t main(){
    war();
    //read();   write();
    /////////////////////////////////////
 
    /////////////////////////////////////
    int tc=1;
    cin>>tc;
    build(1, 1, N);
    for(int T=1; T<=tc; T++){
        solve(T);
    }
return 0;
}