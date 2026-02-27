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

const int N=3e5+7;

struct max_tree{
    int tree[4*N];

    void build(int arr[],int node, int st, int en){
        if(st==en){
            tree[node]=arr[st]; 
            return;
        }
        int mid=((en-st)/2)+st;
        build(arr, 2*node, st, mid);
        build(arr, 2*node+1, mid+1, en);
        tree[node]=max(tree[2*node],tree[2*node+1]);
        return;
    }

    int query(int node, int st, int en, int l, int r){
        if(st>r || en<l){return 0;}
        else if(st>=l && en<=r){return tree[node];}
        int mid=((en-st)/2)+st;
        int q1= query(2*node, st, mid, l, r);
        int q2= query(2*node+1, mid+ 1, en, l, r);
        return max(q1,q2);
    }
}pre_max,suf_max;



void solve(int T){
    int n;  cin>>n;
    int arr[n+1];
    for(int i=1; i<=n; i++){cin>>arr[i];}

    if(n==1){cout<<arr[n]<<endl; return;}
    
    int pre[n+1],suf[n+1];
    
    for(int i=1; i<=n; i++){
        pre[i]=arr[i]+i-1;
        suf[i]=arr[i]+n-i;
    }

    pre_max.build(pre,1,1,n);
    suf_max.build(suf,1,1,n);

    int ans=LLMax;

    for(int i=2; i<n; i++){
        int z1=suf_max.query(1, 1, n, 1, i-1);
        int z2=pre_max.query(1, 1, n, i+1, n);
        ans=min(ans, max({arr[i],z1,z2}));
    }

    ans=min(ans, max(arr[1],pre_max.query(1, 1, n, 2, n)));
    ans=min(ans, max(arr[n],suf_max.query(1, 1, n, 1, n-1)));
    cout<<ans<<endl;
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