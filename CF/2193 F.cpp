#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x){
        x+=0x9e3779b97f4a7c15;  x=(x^(x>>30))*0xbf58476d1ce4e5b9;   x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    size_t operator()(uint64_t x) const{
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
    size_t operator()(pair<uint64_t, uint64_t>x) const { 
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count(); 
        return splitmix64(x.first+FIXED_RANDOM)^(splitmix64(x.second+FIXED_RANDOM)>>1); 
    }
};


#define int ll

const int N=3e5+7;

vector<pair<int,int>>YY;  //mn,mx
vector<int>XX;

int dp[N][2];

void clr(int n){
    YY.clear();
    XX.clear();
    for(int i=0; i<n; i++){
        dp[i][0]=-1;
        dp[i][1]=-1;
    }
}

int absolute(int x){
    if(x<0){
        x=-1*x;
    }
    return x;
}

int fun(int pos, int last){
    if((pos+1)>=XX.size()){return 0;}
    if(~dp[pos][last]){return dp[pos][last];}
    int ans=LLMax;

    if(last==0){
        int ans_1=fun(pos+1, 0) + absolute(XX[pos+1]-XX[pos])+ absolute(YY[pos].ss-YY[pos].ff)+absolute(YY[pos].ss-YY[pos+1].ff);
        int ans_2=fun(pos+1, 1) + absolute(XX[pos+1]-XX[pos])+ absolute(YY[pos].ss-YY[pos].ff)+absolute(YY[pos].ss-YY[pos+1].ss);
        ans=min({ans,ans_1,ans_2});
    }
    else{
        int ans_1=fun(pos+1, 0) + absolute(XX[pos+1]-XX[pos])+ absolute(YY[pos].ss-YY[pos].ff)+absolute(YY[pos].ff-YY[pos+1].ff);
        int ans_2=fun(pos+1, 1) + absolute(XX[pos+1]-XX[pos])+ absolute(YY[pos].ss-YY[pos].ff)+absolute(YY[pos].ff-YY[pos+1].ss);
        ans=min({ans,ans_1,ans_2});
    }
    return dp[pos][last]=ans;
}



void solve(int T){
    int n, sx,sy, dx,dy;    cin>>n>>sx>>sy>>dx>>dy;

    clr(n+4);

    vector<pair<int,int>>v(n);
    for(int i=0; i<n; i++){cin>>v[i].ff;}
    for(int i=0; i<n; i++){cin>>v[i].ss;}
    sort(all(v));
    // gp_hash_table<int, int,custom_hash>mp;

    int mx=sy;
    int mn=sy;
    int last=sx;
    for(int i=0; i<n; i++){
        if(last==v[i].ff){
            mx=max(mx, v[i].ss);
            mn=min(mn, v[i].ss);
        }
        else{
            XX.pb(last);
            YY.pb({mn,mx});
            last=v[i].ff;
            mx=v[i].ss;
            mn=v[i].ss;
        }
    }
    XX.pb(last);
    YY.pb({mn,mx});
    
    XX.pb(dx);
    YY.pb({dy,dy});
    
    int ans=fun(0,0);
    cout<<ans<<endl;
} 



    

int32_t main(){             //DRINK WATER
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

/*

     /\_/\
    (= ._.)
    / >  \> Mr_Warlock
   /      \

*/  