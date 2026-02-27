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
ll gcd(ll a, ll b){if(b==0){return a;} else{return gcd(b,a%b);}}

const int N=5e5+7;

int arr[N];
int tree[4*N];

int not_similar=0;

void build(int node, int st, int en){
    if(st==en){  tree[node] = arr[st]; return;}
    int mid=((en-st)/2)+st;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    tree[node]=gcd(tree[2*node],tree[2*node+1]);
    return;
}

void query(int node, int st, int en, int l, int r, int x){
    if(not_similar>1){return;}
    if(st>r || en<l){return;}
    else if(st>=l && en<=r){
        if(tree[node]%x){
            if(st==en){not_similar++;}
            else{
                int mid=((en-st)/2)+st;
                query(2*node, st, mid, l, r, x);
                query(2*node+1, mid+ 1, en, l, r, x);

            }
        }
    }
    else if(tree[node]%x){
        int mid=((en-st)/2)+st;
        query(2*node, st, mid, l, r, x);
        query(2*node+1, mid+ 1, en, l, r, x);
    }
}

void update(int node, int st, int en, int ind, int val){
    if(st==en){tree[node]=val;   return;}
    int mid=((en-st)/2)+st;
    if(st<=ind && mid>=ind){update(2*node,st, mid, ind, val);}
    else{update(2*node+1, mid+1, en, ind, val);}
    tree[node]=gcd(tree[2*node],tree[2*node+1]);
    return;
}


void solve(int T){
    int n;  cin>>n;
    for(int i=1; i<=n; i++){cin>>arr[i];}

    build(1, 1, n);

    int q;  cin>>q;
    while(q--){
        int type;   cin>>type;
        if(type==1){
            int l,r,x;  cin>>l>>r>>x;
            not_similar=0;
            query(1, 1, n, l, r, x);
            if(not_similar>1){NO;}
            else{YES;}
        }
        else{
            int idx,val;   cin>>idx>>val;
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