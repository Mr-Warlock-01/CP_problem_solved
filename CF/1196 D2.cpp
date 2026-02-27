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

const int N=2e5+7;


int pre[3][N];

int check(int idx, int l, int r){
    l=l-1;
    int val_l=0;
    if(l>=0){val_l=pre[idx][l];}
    int val_r=pre[idx][r];
    return val_r-val_l;
}

void solve(int T){
    int n,k;    cin>>n>>k;
    string s;   cin>>s;

    

    for(int i=0; i<n; i++){//RGB
             if(i%3==0 && s[i]=='R'){pre[0][i]=0;}
        else if(i%3==1 && s[i]=='G'){pre[0][i]=0;}
        else if(i%3==2 && s[i]=='B'){pre[0][i]=0;}
        else{pre[0][i]=1;}
    }
    for(int i=0; i<n; i++){//GBR
             if(i%3==0 && s[i]=='G'){pre[1][i]=0;}
        else if(i%3==1 && s[i]=='B'){pre[1][i]=0;}
        else if(i%3==2 && s[i]=='R'){pre[1][i]=0;}
        else{pre[1][i]=1;}
    }
    for(int i=0; i<n; i++){//BRG
             if(i%3==0 && s[i]=='B'){pre[2][i]=0;}
        else if(i%3==1 && s[i]=='R'){pre[2][i]=0;}
        else if(i%3==2 && s[i]=='G'){pre[2][i]=0;}
        else{pre[2][i]=1;}
    }

    for(int i=1; i<n; i++){
        pre[0][i]+=pre[0][i-1];
        pre[1][i]+=pre[1][i-1];
        pre[2][i]+=pre[2][i-1];
    }

    int ans=n;

    for(int i=k-1; i<n; i++){
        ans=min(ans, check(0, i-k+1, i));
        ans=min(ans, check(1, i-k+1, i));
        ans=min(ans, check(2, i-k+1, i));
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