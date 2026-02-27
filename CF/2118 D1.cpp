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
const int N=503;
int pos[N];
int d[N];

int dp[N][N][2];
int n,k;


int BS(int a){
    int l=0, r=n-1;
    int idx=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(pos[mid]==a){return mid;}
        else if(pos[mid]<a){l=mid+1;}
        else{idx=mid;   r=mid-1;}
    }
    return idx;
}

int xxx(int idx, int time, int dir){
    if(idx==(n-1) && time!=d[idx] && dir==0){return 1;}
    if(idx==0 && time!=d[idx] && dir==1){return 1;}
    if(dp[idx][time][dir]!=-1){return dp[idx][time][dir];}

    dp[idx][time][dir]=0;
    int ans=0;

    if(dir==0){
        if(d[idx]!=time){ans=xxx(idx+1, (time+pos[idx+1]-pos[idx])%k, dir);}
        else{
            ans=xxx(idx-1, (time+pos[idx]-pos[idx-1])%k, 1);
        }
    }
    else{
        if(d[idx]!=time){ans=xxx(idx-1, (time+pos[idx]-pos[idx-1])%k, dir);}
        else{
            ans=xxx(idx+1, (time+pos[idx+1]-pos[idx])%k, 0);
        }
    }
    return dp[idx][time][dir]=ans;
}


void solve(int T){
    cin>>n>>k;
    for(int i=0; i<n; i++){cin>>pos[i];}
    for(int i=0; i<n; i++){cin>>d[i];}
    int q;  cin>>q;
    memset(dp, -1, sizeof(dp));
    while(q--){
        int a;  cin>>a;
        int p=BS(a);
        if(p==-1){YES; continue;}
        int time=(pos[p]-a)%k;
        int ans=xxx(p,time,0);
        if(ans){YES;}
        else{NO;}
    }
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