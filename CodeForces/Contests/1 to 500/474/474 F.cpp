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

ll gcd(ll a, ll b){if(b==0){return a;} else{return gcd(b,a%b);}}
//#define int ll
const int N=1e5+4;

int arr[N];
pair<pair<int,int>,int>treee[4*N]; //{{max, cnt}, gcd}

void build(int node, int st, int en){
    if(st==en){
        treee[node].ff.ff=arr[st]; 
        treee[node].ff.ss=1;
        treee[node].ss=arr[st];
        return;
    }
    int mid=((en-st)/2)+st;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);

    treee[node].ff.ff=min(treee[2*node].ff.ff,treee[2*node+1].ff.ff);
    if(treee[node].ff.ff==treee[2*node].ff.ff){
        treee[node].ff.ss+=treee[2*node].ff.ss;
    }
    if(treee[node].ff.ff==treee[2*node+1].ff.ff){
        treee[node].ff.ss+=treee[2*node+1].ff.ss;
    }
    treee[node].ss=gcd(treee[2*node].ss,treee[2*node+1].ss);
    return;
}



pair<pair<int,int>,int> query(int node, int st, int en, int l, int r){
    if(st>r || en<l){return {{2e9,0},0};}
    else if(st>=l && en<=r){return treee[node];}
    int mid=((en-st)/2)+st;
    auto q1= query(2*node, st, mid, l, r);
    auto q2= query(2*node+1, mid+ 1, en, l, r);
    
    int mn=min(q1.ff.ff,q2.ff.ff);
    int cnt=0;
    if(mn==q1.ff.ff){cnt+=q1.ff.ss;}
    if(mn==q2.ff.ff){cnt+=q2.ff.ss;}
    int g=gcd(q1.ss,q2.ss);
    return {{mn,cnt},g};
}

void solve(int T){
    int n;  cin>>n;
    for(int i=1; i<=n; i++){cin>>arr[i];}
    build(1, 1, n);
    int q;  cin>>q;
    while(q--){
        int l,r;    cin>>l>>r;
        auto z=query(1, 1, n, l ,r);
        if(z.ff.ff!=z.ss){z.ff.ss=0;}
        cout<<(r-l+1-z.ff.ss)<<endl;
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