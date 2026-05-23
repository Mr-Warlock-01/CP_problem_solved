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
// *.find_by_order(x)
//substr
//cin.ignore();
//get<idx>(z) //tuple
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

const int N=1e6+9;
int arr[N];
int dp[N];
vector<int>divisor[N];
vector<int>ZZZ[32];

void factor_cal(){
    for(int i=2; i*i<N; i++){
        for(int j=i*i; j<N; j+=i){
            divisor[j].pb(i);
            if((j/i)!=i){
                divisor[j].pb(j/i);
            }
        }
    }
}


int grandy(int x){
    if(x==1){return 0;}
    if(~dp[x]){return dp[x];}
    int ans=0;
    vector<bool>v(22);
    for(auto u:divisor[x]){
        int z=grandy(x/u);
        if(z<22){v[z]=1;}
    }
    for(int i=1; i<22; i++){
        if(!v[i]){ans=i; break;}
    }
    return dp[x]=ans;
}

int BS(int idx, int x){
    int ans=-1;
    int l=0, r=ZZZ[idx].size()-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(ZZZ[idx][mid]<x){
            ans=mid; l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return ans;
}

void clr(){
    for(int i=0; i<32; i++){
        ZZZ[i].clear();
    }
}

void solve(int T){
    clr();
    int n,q;  cin>>n>>q;
    for(int i=1; i<=n; i++){
        int a;  cin>>a;
        arr[i]=arr[i-1]^grandy(a);
    }
    for(int i=0; i<=n; i++){
        ZZZ[arr[i]].pb(i);
    }
    while(q--){
        int l,r;    cin>>l>>r;
        ll cnt=r-l+1;
        ll total=(cnt*(cnt+1))/2;
        ll S_win=0;
        for(int i=0; i<32; i++){
            ll CNT_s=BS(i, r+1)-BS(i, l-1);
            S_win+=((CNT_s)*(CNT_s-1))/2;
        }
        ll F_win=total - S_win;
        if(F_win==S_win){
            cout<<"Draw"<<endl;
        }
        else if(F_win>S_win){
            cout<<"First"<<endl;
        }
        else{
            cout<<"Second"<<endl;
        }
    }


}   


    

int32_t main(){             //DRINK WATER
    war();
    //read();   write();
    /////////////////////////////////////
    memset(dp, -1, sizeof(dp));
    factor_cal();
    /////////////////////////////////////
    int tc=1;
    cin>>tc;
    for(int T=1; T<=tc; T++){
        solve(T);
    }
return 0;
} 

/*

     /\_/\
    (= ._.)
    / >  \> Mr_Warlock
   /      \

*/  