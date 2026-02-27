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

#define int ll
const int B1= 137;
const int B2= 277;
const int M1= 14457881;
const int M2= 11457857;
const int N=1e5+7;



int b1_q[N],b2_q[N];
int pre_b1[N],pre_b2[N];

struct NODE{
    int hash_1, hash_2;
    int sz;
}tree[4*N];
int lazy[4*N];
string s;


void build(int node, int st, int en){
    if(st==en){
        tree[node].hash_1=s[st]-45;
        tree[node].hash_2=s[st]-45;
        tree[node].sz=1;
        lazy[node]=-1;
        return;
    }
    int mid=(st+en)/2;
    int L=2*node; int R=L+1;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    tree[node].hash_1 = (tree[L].hash_1+((b1_q[tree[L].sz]*tree[R].hash_1)%M1))%M1;
    tree[node].hash_2 = (tree[L].hash_2+((b2_q[tree[L].sz]*tree[R].hash_2)%M2))%M2;
    tree[node].sz=tree[L].sz+tree[R].sz;
    lazy[node]=-1;
    return;
}

void relax(int node, int st, int en){
    if(lazy[node]==-1){return;}
    int L=2*node; int R=L+1;
    tree[node].hash_1=(pre_b1[en-st]*lazy[node])%M1;
    tree[node].hash_2=(pre_b2[en-st]*lazy[node])%M2;
    if(st!=en){
        lazy[L]=lazy[node];
        lazy[R]=lazy[node];
    }
    lazy[node]=-1;
}

void update(int node, int st, int en, int l, int r, int val){
    relax(node, st, en);
    if(st>r || en<l){return;}
    else if(st>=l && en<=r){
        tree[node].hash_1=(pre_b1[en-st]*val)%M1;
        tree[node].hash_2=(pre_b2[en-st]*val)%M2;
        if(st!=en){
            lazy[2*node]=val;
            lazy[2*node+1]=val;
        }
        return;
    }
    int mid=(st+en)/2;
    int L=2*node; int R=L+1;
    update(2*node, st, mid, l, r, val);
    update(2*node+1, mid+1, en, l, r, val);
    tree[node].hash_1 = (tree[L].hash_1+((b1_q[tree[L].sz]*tree[R].hash_1)%M1))%M1;
    tree[node].hash_2 = (tree[L].hash_2+((b2_q[tree[L].sz]*tree[R].hash_2)%M2))%M2;
    tree[node].sz=tree[L].sz+tree[R].sz;
    return;
}

tuple<int,int,int>query(int node, int st, int en, int l, int r){
    relax(node, st, en);
    if(st>r || en<l){return {0,0,0};}
    else if(st>=l && en<=r){
        return {tree[node].hash_1,tree[node].hash_2, tree[node].sz};
    }
    int mid=(st+en)/2;
    auto [l_h1, l_h2, l_sz]= query(2*node, st, mid, l, r);
    auto [r_h1, r_h2, r_sz]= query(2*node+1, mid+ 1, en, l, r);

    int h1=(l_h1+((b1_q[l_sz]*r_h1)%M1))%M1;
    int h2=(l_h2+((b2_q[l_sz]*r_h2)%M2))%M2;
    int s_z=l_sz+r_sz;
    return {h1,h2,s_z};
}

void pre_cal(int n){
    b1_q[0]=b2_q[0]=1;
    pre_b1[0]=pre_b2[0]=1;
    for(int i=1; i<n; i++){
        b1_q[i]= (b1_q[i-1]*B1)%M1;
        b2_q[i]= (b2_q[i-1]*B2)%M2;

        pre_b1[i]=(pre_b1[i-1]+b1_q[i])%M1;
        pre_b2[i]=(pre_b2[i-1]+b2_q[i])%M2;
    }
}

void solve(int T){
    int n,m,k;  cin>>n>>m>>k;
    cin>>s;
    int q=m+k;
    s="#"+s;
    pre_cal(n+4);
    build(1,1,n);

    while(q--){
        int type;   cin>>type;
        int l,r;    cin>>l>>r;
        if(type==1){
            char c;  cin>>c;
            update(1, 1, n, l, r, c-45);
        }
        else{
            int d;  cin>>d;
            auto h1=query(1, 1, n, l, r-d);
            auto h2=query(1, 1, n, l+d, r);
            if(h1==h2){YES;}
            else{NO;}
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